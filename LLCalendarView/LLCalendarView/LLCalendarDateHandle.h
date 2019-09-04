//
//  LLCalendarDateHandle.h
//  LLCalendarView
//
//  Created by Mac on 2019/7/31.
//  Copyright © 2019 zyl. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LLCalendarDateHandle : NSObject

/**
 获取当前日期

 @return 当前日期
 */
+ (NSDate *)currentDate;

/**
 生成日期

 @param year 年-2019
 @param month 月-08
 @param day 日-01
 @return 日期2019-08-01 00:00:00 UTC
 */
+ (NSDate *)dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day ;

/**
 当前日期 是周几

 @param date 传入日期
 @return 周几 0|周日 1|周一 2|周二 3|周三 4|周四 5|周五 6|周六
 */
+ (NSInteger)weekDayForDate:(NSDate *)date ;

/**
 比较compareDate 是否在startDate和endDate之间（不包含startDate和endDate）

 @param startDate 开始日期
 @param endDate 结束日期
 @param compareDate 比对日期
 @return 结果BOOL
 */
+ (BOOL)compareStartDate:(NSDate *)startDate endDate:(NSDate *)endDate compareDate:(NSDate *)compareDate;

/**
 日期比较

 @param originDate 原始日期
 @param compareDate 比对日期
 @return 1|compareDate 比 originDate 大 、 0|compareDate = originDate -1 、-1|compareDate 比 originDate 小
 */
+ (NSInteger)compareOriginDate:(NSDate *)originDate compareDate:(NSDate *)compareDate;

/**
 计算两个日期之间的天数

 @param beginDate 开始日期
 @param endDate 结束日期
 @return 天数
 */
+ (NSInteger)calculateDaysFromStartDate:(NSDate *)beginDate endDate:(NSDate *)endDate;

/**
 获取当前日期所在月份共有多少天

 @param date 当前日期
 @return 天数
 */
+ (NSInteger)totaldaysInMonth:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
