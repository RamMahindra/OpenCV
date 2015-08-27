#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;



int main( )
{

  Mat image = Mat::zeros( 400, 400, CV_8UC3 );


  line( image, Point( 15, 20 ), Point( 400, 50), Scalar( 110, 220, 0 ),  2, 8 );
  circle( image, Point( 200, 200 ), 32.0, Scalar( 0, 0, 255 ), 1, 8 );
  ellipse( image, Point( 200, 200 ), Size( 100.0, 160.0 ), 45, 0, 360, Scalar( 255, 0, 0 ), 1, 8 );
  rectangle( image, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 55, 255 ), +1, 4 );
  putText(image, "Workshop", Point(50,100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);


  Point rook_points[1][4];
    rook_points[0][0] = Point( 300, 300 );
    rook_points[0][1] = Point( 350, 300 );
    rook_points[0][2] = Point( 400, 400 );
    rook_points[0][3] = Point( 150, 400 );

    const Point* ppt[1] = { rook_points[0] };
    int npt[] = { 4 };

    fillPoly( image, ppt, npt, 1, Scalar( 255, 255, 255 ), 8 );



  imshow("Image",image);

  waitKey( 0 );
  return(0);
}
