#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;


int main()
{

Mat src1;
src1 = imread("lena512.jpg",0);
imshow("original",src1);
for(int i=0;i < 5;i++)
{
    for(int j=0;j < 5;j++)
    {
       // src1.at<uchar>(i,j)=255- src1.at<uchar>(i,j);
        cout << src1.at<double_t>(i,j) << endl;
    }
}

namedWindow("window1",WINDOW_AUTOSIZE);
imshow( "window1", src1 );

waitKey(0);
return 0;
}

