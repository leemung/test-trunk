#include <iostream>
#include "log.h"

//不显示控制台窗口
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup")


int main()
{
	
	HYLog.Init("D:/workspace/test-trunk/log4cplus-2.0.5/log4cplus_demo/log.config");
	for (size_t i = 0; i < 1000000000; i++)
	{
		LOG_INFO("开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息。。。Info。");
		LOG_INFO("开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息。。Error。");
		LOG_INFO("开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息开始打印日志信息。。Warn。");

	}
	std::cout << "Hello World.." << std::endl;
	//HYLog.Close();
	return 0;
}