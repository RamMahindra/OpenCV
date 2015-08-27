#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;


int main( int argc, char** argv )
{
    Mat src,src_gray;
/// Load an image
src = imread("lena.jpg", 1 );
/// Convert the image to Gray
cvtColor( src, src_gray, CV_RGB2GRAY );
namedWindow("src",WINDOW_AUTOSIZE);
namedWindow("dst",WINDOW_AUTOSIZE);
imshow("src",src);
imshow("dst",src_gray);
return 0;
}
