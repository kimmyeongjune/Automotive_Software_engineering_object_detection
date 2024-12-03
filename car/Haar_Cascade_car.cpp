#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 비디오 파일 읽기
    VideoCapture cap("video1.avi");  // 비디오 경로 확인 필요

    // 비디오 파일이 제대로 열렸는지 확인
    if (!cap.isOpened()) {
        cerr << "Error: Could not open or find the video!" << endl;
        return -1;
    }

    // 비디오 파일의 프레임 너비와 높이, FPS 가져오기
    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fps = static_cast<int>(cap.get(CAP_PROP_FPS));

    // 비디오 파일 저장을 위한 VideoWriter 객체 생성
    VideoWriter outputVideo("output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(frame_width, frame_height));

    // VideoWriter 객체가 제대로 열렸는지 확인
    if (!outputVideo.isOpened()) {
        cerr << "Error: Could not open the output video for write!" << endl;
        return -1;
    }

    // 차를 찾기 위한 변수
    std::vector<Rect> carRect;
    CascadeClassifier car;

    // 차량 cascade 파일 로드
    if (!car.load("cars.xml")) {
        cerr << "Error: Could not load car cascade!" << endl;
        return -1;
    }

    Mat frame, grayFrame;
    while (true) {
        // 비디오의 다음 프레임 읽기
        cap >> frame;

        // 프레임이 비어있으면 비디오의 끝에 도달한 것임
        if (frame.empty()) {
            break;
        }

        // 그레이스케일 이미지로 변환
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

        // 차 탐지
        car.detectMultiScale(grayFrame, carRect, 1.1, 3, 0, Size(50, 50));

        // 차량 영역 그리기
        for (int i = 0; i < carRect.size(); i++) {
            rectangle(frame, carRect[i], Scalar(50, 0, 200), 2);  // 차량 사각형 그리기
        }

        // 결과 프레임 화면에 표시
        imshow("Car Detection", frame);

        // 결과 프레임을 비디오 파일에 저장
        outputVideo.write(frame);

        // 'q' 키를 누르면 종료
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // 비디오 캡처 객체 해제
    cap.release();

    // 비디오 작성 객체 해제
    outputVideo.release();

    // 모든 창 닫기
    destroyAllWindows();

    return 0;
}