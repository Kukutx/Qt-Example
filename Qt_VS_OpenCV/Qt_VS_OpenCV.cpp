#include "Qt_VS_OpenCV.h"
#include <opencv2/opencv.hpp>
using namespace cv;
Qt_VS_OpenCV::Qt_VS_OpenCV(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//������ͷ������Ƶ
	VideoCapture capture(0);
	//ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;//�洢ÿһ֡ͼ��
		capture >> frame;//��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);//��ʱ30����
	}
}
