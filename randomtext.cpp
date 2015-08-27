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

int Displaying_Random_Text( Mat image, char* window_name, RNG rng )
{
    int lineType = 8;
    for ( int i = 1; i < NUMBER; i++ )
    {
        Point org; org.x = rng.uniform(x_1, x_2);
        org.y = rng.uniform(y_1, y_2);
        putText( image, "Testing text rendering", org, rng.uniform(0,8), rng.uniform(0,100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);

imshow( window_name, image );
if( waitKey(DELAY) >= 0 )
{
    return -1;
}
    }
    return 0;
}


int main()
{
    Mat image = Mat::zeros( 400, 400, CV_8UC3 );
    putText( image, "Testing text rendering", org, rng.uniform(0,8),rng.uniform(0,100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);


return 0;
}
