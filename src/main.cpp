#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // OpenCV를 이용한 이미지 로드
    cv::Mat image = cv::imread("image.jpg");

    if (image.empty()) {
        std::cout << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // 이미지를 윈도우에 표시
    cv::imshow("Loaded Image", image);
    cv::waitKey(0);

    return 0;
}
