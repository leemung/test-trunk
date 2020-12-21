#include <iostream>
#include "log.h"
//不显示控制台窗口
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup")

int main()
{
	
	HYLog.Init("D:\\CodeSpace\\CppTools\\log4cplus-2.0.5\\msvc14\\Release\\log.config");

	for (size_t i = 0; i < 1000000000; i++)
	{
		HYLog.Info("[%s] 开始打印日志信息。。。Info。", __FUNCTION__);
		HYLog.Error("[%s] 开始打印日志信息。。Error。", __FUNCTION__);
		HYLog.Warn("[%s] 开始打印日志信息。。Warn。", __FUNCTION__);
		
	}
	std::cout << "Hello World.." << std::endl;
	//HYLog.Close();
	return 0;
}