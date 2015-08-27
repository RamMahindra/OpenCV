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
double alpha = 0.5; double beta;
Mat src1, src2, dst, dst2;

beta = ( 1.0 - alpha );

src1 = imread("lena512.jpg",1);
src2 = imread("cameraman_512.jpg",1);

namedWindow("window1",WINDOW_AUTOSIZE);
namedWindow("window2",WINDOW_AUTOSIZE);
namedWindow("window3",WINDOW_AUTOSIZE);

addWeighted( src1,alpha,src2,beta, 20.0, dst);

dst2 = src1 - src2;
cout << dst2;

imshow( "window1", src1 );
imshow( "window2", dst );
imshow( "window3", dst2 );
waitKey(0);
return 0;
}
