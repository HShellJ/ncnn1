// ncnn1.cpp: 定义应用程序的入口点。
//

#include "ncnn1.h"

using std::cout;
using std::endl;
using ncnn::Net;
using ncnn::Mat;

Mat prepare_input(int x) {
	// 创建1维输入（长度为1），值为x（若训练时有归一化，需同步处理，如x/1000.0）
	Mat input(1);
	input[0] = (float)x;
	return input;
}

int main()
{
	Net net;

	net.load_param("C:\\Users\\25190\\Documents\\Model\\function_fitting_model.ncnn.param");
	net.load_model("C:\\Users\\25190\\Documents\\Model\\function_fitting_model.ncnn.bin");


    for (int x = 1; x <= 1000; x++) {
        // 准备1维输入
        Mat input = prepare_input(x);
        ncnn::Extractor ex = net.create_extractor();
        ex.input("in0", input);
        Mat output;
        ex.extract("out0", output);
        float result = output[0];
        cout << "输入: " << x << ", 推理结果: " << result << endl;
    }

	return 0;
}
