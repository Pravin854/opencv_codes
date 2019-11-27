// To detect a color in the image

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()

{
	int i, j, k, row, col;
	uchar table[256];
	// cv:Mat mat;
	Scalar_<uint8_t> bgrPixel;

	Mat img = imread("pik.png", IMREAD_COLOR);  // reading the image
	row = img.rows;
	col = img.cols;

	Mat hsv, mask1, mask2;
	cvtColor(img, hsv, COLOR_BGR2HSV);   /* converting image from RGB to HSV space because RGB is very
										    sensitive to the the illumination */

	inRange(hsv, Scalar(20, 120, 70), Scalar(40, 255, 255), mask1); 	// creating mask to detect lower color
	inRange(hsv, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);	// creating mask to detect upper color

	mask1 = mask1 + mask2;				// Final mask (Two masks because in HSV colors are represented in the form of a circle)
	Mat kernel = Mat::ones(3,3, CV_32F);
	morphologyEx(mask1,mask1,MORPH_OPEN,kernel); // Removing noise from the Mask
	morphologyEx(mask1,mask1,MORPH_DILATE,kernel);

	bitwise_not(mask1,mask2); // Inverting each bit of an array to get the color which is not desired
	Mat res1, res2, final_output;

	// Segmenting the cloth out of the frame using bitwise and with the inverted mask
	bitwise_and(img,img,res1,mask1);
	imshow("original", img);
	imshow("magic", res1);
	// cout<<res1;

	// // cout<< img;
	// Mat_<Vec3b> imgmat = img;
	// uchar *p;
	// for(int i=0; i<row; i++)
	// {	
	// 	Vec3b* ptr = img.ptr<Vec3b>(i);
	// 	for(j=0; j<col; j++)
	// 	{
	// 		// Vec3b bgrPixel = img.at<Vec3b>(i, j);
	// 		ptr[j] = Vec3b(ptr[j][2], ptr[j][1], ptr[j][0]);
	// 		if(ptr[j] == Vec3b(236, 188, 62))
	// 		{	
	// 			ptr[j] = Vec3b(0, 0, 0);
	// 		}
	// 		cout<<ptr[j]<<endl;
	// 	}

	// }

	// cout<<img;
	// namedWindow("Display window", WINDOW_AUTOSIZE);
    // imshow("Display window,img);

    waitKey(0);
	return 0;
}