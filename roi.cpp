#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;



int main()
{
Mat src1, imageROI, logo;

logo = imread("cute.jpg", 0);
cvSetImageROI(logo,cvRect(10,10,100,200));
//imageROI= image(Rect(100,100,logo.cols,logo.rows));

addWeighted(logo,1.0,0,0,50,logo);

cvResetImageROI(logo);
namedWindow("meh", CV_WINDOW_AUTOSIZE);
imshow("meh", logo);
waitKey(0);


return 0;
}
