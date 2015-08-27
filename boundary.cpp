#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;


/**
 * function main
 */
int main( void )
{


Mat src = imread("shapes.jpg",0);
if (src.empty())
    return -1;

normalize(src, src, 0, 1, cv::NORM_MINMAX);

Mat dst;
dst = Mat::zeros(src.size(), CV_8U);
dst.at<uchar>(75,75) = 1;

Mat prev;
Mat kernel = (Mat_<uchar>(3,3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);

do {
    dst.copyTo(prev);
    dilate(dst, dst, kernel);
    dst &= (1 - src);
}
while (countNonZero(dst - prev) > 0);

normalize(src, src, 0, 255, NORM_MINMAX);
normalize(dst, dst, 0, 255, NORM_MINMAX);


namedWindow("Image",WINDOW_AUTOSIZE);

    imshow("Image",dst);

    waitKey(0);
    destroyAllWindows();
    return 0;

}
