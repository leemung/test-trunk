/**********************************************************************
* Copyright (C) 2019 -  - All Rights Reserved
*
* �ļ�����:       Log.cpp
* ժ    Ҫ:       ��־������,��־ģ��Ľӿ�
*
* ��    ��:       limin
* ��    ��:       �鿴�ļ����·�.
*
***********************************************************************/

#define  _CRT_SECURE_NO_WARNINGS
#include "log.h"


using namespace log4cplus;
using namespace log4cplus::helpers;

log4cplus::Logger Log::s_logger = log4cplus::Logger::getInstance("rootLogger");

Log::Log()
{	
}

Log::~Log()
{
	s_logger.shutdown();
}

void Log::Debug(const char* file, int line, const char* pFormat, ...)
{
	
	s_logger.log(log4cplus::DEBUG_LOG_LEVEL, pFormat, file, line);
}

void Log::Error(const char* file, int line, const char* pFormat, ...)
{
	s_logger.log(log4cplus::ERROR_LOG_LEVEL, pFormat, file, line);
}

void Log::Fatal(const char* file, int line, const char* pFormat, ...)
{
	s_logger.log(log4cplus::FATAL_LOG_LEVEL, pFormat, file, line);
}

void Log::Info(const char* file, int line, const char* pFormat, ...)
{
	s_logger.log(FATAL_LOG_LEVEL, pFormat, file, line);
}

void Log::Warn(const char* file, int line, const char* pFormat, ...)
{
	s_logger.log(log4cplus::WARN_LOG_LEVEL, pFormat, file, line);
}

void Log::Trace(const char* file, int line, const char* pFormat, ...)
{
	s_logger.log(log4cplus::TRACE_LOG_LEVEL, pFormat, file, line);
}

void Log::Init(const char* properties_filename)
{
	if (properties_filename == NULL) return;
	////����1��ʹ�������ļ�����log��ʽ
	log4cplus::initialize();
	log4cplus::PropertyConfigurator::doConfigure(properties_filename);
}