/*                                                   // 上下两段分别为1、2两张图片的处理代码
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
int main(){
    std::string path="../1.jpg";
    cv::Mat img = cv::imread(path);
    cv::cvtColor(img, img, cv::COLOR_RGB2GRAY);
    cv::Mat imgGray = img.clone();
    int height = img.rows;
    int width = img.cols;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int gray = img.at<uchar>(i, j);
            imgGray.at<uchar>(i,j)=std::pow(gray,1/2.2);
        }
    }
    cv::normalize(imgGray, imgGray, 0, 255, cv::NORM_MINMAX);
    cv::imshow("Original", img);
    cv::imshow("Gray", imgGray);
    cv::waitKey(0);
    return 0;
}
*/



#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

void MyGammaCorrection(cv::Mat &img, cv::Mat &imgGamma, float fGamma)
{

    unsigned char lut[256];            // 保存每个灰度级别对应的Gamma校正后的值
    for (int i = 0; i < 256; i++)
    {
        lut[i] = cv::saturate_cast<uchar>(std::pow((float)(i / 255.0), fGamma) * 255.0f);
    }

    imgGamma = img.clone();
    const int channels = imgGamma.channels();
    switch (channels)
    {
    case 1:                                              // 灰度图的情况
    {

        cv::MatIterator_<uchar> nowp, endp;              // 迭代器
        for (nowp = imgGamma.begin<uchar>(), endp = imgGamma.end<uchar>(); nowp != endp; nowp++)
            //*nowp = std::pow((float)(((*nowp))/255.0), fGamma) * 255.0;
            *nowp = lut[(*nowp)];

        break;
    }
    case 3:                                              // 彩色图的情况
    {

        cv::MatIterator_<cv::Vec3b> nowp, endp;
        for (nowp = imgGamma.begin<cv::Vec3b>(), endp = imgGamma.end<cv::Vec3b>(); nowp != endp; nowp++)
        {
            //(*nowp)[0] = std::pow((float)(((*nowp)[0])/255.0), fGamma) * 255.0;
            //(*nowp)[1] = std::pow((float)(((*nowp)[1])/255.0), fGamma) * 255.0;
            //(*nowp)[2] = std::pow((float)(((*nowp)[2])/255.0), fGamma) * 255.0;
            (*nowp)[0] = lut[((*nowp)[0])];
            (*nowp)[1] = lut[((*nowp)[1])];
            (*nowp)[2] = lut[((*nowp)[2])];
        }

        break;
    }
    }
}

int main()
{
    cv::Mat img = cv::imread("../2.jpg");

    cv::Mat dst1;
    cv::Mat dst2;
    float fGamma1 = 1 / 2.2;
    float fGamma2 = 2;
    MyGammaCorrection(img, dst1, fGamma1);
    MyGammaCorrection(img, dst2, fGamma2);


    cv::imshow("Original", img);
    cv::imshow("Gamma=1/2.2", dst1);
    cv::imshow("Gamma=2", dst2);

    cv::waitKey(0);

    return 0;
}
