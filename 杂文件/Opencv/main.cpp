#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:\\资料\\课题资料\\Excel数据提取流程.png");
	namedWindow("输出窗口", WINDOW_AUTOSIZE);
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	imshow("输出窗口", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
