#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;


Mat rotate(Mat src, double angle)
{
    Mat dst;
    Point2f pt(src.cols/2., src.rows/2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    return dst;
}

int main()
{
    Mat src = imread("lena.jpg");

    Mat dst;
    dst = rotate(src, 10);

    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);
    return 0;
}
