#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:\\����\\��������\\Excel������ȡ����.png");
	namedWindow("�������", WINDOW_AUTOSIZE);
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	imshow("�������", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
