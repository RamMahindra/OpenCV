#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;


int main( )
{
    Mat image;
    image = imread("shapes.jpg", 1);
    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    Mat gray;
    cvtColor(image, gray, CV_BGR2GRAY);
    Canny(gray, gray, 100, 200, 3);
    /// Find contours
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    RNG rng;
    findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    /// Draw contours
    Mat drawing = Mat::zeros( gray.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }

    imshow( "Result window", drawing );
    waitKey(0);
    return 0;
}
