#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()

{
	int i, j, k, row, col;
	uchar table[256];
	// cv:Mat mat;
	Scalar_<uint8_t> bgrPixel;

	Mat img = imread("pik.png", IMREAD_COLOR);
	row = img.rows;
	col = img.cols;
	int cn = img.channels();

	// cout<< img;
	Mat_<Vec3b> imgmat = img;
	uchar *p;
	for(int i=0; i<row; i++)
	{	
		Vec3b* ptr = img.ptr<Vec3b>(i);
		for(j=0; j<col; j++)
		{
			// Vec3b bgrPixel = img.at<Vec3b>(i, j);
			ptr[j] = Vec3b(ptr[j][2], ptr[j][1], ptr[j][0]);
			if(ptr[j] == Vec3b(236, 188, 62))
			{	
				ptr[j] = Vec3b(0, 0, 0);
			}
			cout<<ptr[j]<<endl;
		}

	}

	// cout<<img;
	// namedWindow("Display window", WINDOW_AUTOSIZE);
    // imshow("Display window,img);

    // waitKey(0);
	return 0;
	

}