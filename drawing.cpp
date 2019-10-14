#include <iostream>
#include <stdio.h>
#include<iomanip>
#include<cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui.hpp>

#define w 400

using namespace cv;
using namespace std;

void Myellipse(Mat img, double angle)
{

	int thick = 2, line = 8;
	ellipse(img, Point(w/2, w/2), Size(w/4, w/16), angle, 0, 360, Scalar(255, 0, 0), thick, line);

}

void MyFilledCircle( Mat img, Point center )
{
  circle(img, center, w/32, Scalar(0, 255, 0), CV_FILLED, 8, 0);
}

void MyLine( Mat img, Point start, Point end )
{
  int thickness = 2;
  int lineType = 8;
  line( img,
    start,
    end,
    Scalar( 0, 0, 0 ),
    thickness,
    lineType );
}

int main(void)
{
	char atom_window[] = "Drawing 1: Atom";
	Mat atom_image = Mat::zeros(w, w, CV_8UC3);
	Mat rook_image = Mat::zeros(w, w, CV_8UC3);
	Myellipse(atom_image, 45);
	Myellipse(atom_image, 0);
	Myellipse(atom_image, -45);
	Myellipse(atom_image, 90);
	MyFilledCircle( atom_image, Point( w/2, w/2) );

	imshow(atom_window, atom_image);
	moveWindow( atom_window, 0, 200 );
	// cout<<atom_image;
	waitKey(0);
	return(0);
}