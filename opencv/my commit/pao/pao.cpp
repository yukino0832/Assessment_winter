#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    std::string path = "../pao.jpg";
    cv::Mat img;
    img = cv::imread(path);
    // cv::resize(img, img, cv::Size(), 2, 2);
    cv::cvtColor(img, img,cv::COLOR_BGR2GRAY);
    cv::threshold(img, img,0,255,cv::THRESH_OTSU);

    cv::Mat imgDilation;
    cv::Mat imgErode;

    cv::Mat kernal = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(23,23));
    //cv::Mat kernal = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(23, 23));
    //cv::Mat kernal = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(19, 19));

    //cv::erode(img, imgErode, kernal);
    //cv::dilate(imgErode, imgDilation, kernal);     //开运算，先腐蚀后膨胀

    //cv::dilate(img, imgDilation, kernal);
    //cv::erode(imgDilation, imgErode, kernal);      //闭运算，先膨胀后腐蚀
    cv::morphologyEx(img, imgErode, cv::MORPH_CLOSE, kernal, cv::Point(-1, -1));

    cv::imshow("Original", img);
    // cv::imshow("Gray", imgGray);
    // cv::imshow("Blur", imgBlur);
    // cv::imshow("Canny", imgCanny);
    //cv::imshow("Dilation", imgDilation);
    cv::imshow("Erode", imgErode);
    cv::waitKey(0);
    return 0;
}
