#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("lena.jpg", 1);
	cv::Mat dstMat, dstMat1;

	int height = srcMat.rows;
	int width = srcMat.cols;

	//顺时针旋转10°
	float angle = -10.0, scale = 1;
	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols * 0.5, srcMat.rows * 0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	//改进后
	float scale1 = width / (sin(abs(angle) / 360 * 2 * 3.14) * height + cos(abs(angle) / 360 * 2 * 3.14) * width);
	cout << scale1 << endl;
	//获得变换矩阵
	const cv::Mat affine_matrix1 = cv::getRotationMatrix2D(center, angle, scale1);
	cv::warpAffine(srcMat, dstMat1, affine_matrix1, srcMat.size());

	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
	cv::imshow("dstMat1", dstMat1);
	waitKey(0);
}