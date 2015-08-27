#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videostab/videostab.hpp"

using namespace cv;
using namespace std;

int power(int a,int n)
{
    int temp=1;
    while(n!=0)
    {
        temp=a*temp;
        n=n-1;
    }
    return temp;
}

int main()
{

    IplImage* input=cvLoadImage("barbara.png",0);

    int height,width,step1,nchannels,step2;
    uchar*data=(uchar*)input->imageData;
    height=input->height;
    width=input->width;
    step1=input->widthStep;
    nchannels=input->nChannels;


    int level;
    cout<< "enter the no of levels: ";
    cin>>level;
    cout<<endl;

    IplImage* dwtimage=cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1);

    IplImage* opimage=cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1);
    uchar*dwtdata=(uchar*)dwtimage->imageData;
    step2 = opimage->widthStep;
    IplImage* tempdata=cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1);
    uchar*temp=(uchar*)tempdata->imageData;

    for(int k=0;k<nchannels;k++)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                temp[i*step1+j*nchannels+k]=data[i*step1+j*nchannels+k];
            }
        }
    }


int nwidth,nheight,step;
nwidth=width;
nheight=height;
step=step1;

    for(int i=1;i<=level;i++)
    {
        IplImage*High=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*H=(uchar*)High->imageData;
        IplImage*Low=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*L=(uchar*)Low->imageData;
        IplImage*HighHigh=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*HH=(uchar*)HighHigh->imageData;
        IplImage*LowLow=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*LL=(uchar*)LowLow->imageData;
        IplImage*HighLow=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*HL=(uchar*)HighLow->imageData;
        IplImage*LowHigh=cvCreateImage(cvSize(nwidth,nheight),IPL_DEPTH_8U,1);
        uchar*LH=(uchar*)LowHigh->imageData;

        for(int k=0;k<nchannels;k++)
        {
            for(int r=0;r<(nheight);r++)
            {
                for(int c=0;c<(nwidth);c++)
                {
                    for(int p=0;p<2;p++)
                    {
                        if(p==0)
                        {
                            //high
                            if(c==0)
                            {
                                H[r*(High->widthStep)+c*nchannels+k]=temp[r*(tempdata->widthStep)+(nwidth-1)*nchannels+k] - temp[r*(tempdata->widthStep)+(c)*nchannels+k];
                            }
                            else
                            {
                                H[r*(High->widthStep)+c*nchannels+k]=temp[r*(tempdata->widthStep)+(c-1)*nchannels+k] - temp[r*(tempdata->widthStep)+(c)*nchannels+k];
                            }
                        }
                        if(p==1)
                        {
                            //low
                            if(c==0)
                            {
                                L[r*(Low->widthStep)+c*nchannels+k]=(temp[r*(tempdata->widthStep)+(nwidth-1)*nchannels+k]+temp[r*(tempdata->widthStep)+(c)*nchannels+k])/2;
                            }
                            else
                            {
                                L[r*(Low->widthStep)+c*nchannels+k]=(temp[r*(tempdata->widthStep)+(c-1)*nchannels+k] + temp[r*(tempdata->widthStep)+(c)*nchannels+k])/2;
                            }
                        }
                    }

                }
            }
        }

        for(int k=0;k<nchannels;k++)
        {
            for(int c=0;c<nwidth;c++)
            {
                for(int r=0;r<nheight;r++)
                {

                    for(int p=0;p<4;p++)
                    {
                        if(p==0)
                        {
                            //HH
                            if(r==0)
                            {
                                HH[r*(HighHigh->widthStep)+c*nchannels+k]=H[((nheight)-1)*(High->widthStep)+c*nchannels+k] - H[r*(High->widthStep)+c*nchannels+k];
                            }
                            else
                            {
                                HH[r*(HighHigh->widthStep)+c*nchannels+k]=H[(r-1)*(High->widthStep)+c*nchannels+k] - H[r*(High->widthStep)+c*nchannels+k];
                            }
                        }
                        if(p==1)
                        {
                            //LH
                            if(r==0)
                            {
                                LH[r*(LowHigh->widthStep)+c*nchannels+k]=(H[((nheight)-1)*(High->widthStep)+c*nchannels+k] + H[r*(High->widthStep)+c*nchannels+k])/2;

                            }
                            else
                            {
                                LH[r*(LowHigh->widthStep)+c*nchannels+k]=(H[(r-1)*(High->widthStep)+c*nchannels+k] + H[r*(High->widthStep)+c*nchannels+k])/2;

                            }
                        }
                        if(p==2)
                        {
                            //HL
                            if(r==0)
                            {
                                HL[r*(HighLow->widthStep)+c*nchannels+k]=L[((nheight)-1)*(Low->widthStep)+c*nchannels+k] - L[r*(Low->widthStep)+c*nchannels+k];
                            }
                            else
                            {
                                HL[r*(HighLow->widthStep)+c*nchannels+k]=L[(r-1)*(Low->widthStep)+c*nchannels+k] - L[r*(Low->widthStep)+c*nchannels+k];

                            }
                        }
                        if(p==3)
                        {
                            //LL
                            if(r==0)
                            {
                                LL[r*(LowLow->widthStep)+c*nchannels+k]=(L[((LowLow->height)-1)*(Low->widthStep)+c*nchannels+k] + L[r*(Low->widthStep)+c*nchannels+k])/2;
                            }
                            else
                            {
                                LL[r*(LowLow->widthStep)+c*nchannels+k]=(L[(r-1)*(Low->widthStep)+c*nchannels+k] + L[r*(Low->widthStep)+c*nchannels+k])/2;
                            }
                        }
                    }
                }
            }

        }

    for(int k=0;k<nchannels;k++)
    {//
        for(int h=0;h<(height)/(power(2,i));h++)
        {
            for(int w=0;w<(width)/(power(2,i));w++)
            {
                for(int p=0;p<4;p++)
                {
                    if(p==0)
                    {
                        dwtdata[(h)*(step1)+(w)*nchannels+k]=LL[h*2*(LowLow->widthStep)+w*2*nchannels+k];
                    }
                    if(p==1)
                    {
                        dwtdata[(h+((height)/power(2,i)))*(step1)+(w)*nchannels+k]=LH[h*2*(LowHigh->widthStep)+w*2*nchannels+k];
                    }
                    if(p==2)
                    {
                        dwtdata[(h)*(step1)+(w+((width)/power(2,i)))*nchannels+k]=HL[h*2*(HighLow->widthStep)+w*2*nchannels+k];
                    }
                    if(p==3)
                    {
                        dwtdata[(h+((height)/power(2,i)))*(step1)+(w+((width)/power(2,i)))*nchannels+k]=HH[h*2*(HighHigh->widthStep)+w*2*nchannels+k];
                    }
                }

            }
        }
    }

//    IplImage*tempdata=cvCreateImage(cvSize((int)width/(power(2,i)),(int)height/(power(2,i))),IPL_DEPTH_8U,1);
//    uchar*temp=(uchar*)tempdata->imageData;


    nwidth=nwidth/2;
    nheight=nheight/2;
    step=step/2;


    for(int k=0;k<nchannels;k++)
    {//temp[height][width] is loaded with image data
        for(int h=0;h<nheight;h++)
        {
            for(int w=0;w<nwidth;w++)
            {
                temp[h*(tempdata->widthStep)+w*nchannels+k]=LL[h*2*(LowLow->widthStep)+w*2*nchannels+k];
            }
        }
    }

    cvReleaseImage(&High);
    cvReleaseImage(&Low);
    cvReleaseImage(&HighHigh);
    cvReleaseImage(&LowHigh);
    cvReleaseImage(&HighLow);
    cvReleaseImage(&LowLow);


    }

    Mat m(dwtimage);
    Mat dst;
    Point2f pt(m.cols/8., m.rows/8.);
    Mat r = getRotationMatrix2D(pt, 0, 1.0);
    warpAffine(m, dst, r, Size(m.cols/4., m.rows/4.));




    cout << m.cols <<" " << m.rows <<"  " << endl;
    cout << dwtimage->height << "  " << dwtimage->width << "   " << endl;
    cout << step2 << endl;
    cout << dwtimage << endl;
    cvShowImage("input",input);
    cvShowImage("dwtimage",dwtimage);
    cvSaveImage("dwtimage.jpg",dwtimage);


    namedWindow("im",WINDOW_AUTOSIZE);
    imshow("im",dst);


    cvWaitKey(0);
    cvReleaseImage(&tempdata);
    cvReleaseImage(&input);
    cvReleaseImage(&dwtimage);
}

