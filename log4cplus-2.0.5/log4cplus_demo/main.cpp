#include <iostream>
#include "log.h"

//����ʾ����̨����
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup")


int main()
{
	
	HYLog.Init("D:/workspace/test-trunk/log4cplus-2.0.5/log4cplus_demo/log.config");
	for (size_t i = 0; i < 1000000000; i++)
	{
		LOG_INFO("��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ������Info��");
		LOG_INFO("��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ����Error��");
		LOG_INFO("��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ��ʼ��ӡ��־��Ϣ����Warn��");

	}
	std::cout << "Hello World.." << std::endl;
	//HYLog.Close();
	return 0;
}