// ncnn1.cpp: 定义应用程序的入口点。
//

#include "ncnn1.h"


using std::cout;
using std::endl;
using ncnn::Net;


ncnn::Mat resizeImg(ncnn::Mat img,int cols,int rows) {
	ncnn::Mat resizedImg;
	ncnn::resize_bilinear(img, resizedImg, cols, rows);
	return resizedImg;
}




int main()
{
	Net net;

	net.load_param("C:\\Users\\25190\\Documents\\Model\\yolov3.ncnn.param");
	net.load_model("C:\\Users\\25190\\Documents\\Model\\yolov3.ncnn.bin");

	cv::Mat bgr = cv::imread("C:\\Users\\25190\\Pictures\\TEST_IMAGE.jpg");
	
	ncnn::Mat in = ncnn::Mat::from_pixels(bgr.data, ncnn::Mat::PIXEL_BGR2RGB, bgr.cols, bgr.rows);

	ncnn::Mat resizedIn = resizeImg(in, 640, 640);
	
	const float mean[3] = { 0.0f, 0.0f, 0.0f };
	const float norm[3] = { 1.0f / 255.0f, 1.0f / 255.0f, 1.0f / 255.0f };

	resizedIn.substract_mean_normalize(mean, norm);

	ncnn::Extractor ex = net.create_extractor();
	ex.input("in0", resizedIn);
	ncnn::Mat out;
	ex.extract("out0",out);

	cout << "Dim " << out.w << "x" << out.h << "x" << out.c << endl;
	
	return 0;
}
