#include <iostream>
#include "log.h"
//����ʾ����̨����
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup")

int main()
{
	
	HYLog.Init("./log.config");

	for (size_t i = 0; i < 1000000000; i++)
	{
		HYLog.Info("[%s] ��ʼ��ӡ��־��Ϣ������Info��", __FUNCTION__);
		HYLog.Error("[%s] ��ʼ��ӡ��־��Ϣ����Error��", __FUNCTION__);
		HYLog.Warn("[%s] ��ʼ��ӡ��־��Ϣ����Warn��", __FUNCTION__);
		
	}
	std::cout << "Hello World.." << std::endl;
	//HYLog.Close();
	return 0;
}