// To track a color in the video

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()

{

	VideoCapture cap("mass_0.1.mp4"); // read the video
	if(!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
  		return -1;
	}

	while(1)
	{
		Mat img;
		cap >> img; // capturing frame of the video

		if(img.empty())
			break;

		Mat hsv, mask1, mask2;
		cvtColor(img, hsv, COLOR_BGR2HSV); /* converting image from RGB to HSV space because RGB is very
										    sensitive to the the illumination */ 

		inRange(hsv, Scalar(30, 0, 120), Scalar(40, 255, 180), mask1); // lower mask to detect the color
		// inRange(hsv, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);

		Mat kernel = Mat::ones(3,3, CV_32F);
		morphologyEx(mask1,mask1,MORPH_OPEN,kernel); // removing noise from the mask
		morphologyEx(mask1,mask1,MORPH_DILATE,kernel);

		bitwise_not(mask1,mask2);   // bitwise inverting the mask
		Mat res1, res2, final_output;

		bitwise_and(img,img,res1,mask2); 	// Segmenting the cloth out of the frame using bitwise and with the inverted mask
		// imshow("original", img);
		imshow("magic", res1);

		// imshow("Image", img);
		char c=(char)waitKey(25);	// stop the code when Esc is pressed
		if(c==27)
			break;
	}

	cap.release();
	destroyAllWindows();

	return 0;
}