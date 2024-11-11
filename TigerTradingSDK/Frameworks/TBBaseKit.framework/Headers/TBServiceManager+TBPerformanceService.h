//
//  TBServiceManager+TBPerformanceService.h
//  TBBaseKit
//
//  Created by 秦晓强 on 2023/1/4.
//

#import "TBServiceManager.h"
#import <TBServiceProtocolKit/TBPerformanceComponentService.h>

NS_ASSUME_NONNULL_BEGIN

#define TBLOG_MAYBE_TYPE(logType, lvl, flg, fnct, frmt, ...) [TBService(TBPerformanceComponentService) tb_logMaybeType:logType level:lvl flag:flg func:fnct format:frmt, ##__VA_ARGS__]

// 开发埋点使用的宏
#define TB_DEVELOPERLOG(frmt, ...)               TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 1), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TB_DEVELOPERLOG_TYPE(logType, frmt, ...) TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 1), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

// 网络日志宏
#define TBLogNetwork(frmt, ...) TBLOG_MAYBE_TYPE(6, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 1), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogError(frmt, ...)     TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 0),   __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogWarn(frmt, ...)      TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 1), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogInfo(frmt, ...)      TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 2),    __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogDebug(frmt, ...)     TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 3),   __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogVerbose(frmt, ...)   TBLOG_MAYBE_TYPE(2, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 4), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogErrorType(logType, frmt, ...)   TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 0),   __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogWarnType(logType, frmt, ...)    TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 1), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogInfoType(logType, frmt, ...)    TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 2),    __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogDebugType(logType, frmt, ...)   TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 3),   __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define TBLogVerboseType(logType, frmt, ...) TBLOG_MAYBE_TYPE(logType, [TBService(TBPerformanceComponentService) tb_getTBLogLevel], (1 << 4), __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#ifdef DEBUG
    #define TBLog(fmt, ...)                                 TBLogDebug((fmt), ##__VA_ARGS__);
#else
    #define TBLog(fmt, ...)                                 TBLogInfo((fmt), ##__VA_ARGS__);
#endif

@interface TBServiceManager (TBPerformanceService)

@end

NS_ASSUME_NONNULL_END
