/*****************************************************************************\
*
*                            ͣ��������ϵͳӲ������ƽ̨ 1.0
*
*           Copyright (C) 2019, ���ݻ��ƿƼ����޹�˾ �з���
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* ��  ��  ����log.h
* ��      ;����־ģ��Ľӿ�
* ��      �ߣ�����
* �������ڣ�2019.11
* �� �� �ţ�1.0.0.001
* �޸���ʷ��
*
* ===========================================================================
*
* N O T E:
*           1. Platform: WIN32
*
*****************************************************************************/
#pragma once
#include <memory>
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>

class Log
{
public:
	static log4cplus::Logger s_logger;

	static Log& GetInstance()
	{
		static Log instance;
		return instance;
	}

	/// ������־ϵͳ
	/// @param[in] properties_filename ��־ϵͳ�����ļ��ļ���
	/// log��������Զ��������ļ�������
	void Init(const char* properties_filename);

	void Debug(const char* file, int line, const char* pFormat, ...);

	void Error(const char* file, int line, const char* pFormat, ...);

	void Fatal(const char* file, int line, const char* pFormat, ...);

	void Info(const char* file, int line, const char* pFormat, ...);

	void Warn(const char* file, int line, const char* pFormat, ...);

	void Trace(const char* file, int line, const char* pFormat, ...);

private:
	Log();
	~Log();
 };

#define HYLog Log::GetInstance()

//////////////////////////////////////////////////////////////////////////
// ������־
//////////////////////////////////////////////////////////////////////////
#define ASSERT_LOG(expr)\
    if ( (expr) ) {;} else HYLog.Error(__FILE__, __LINE__, #expr);


//////////////////////////////////////////////////////////////////////////
// ���µĺ�ֻ��VS2005�Լ�֮�ϵİ汾����ʹ�ã���ΪVS2005֮�µİ汾��֧�ֿɱ������
//////////////////////////////////////////////////////////////////////////
#if defined(_MSC_VER) && _MSC_VER > 1400
#define LOG_DEBUG(...)    HYLog.Debug( __FILE__, __LINE__, __VA_ARGS__);
#define LOG_ERROR(...)	  HYLog.Error( __FILE__, __LINE__, __VA_ARGS__);
#define LOG_FATAL(...)    HYLog.Fatal( __FILE__, __LINE__, __VA_ARGS__);
#define LOG_INFO(...)     HYLog.Info( __FILE__, __LINE__, __VA_ARGS__);
#define LOG_WARN(...)     HYLog.Warn( __FILE__, __LINE__, __VA_ARGS__);
#define LOG_TRACE(...)    HYLog.Trace( __FILE__, __LINE__, __VA_ARGS__);
#elif defined(__linux__)
#define LOG_DEBUG(...)    HYLog.Debug(__FILE__, __LINE__,__VA_ARGS__);
#define LOG_ERROR(...)    HYLog.Error(__FILE__, __LINE__,__VA_ARGS__);
#define LOG_FATAL(...)    HYLog.Fatal(__FILE__, __LINE__,__VA_ARGS__);
#define LOG_INFO(...)     HYLog.Info(__FILE__, __LINE__,__VA_ARGS__);
#define LOG_WARN(...)     HYLog.Warn(__FILE__, __LINE__,__VA_ARGS__);
#define LOG_TRACE(...)    HYLog.Trace(__FILE__, __LINE__,__VA_ARGS__);
#endif

