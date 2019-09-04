//
//  LLCalendarModel.h
//  LLCalendarView
//
//  Created by Mac on 2019/7/31.
//  Copyright © 2019 zyl. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger ,LLCalendarDayState) {
    // 默认状态
    LLCalendarDayStateNormal = 0,
    // 选中状态
    LLCalendarDayStateSelect,
    // 开始状态（选中）
    LLCalendarDayStateSelectStart,
    // 结束状态（选中）
    LLCalendarDayStateSelectEnd,
    // 不可点击状态
    LLCalendarDayStateUntouch,
    // 失效状态（对应空白item）
    LLCalendarDayStateUnable
};

typedef NS_ENUM(NSInteger ,LLCalendarDayOfWeek) {
    //未知
    LLCalendarDayOfWeekUnknown = -1,
    // 周日
    LLCalendarDayOfWeekSunday = 0,
    // 周一
    LLCalendarDayOfWeekMonday,
    // 周二
    LLCalendarDayOfWeekTuesday,
    // 周三
    LLCalendarDayOfWeekWednesday,
    // 周四
    LLCalendarDayOfWeekThursday,
    // 周五
    LLCalendarDayOfWeekFriday,
    // 周六
    LLCalendarDayOfWeekSaturday
};


@interface LLCalendarDayModel : NSObject

/**
 当前日期
 */
@property (nonatomic ,strong) NSDate *date;

/**
 年
 */
@property (nonatomic ,assign) NSInteger year;

/**
 月
 */
@property (nonatomic ,assign) NSInteger month;

/**
 日
 */
@property (nonatomic ,assign) NSInteger day;

/**
 周几
 */
@property (nonatomic ,assign) LLCalendarDayOfWeek dayOfWeek;

/**
 item显示状态
 */
@property (nonatomic ,assign) LLCalendarDayState dayState;

@end

@interface LLCalendarMonthModel : NSObject

/**
 年
 */
@property (nonatomic ,assign) NSInteger year;

/**
 月
 */
@property (nonatomic ,assign) NSInteger month;

/**
 日
 */
@property (nonatomic ,assign) NSInteger day;
@property (nonatomic ,assign) NSInteger totalDays;

/**
 当月所有天数数组
 */
@property (nonatomic ,strong) NSMutableArray <LLCalendarDayModel *> *dayModels;
@end







NS_ASSUME_NONNULL_END
