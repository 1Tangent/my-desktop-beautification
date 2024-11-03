#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

int main(){
    cv::Mat test_pic=cv::Mat::zeros(cv::Size(466,45),CV_8UC3);
    cv::Mat test_pic_1=cv::Mat::zeros(cv::Size(1,45),CV_8UC3);
    cv::Vec3b white(255,255,255);
    cv::Vec3b blue(252,172,84);
    for(int i = 0; i < 466; i++){
        for(int j = 0; j < 45; j++){
            if ((j > 1 && j < 43) && (i > 0 && i < 464)){
                test_pic.at<cv::Vec3b>(j, i) = blue;
            }else{
                test_pic.at<cv::Vec3b>(j, i) = white;
            }
        }
    }
    for(int i = 0; i < 45; i++){
    cv::imshow("MY_PIC", test_pic);
        test_pic_1.at<cv::Vec3b>(i, 0) = white;
    }
    // bool pic = cv::imwrite("my_pic.png",test_pic_1);
    // if (pic == false)
    //     return 0;

    cv::imshow("MY_PIC", test_pic);
    cv::imshow("MY_PIC_1", test_pic_1);

    // cv::imwrite("my_pic.png",test_pic);
    bool pic = cv::imwrite("my_r.png",test_pic_1);
    if (pic == false){
        std::cout << "Fuck you!" << std::endl;
        return 0;
    }
        cv::waitKey(0);
        // return 0;
    return 0;
}