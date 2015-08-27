#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include<conio.h>


using namespace cv;
using namespace std;

int main()
{
    Mat im1 = imread("lena.jpg");
    if (im1.empty())
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }
 cvtColor(im1, im1, CV_BGR2GRAY);
    imshow("im1", im1);  // Original image

 Mat im2(im1.rows, im1.cols, CV_8UC1, Scalar(0,0,0));
 ellipse( im2, Point( 120, 130 ), Size( 50.0, 60.0 ), 0, 0, 360, Scalar( 255, 255, 255), -1, 8 );
 imshow("im2",im2);  // mask

 Mat res1,res2,res3;
 bitwise_and(im1,im2,res1);
 bitwise_or(im1,im2,res2);
 bitwise_xor(im1,im2,res3);
 namedWindow("AND",WINDOW_AUTOSIZE);
 namedWindow("OR",WINDOW_AUTOSIZE);
 namedWindow("XOR",WINDOW_AUTOSIZE);
 imshow("AND",res1);
 imshow("OR",res2);
 imshow("XOR",res3);

    waitKey(0);
 return 0;
}
