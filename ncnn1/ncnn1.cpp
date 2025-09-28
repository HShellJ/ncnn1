// ncnn1.cpp: 定义应用程序的入口点。
//

#include "ncnn1.h"


using std::cout;
using std::endl;
using ncnn::Net;


ncnn::Mat prepare_input(int x) {
	ncnn::Mat input(1);
	input[0] = (float)x;
	return input;
}




int main()
{
	Net net;

	net.load_param("C:\\Users\\25190\\Documents\\Model\\function_fitting_model.ncnn.param");
	net.load_model("C:\\Users\\25190\\Documents\\Model\\function_fitting_model.ncnn.bin");

	cv::Mat img = cv::imread("C:\\Users\\25190\\Pictures\\TEST_IMAGE.jpg");

	return 0;
}
