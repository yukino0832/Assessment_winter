#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main()
{
    cv::Mat srcMat = cv::imread("../huixingzhen.jpg", 0);
    cv::Mat resMat;
    cv::Mat resover;
    cv::Mat sign;
    cv::Mat state;
    cv::Mat center;
    cv::threshold(srcMat, resMat, 100, 255, cv::THRESH_OTSU); // 大津法
    cv::bitwise_not(resMat, resover);
    cv::imshow("resover", resover);
    cv::connectedComponentsWithStats(resover, sign, state, center, 8, CV_32S); // 连通域标记
    int line = 0;
    int num = 0;
    int i;
    line = state.rows;
    int fontFace = cv::FONT_HERSHEY_SIMPLEX;
    cv::Point org(50, 100);
    double fontScale = 1;
    cv::Scalar color(0, 0, 255);
    int thickness = 2;
    for (i = 0; i < state.rows; i++)
    {
        if (state.at<int>(i, 4) >= 2000 && state.at<int>(i, 4) <= 8000)
        {
            num = num + 1;
            cv::Rect rect;
            rect.x = state.at<int>(i, 0);
            rect.y = state.at<int>(i, 1);
            rect.width = state.at<int>(i, 2);
            rect.height = state.at<int>(i, 3);
            cv::Point org(rect.x , rect.y+20 );
            cv::rectangle(srcMat, rect, CV_RGB(0, 10, 0), 1, 8, 0);
            cv::putText(srcMat, std::to_string(num),org, fontFace, fontScale, color, thickness, 8);
        }
    }
    std::cout << num << std::endl;
    cv::imshow("resover", srcMat);
    cv::waitKey(0);
}
