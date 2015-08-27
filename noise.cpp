#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;


void Add_salt_pepper_Noise(Mat &srcArr, float pa, float pb )

{    RNG rng;
    int amount1=srcArr.rows*srcArr.cols*pa;
    int amount2=srcArr.rows*srcArr.cols*pb;
    for(int counter=0; counter<amount1; ++counter)
    {

     srcArr.at<uchar>(rng.uniform( 0,srcArr.rows), rng.uniform(0, srcArr.cols)) =0;

    }
     for (int counter=0; counter<amount2; ++counter)
     {
     srcArr.at<uchar>(rng.uniform(0,srcArr.rows), rng.uniform(0,srcArr.cols)) = 255;
     }
}



void Add_gaussian_Noise(Mat &srcArr,double mean,double sigma)
{
    Mat NoiseArr = srcArr.clone();
    RNG rng;
    rng.fill(NoiseArr, RNG::NORMAL, mean,sigma);


    add(srcArr, NoiseArr, srcArr);
}



int main()
{
    Mat srcArr;


    srcArr = imread("lena512.jpg");


  cvtColor(srcArr,srcArr, CV_RGB2GRAY,1);
  imshow("The original Image", srcArr);

 Mat srcArr1 = srcArr.clone();
 Mat srcArr2 = srcArr.clone();
 Mat dstArr;

 float sigma,mean,pa,pb;
 cout<<"input the sigma and mean of the expect gaussian noise = ";
 cin>>sigma>>mean;

 cout<<"input the pa and pb of the expect salt&pepper noise = ";
 cin>>pa>>pb;


  Add_salt_pepper_Noise(srcArr1, pa,pb);
  imshow("Add salt and pepper noise to image ", srcArr1);
  imwrite("salt&pepper noise image.tif",srcArr1);


  medianBlur(srcArr1, dstArr, 5);
  imshow ("The effect after median filter",dstArr);
  imwrite("filter image.tif",dstArr);


  Add_gaussian_Noise(srcArr2, mean, sigma);
  imshow("Add gaussian noise to image", srcArr2);
  imwrite("salt&pepper noise image.tif",srcArr2);
  waitKey(0);
  return 0;
}

