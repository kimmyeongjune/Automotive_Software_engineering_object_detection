#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 이미지 파일 읽기
    Mat img = imread("image.jpg");  // 이미지 경로 확인 필요

    // 이미지가 제대로 읽혔는지 확인
    if (img.empty()) {
        cerr << "Error: Could not open or find the image!" << endl;
        return -1;
    }

    // 그레이스케일 이미지로 변환
    Mat grayImg;
    cvtColor(img, grayImg, COLOR_BGR2GRAY);

    // 얼굴과 눈을 찾기 위한 변수
    std::vector<Rect> faceRect, eyeRect;
    CascadeClassifier face, eye;

    // 얼굴과 눈 cascade 파일 로드
    if (!face.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error: Could not load face cascade!" << endl;
        return -1;
    }

    if (!eye.load("haarcascade_eye.xml")) {
        cerr << "Error: Could not load eye cascade!" << endl;
        return -1;
    }

    // 얼굴 탐지
    face.detectMultiScale(grayImg, faceRect, 1.05, 10, 0, Size(50, 50));

    // 눈 탐지
    eye.detectMultiScale(grayImg, eyeRect, 1.05, 5, 0, Size(15, 15));

    // 얼굴 영역 그리기
    for (int i = 0; i < faceRect.size(); i++) {
        rectangle(img, faceRect[i], Scalar(50, 0, 200), 2);  // 얼굴 사각형 그리기
    }

    // 눈 영역 그리기
    for (int i = 0; i < eyeRect.size(); i++) {
        rectangle(img, eyeRect[i], Scalar(200, 0, 50), 2);  // 눈 사각형 그리기
    }

    // 결과 이미지 화면에 표시
    imshow("img_detect", img);
    waitKey(0);  // 사용자가 키를 누를 때까지 기다림
    return 0;
}
