#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;


void conv2(Mat src, int kernel_size)
{
    Mat dst;
    //kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(9*kernel_size*kernel_size);
    Mat kernel = (Mat_<double>(3,3) << 1, 1, 1, -1, -1, -1, 1, 1, 1);

    /// Apply filter
    filter2D(src, dst, -1 , kernel, Point( -1, -1 ), 0, BORDER_DEFAULT );
    namedWindow( "filter2D Demo", CV_WINDOW_AUTOSIZE );
    namedWindow( "filter2D", CV_WINDOW_AUTOSIZE );
    imshow( "filter2D", src );
    imshow( "filter2D Demo", dst );
}

int main ()
{
    Mat src;

    /// Load an image
    src = imread( "grid.jpg" );
    if( !src.data )  { return -1; }

    conv2(src,3);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

