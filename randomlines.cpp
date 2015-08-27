#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;


void Drawing_Random_Lines( Mat image, char* window_name, RNG rng, int NumOfLines, int windowHeight, int windowWidth );
static Scalar randomColor( RNG& rng );

int main( )
{
    int windowHeight = 480, windowWidth=640;
    Mat image = Mat::zeros( windowHeight, windowWidth, CV_8UC3 );
    namedWindow( "Source", CV_WINDOW_AUTOSIZE );
    int n=1;
    while(1)
    {
    RNG rng(n);
    Drawing_Random_Lines(image, "Source", rng, 5, windowHeight, windowWidth);
    imshow( "Source", image );
    waitKey(100);
    n++;
    }

    return(0);
}

void Drawing_Random_Lines( Mat image, char* window_name, RNG rng, int NumOfLines, int windowHeight, int windowWidth )
{

    Point pt1, pt2;

    for( int i = 0; i < NumOfLines; i++ )
    {
        pt1.x = rng.uniform( 0, windowWidth );
        pt1.y = rng.uniform( 0, windowHeight );
        pt2.x = rng.uniform( 0, windowWidth );
        pt2.y = rng.uniform( 0, windowHeight );

        line( image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), 8 );
        imshow( window_name, image );
    }
}

static Scalar randomColor( RNG& rng )
{
    int icolor = (unsigned) rng;
    return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
}
