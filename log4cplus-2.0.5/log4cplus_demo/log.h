/*****************************************************************************\
*
*                            停车场管理系统硬件虚拟平台 1.0
*
*           Copyright (C) 2019, 杭州华云科技有限公司 研发部
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* 文  件  名：log.h
* 用      途：日志模块的接口
* 作      者：李敏
* 创建日期：2019.11
* 版 本 号：1.0.0.001
* 修改历史：
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

	/// 启动日志系统
	/// @param[in] properties_filename 日志系统配置文件文件名
	/// log种类和属性都在配置文件中设置
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
// 断言日志
//////////////////////////////////////////////////////////////////////////
#define ASSERT_LOG(expr)\
    if ( (expr) ) {;} else HYLog.Error(__FILE__, __LINE__, #expr);


//////////////////////////////////////////////////////////////////////////
// 以下的宏只有VS2005以及之上的版本可以使用！因为VS2005之下的版本不支持可变参数宏
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

