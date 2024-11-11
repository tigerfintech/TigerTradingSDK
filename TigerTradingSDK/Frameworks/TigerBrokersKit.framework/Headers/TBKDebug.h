//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * TigerBrokersKit Debugging tools.
 *
 * Provided in this header are a set of debugging tools. This is meant quite literally, in that
 * all of the macros below will only function when the DEBUG preprocessor macro is specified.
 *
 * TBKDEBUGASSERT(<statement>);
 * If <statement> is false, the statement will be written to the log and if you are running in
 * the simulator with a debugger attached, the app will break on the assertion line.
 *
 * TBKDEBUGPRINT(@"formatted log text %d", param1);
 * Print the given formatted text to the log.
 *
 * TBKDEBUGPRINTMETHODNAME();
 * Print the current method name to the log.
 *
 * TBKDEBUGCONDITIONLOG(<statement>, @"formatted log text %d", param1);
 * If <statement> is true, then the formatted text will be written to the log.
 *
 * TBKDEBUGINFO/TBKDEBUGWARNING/TBKDEBUGERROR(@"formatted log text %d", param1);
 * Will only write the formatted text to the log if TBKMAXLOGLEVEL is greater than the respective
 * TTD* method's log level. See below for log levels.
 *
 * The default maximum log level is TBKLOGLEVEL_WARNING.
 */

#define TBKLOGLEVEL_INFO     5
#define TBKLOGLEVEL_WARNING  3
#define TBKLOGLEVEL_ERROR    1

#ifndef TBKMAXLOGLEVEL
#define TBKMAXLOGLEVEL TBKLOGLEVEL_WARNING
#endif

// The general purpose logger. This ignores logging levels.
#ifdef DEBUG
#define TBKDEBUGPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define TBKDEBUGPRINT(xx, ...)  ((void)0)
#endif // #ifdef DEBUG

// Prints the current method's name.
#define TBKDEBUGPRINTMETHODNAME() TBKDEBUGPRINT(@"%s", __PRETTY_FUNCTION__)

// Debug-only assertions.
#ifdef DEBUG

#import <TargetConditionals.h>

#if TARGET_IPHONE_SIMULATOR

#ifdef __cplusplus
extern "C" __attribute__ ((visibility ("default"))) int TBKIsInDebugger();
#else
int TBKIsInDebugger(void);
#endif

// We leave the __asm__ in this macro so that when a break occurs, we don't have to step out of
// a "breakInDebugger" function.
#if defined(__aarch64__)
#define TBKDEBUGASSERT(xx) { if (!(xx)) { TBKDEBUGPRINT(@"TBKDEBUGASSERT failed: %s", #xx); \
if (TBKIsInDebugger()) { asm(".inst 0xd4200000"); }; } \
} ((void)0)
#else
#define TBKDEBUGASSERT(xx) { if (!(xx)) { TBKDEBUGPRINT(@"TBKDEBUGASSERT failed: %s", #xx); \
if (TBKIsInDebugger()) { asm("int $3\n" : : ); }; } \
} ((void)0)
#endif // #if defined(__aarch64__)

#else
#define TBKDEBUGASSERT(xx) { if (!(xx)) { TBKDEBUGPRINT(@"TBKDEBUGASSERT failed: %s", #xx); } } ((void)0)
#endif // #if TARGET_IPHONE_SIMULATOR

#else
#define TBKDEBUGASSERT(xx) ((void)0)
#endif // #ifdef DEBUG

// Log-level based logging macros.
#if TBKLOGLEVEL_ERROR <= TBKMAXLOGLEVEL
#define TBKDEBUGERROR(xx, ...)  TBKDEBUGPRINT(xx, ##__VA_ARGS__)
#else
#define TBKDEBUGERROR(xx, ...)  ((void)0)
#endif // #if TBKLOGLEVEL_ERROR <= TBKMAXLOGLEVEL

#if TBKLOGLEVEL_WARNING <= TBKMAXLOGLEVEL
#define TBKDEBUGWARNING(xx, ...)  TBKDEBUGPRINT(xx, ##__VA_ARGS__)
#else
#define TBKDEBUGWARNING(xx, ...)  ((void)0)
#endif // #if TBKLOGLEVEL_WARNING <= TBKMAXLOGLEVEL

#if TBKLOGLEVEL_INFO <= TBKMAXLOGLEVEL
#define TBKDEBUGINFO(xx, ...)  TBKDEBUGPRINT(xx, ##__VA_ARGS__)
#else
#define TBKDEBUGINFO(xx, ...)  ((void)0)
#endif // #if TBKLOGLEVEL_INFO <= TBKMAXLOGLEVEL

#ifdef DEBUG
#define TBKDEBUGCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
TBKDEBUGPRINT(xx, ##__VA_ARGS__); \
} \
} ((void)0)
#else
#define TBKDEBUGCONDITIONLOG(condition, xx, ...) ((void)0)
#endif // #ifdef DEBUG
