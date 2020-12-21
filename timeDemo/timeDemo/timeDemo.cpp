// timeDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#pragma warning(disable:4996)
#ifdef _WIN32
#include <iostream>
#include <winsock2.h>
#include <time.h>
#include <shellapi.h>
#else
#include <sys/time.h>
#endif

unsigned long long GetCurrentTimeMsec()
{
#ifdef _WIN32
	struct timeval tv;
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;

	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tv.tv_sec = clock;
	tv.tv_usec = wtm.wMilliseconds * 1000;
	return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#else
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#endif
}

int main()
{
	//std::cout << GetCurrentTimeMsec();

	char buf_msg[] = "{ \"ip\":\"192.168.1.154\", \"port\" : 37777, \"userName\" : \"admin\", \"passWord\" : \"admin123\", \"devName\" : \"地面入口相机\", \"devNameOld\" : \"地面入口相机\", \"x\" : 122, \"y\" : 202, \"wide\" : 400, \"high\" : 190 }";

	WCHAR buf[256];
	memset(buf, 0, sizeof(buf));
	MultiByteToWideChar(CP_ACP, 0, buf_msg, strlen(buf_msg) + 1, buf, sizeof(buf) / sizeof(buf[0]));


	//ShellExecute(NULL, L"open", L"F:\\gitspace\\timeDemo\\Release\\RealPlay.exe", buf_msg, L"F:\\gitspace\\timeDemo\\Release\\RealPlay.exe", SW_SHOW);

	ShellExecute(NULL, L"open", L".\\RealPlay.exe", buf, L".\\RealPlay.exe", SW_SHOW);

	std::cout << "开启视频..." << std::endl;
	system("pause");
	return 0;
}