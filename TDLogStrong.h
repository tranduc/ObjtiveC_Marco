//
//  TDLogStrong.h
//  TDLogTest
//
//  Created by tranduc on 3/8/13.
//  Copyright (c) 2013 tranduc. All rights reserved.
//

#ifndef TDLog_TDLogStrong_h
#define TDLog_TDLogStrong_h

#pragma mark -
//=============================================
// MARK: Disable Log in release Mode
// Import this file in to <Project>-Prefix.pch
// and set TDLOG_RELEASE_DISABLE 1 to disable all log
// in release mode
//=============================================

#define TDLOG_RELEASE_DISABLE 1

#if TDLOG_RELEASE_DISABLE

    #ifdef NDEBUG
    #define NSLog(...) /* suppress NSLog when in release mode */
    #endif

#endif

//=============================================
//MARK: Strong Disable log
/*Only set TDLOG_DISABLE_STRONG 1 to disable all TDLOG and NSLog.
  Add this header to <Project>-Prefix.pch to disable log
  for every where in project.
//*/
//=============================================
#define TDLOG_DISABLE_STRONG 0

#if TDLOG_DISABLE_STRONG
    #define NSLog(...) /* suppress NSLog */
#endif //end StrongDisableLog


#pragma mark -
//=============================================
// MARK: Weak log
//=============================================

#define TDLOG_WEAK 1
/*
 * if TDLOG_WEAK is not defined, or if it is 0 then
 *	all TDLOGXXX macros will be disabled
 *
 * if TDLOG_WEAK ==1 then:
 *		TDLOG() will be enabled
 *		TDLOGERROR() will be enabled
 *		TDLOGINFO()	will be disabled
 *
 * if TD_DEBUG==2 or higher then:
 *		TDLOG() will be enabled
 *		TDLOGERROR() will be enabled
 *		TDLOGINFO()	will be enabled
 */
#if !defined(TDLOG_WEAK) || TDLOG_WEAK == 0
    #define TDLOG(...) do {} while (0)
    #define TDLOGINFO(...) do {} while (0)
    #define TDLOGERROR(...) do {} while (0)

#elif TDLOG_WEAK == 1
    #define TDLOG(...) NSLog(__VA_ARGS__)
    #define TDLOGERROR(...) NSLog(__VA_ARGS__)
    #define TDLOGINFO(...) do {} while (0)

#else
    #define TDLOG(...) NSLog(__VA_ARGS__)
    #define TDLOGERROR(...) NSLog(__VA_ARGS__)
    #define TDLOGINFO(...) NSLog(__VA_ARGS__)
#endif // end TDLOG_WEAK


//===============================================
// MARK: Log Function Name
//===============================================

//Log only function name
#define TDLOGFUNC() TDLOG(@"%@::%@",self,NSStringFromSelector(_cmd))

//Log funtion name with separater
#define TDLOGFUNC_SEP() TDLOG(@"==========\n%@::%@",self,NSStringFromSelector(_cmd))

//Log function with string
#define TDLOGFUNC_STR(str) TDLOG(@"%@::%@ %@",self,NSStringFromSelector(_cmd), (str))

//Other way to log function name
#define TDLOGFUNC_C() TDLOG(@"%s: %@", __func__, self); // End Log function name

#pragma mark -
//==================================================
// MARK: Log Point, Rect - Helper
//==================================================
#define cgp(X,Y) CGPointMake((X),(Y))
#define cgr(x,y,w,h) CGRectMake((x),(y),(w),(h))

#define TDLOGRect(str, f) TDLOG(@"%@(x=%.2f, y=%.2f, w=%.2f, h=%.2f)", (str), (f).origin.x, (f).origin.y, (f).size.width, (f).size.height)
#define TDLOGPoint(str, p) TDLOG(@"%@(x=%.2f, y=%.2f)", (str), (p).x, (p).y)


#endif
