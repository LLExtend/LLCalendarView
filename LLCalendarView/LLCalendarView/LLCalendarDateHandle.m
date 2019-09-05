//
//  LLCalendarDateHandle.m
//  LLCalendarView
//
//  Created by Mac on 2019/7/31.
//  Copyright © 2019 zyl. All rights reserved.
//

#import "LLCalendarDateHandle.h"

@implementation LLCalendarDateHandle

/**
 获取当前日期
 
 @return 当前日期
 */
+ (NSDate *)currentDate {
    // 得到当前时间（世界标准时间 UTC/GMT）
    NSDate *date = [NSDate date];
    // 设置系统时区为本地时区
    NSTimeZone *zone = [NSTimeZone systemTimeZone];
    // 计算本地时区与 GMT 时区的时间差
    NSInteger interval = [zone secondsFromGMT];
    // 在 GMT 时间基础上追加时间差值，得到本地时间
    date = [date dateByAddingTimeInterval:interval];
    return date;
}

/**
 生成日期
 
 @param year 年-2019
 @param month 月-08
 @param day 日-01
 @return 日期2019-08-01 00:00:00 UTC
 */
+ (NSDate *)dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day {
    if (year <= 0 ||
        month <= 0 ||
        day <= 0) {
        return nil;
    }
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setTimeZone:[NSTimeZone timeZoneWithAbbreviation:@"UTC"]];
    [formatter setDateFormat:@"YYYYMMdd"];
    return [formatter dateFromString:[NSString stringWithFormat:@"%ld%02ld%02ld",year,month,day]];
}

/**
 当前日期 是周几
 
 @param date 传入日期
 @return 周几 0|周日 1|周一 2|周二 3|周三 4|周四 5|周五 6|周六
 */
+ (NSInteger)weekDayForDate:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSUInteger unitFlags = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitWeekday;
    NSDateComponents *components = [calendar components:unitFlags fromDate:date];
    
    return components.weekday - 1;
}

/**
 比较compareDate 是否在startDate和endDate之间（不包含startDate和endDate）
 
 @param startDate 开始日期
 @param endDate 结束日期
 @param compareDate 比对日期
 @return 结果BOOL
 */
+ (BOOL)compareStartDate:(NSDate *)startDate endDate:(NSDate *)endDate compareDate:(NSDate *)compareDate {
    NSInteger ss = [self compareOriginDate:startDate compareDate:compareDate];
    
    NSInteger ee = [self compareOriginDate:endDate compareDate:compareDate];
    
    if (ss == 1 && ee == -1) {
        return YES ;
    }
    return NO;
}

/**
 日期比较
 
 @param originDate 原始日期
 @param compareDate 比对日期
 @return 1|compareDate 比 originDate 大 、 0|compareDate = originDate -1 、-1|compareDate 比 originDate 小
 */
+ (NSInteger)compareOriginDate:(NSDate *)originDate compareDate:(NSDate *)compareDate {
    NSInteger sort = 0;
    NSComparisonResult result = [originDate compare:compareDate];
    switch (result) {
            
        // compareDate 比 originDate 大
        case NSOrderedAscending:
            sort = 1;
            break;
            
        // compareDate 比 originDate 小
        case NSOrderedDescending:
            sort = -1;
            break;
            
        // compareDate = originDate
        case NSOrderedSame:
            sort = 0;
            break;
            
        default:
            NSLog(@"erorr dates %@, %@", originDate, compareDate);
            break;
    }
    return sort;
}

/**
 计算两个日期之间的天数
 
 @param beginDate 开始日期
 @param endDate 结束日期
 @return 天数
 */
+ (NSInteger)calculateDaysFromStartDate:(NSDate *)beginDate endDate:(NSDate *)endDate {
    //创建日期格式化对象
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"YYYY-MM-dd HH:mm"];
    
    //取两个日期对象的时间间隔：
    NSTimeInterval time = [endDate timeIntervalSinceDate:beginDate];
    
    NSInteger days = ((NSInteger)time) / (3600 * 24);
    
    return days;
}

/**
 获取当前日期所在月份共有多少天
 
 @param date 当前日期
 @return 天数
 */
+ (NSInteger)totaldaysInMonth:(NSDate *)date {
    NSRange daysInLastMonth = [[NSCalendar currentCalendar] rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:date];
    return daysInLastMonth.length;
}

@end
