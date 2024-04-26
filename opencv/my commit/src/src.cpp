#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    std::string path = "/home/zcy/ZCY/hdu/rm/Assessment_winter/opencv/img/src/src.jpg";
    cv::Mat img=cv::imread(path);
    cv::Mat matrix;                        //转换矩阵(用于线性变换)
    cv::Mat imgWarp;
    float w = 9*40;
    float h = 17*40;
    cv::resize(img, img, cv::Size(), 0.3, 0.3);
    cv::Point2f src[4] = {{289,333}, {522,362}, {363,761}, {662,743}}; // 记录要旋转图片的四个顶点的坐标
    cv::Point2f dst[4] = {{0.0f,0.0f}, {w,0.0f}, {0.0f,h}, {w,h}}; // 记录目标矩阵的四个顶点的坐标
    matrix = cv::getPerspectiveTransform(src, dst);
    // 进行透视变换,使用转换矩阵来找到目标点(matrix相当于aX=b的一个解，其中a为src，b为dst)
    cv::warpPerspective(img, imgWarp, matrix, cv::Point(w, h));    // 对原图进行变换
    cv::imshow("Original", img);
    cv::imshow("Warp", imgWarp);
    cv::waitKey(0);
    return 0;
}
