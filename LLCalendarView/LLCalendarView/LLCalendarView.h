//
//  LLCalendarView.h
//  LLCalendarView
//
//  Created by Mac on 2019/7/31.
//  Copyright © 2019 zyl. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class LLCalendarDayModel;

typedef NS_ENUM(NSInteger ,LLCalendarCalculateRangeCountType) {
    // 按月计算
    LLCalendarCalculateRangeCountTypeMonth = 0 ,
    // 按天计算
    LLCalendarCalculateRangeCountTypeDay
};

typedef struct {
    //周六日 字体颜色
    UIColor * _Nullable weekendHeaderTextColor;
    //周一-周五 字体颜色
    UIColor * _Nullable weekDayHeaderTextColor;
    //周六日 字体
    UIFont * _Nullable weekendHeaderTextFont;
    //周一-周五 字体
    UIFont * _Nullable weekDayHeaderTextFont;
    //背景色
    UIColor * _Nullable weekDayHeaderBackgroundColor;
} LLCalendarWeekDayHeaderConfiguration;

typedef struct {
    UIColor * _Nullable sectionHeaderTextColor;
    UIColor * _Nullable sectionHeaderBackgroundColor;
    UIFont * _Nullable sectionHeaderTextFont;
} LLCalendarSectionHeaderConfiguration;

CG_INLINE LLCalendarWeekDayHeaderConfiguration
LLCalendarWeekDayHeaderConfigurationMake(UIColor * _Nullable weekendHeaderTextColor, UIColor * _Nullable weekDayHeaderTextColor, UIFont * _Nullable weekendHeaderTextFont, UIFont * _Nullable weekDayHeaderTextFont)
{
    LLCalendarWeekDayHeaderConfiguration headerConfiguration;
    headerConfiguration.weekendHeaderTextColor = weekendHeaderTextColor;
    headerConfiguration.weekDayHeaderTextColor = weekDayHeaderTextColor;
    headerConfiguration.weekendHeaderTextFont = weekendHeaderTextFont;
    headerConfiguration.weekDayHeaderTextFont = weekDayHeaderTextFont;
    return headerConfiguration;
}

CG_INLINE LLCalendarSectionHeaderConfiguration
LLCalendarSectionHeaderConfigurationMake(UIColor * _Nullable sectionHeaderTextColor, UIColor * _Nullable sectionHeaderBackgroundColor, UIFont * _Nullable sectionHeaderTextFont)
{
    LLCalendarSectionHeaderConfiguration sectionHeaderConfiguration;
    sectionHeaderConfiguration.sectionHeaderTextFont = sectionHeaderTextFont;
    sectionHeaderConfiguration.sectionHeaderTextColor = sectionHeaderTextColor;
    sectionHeaderConfiguration.sectionHeaderBackgroundColor = sectionHeaderBackgroundColor;
    return sectionHeaderConfiguration;
}

@interface LLCalendarViewConfiguration : NSObject

/**
 @required
 计算日期范围数量
 */
@property (nonatomic ,assign) NSInteger calculateRangeCount;

/**
 @required
 日历日期范围计算方式
 */
@property (nonatomic ,assign) LLCalendarCalculateRangeCountType calculateRangeCountType;

/**
 @optional
 是否开启单选 defalut is NO|双选 YES|单选
 */
@property (nonatomic ,assign) BOOL isOpenSingleSelect;

/**
 @optional
 选中日期背景色
 */
@property (nonatomic ,strong) UIColor *selectedBackgroundColor;

/**
 @optional
 选择开始和结束日期的中间日期背景色
 */
@property (nonatomic ,strong) UIColor *selectedMiddleBackgroundColor;

/**
 @optional
 不可点击状态日期字体颜色
 */
@property (nonatomic ,strong) UIColor *untouchTextColor;

/**
 @optional
 周六日日期字体颜色
 */
@property (nonatomic ,strong) UIColor *weekendTextColor;

/**
 @optional
 周一至周五日期字体颜色
 */
@property (nonatomic ,strong) UIColor *weeknormalTextColor;

/**
 @optional
 周六日日期字体
 */
@property (nonatomic ,strong) UIFont *weekendTextFont;

/**
 @optional
 周一至周日期五字体
 */
@property (nonatomic ,strong) UIFont *weeknormalTextFont;

/**
 @optional
 日历中 日期字体
 */
@property (nonatomic ,strong) UIFont *weekDayTextFont;

/**
 @optional
 开始日期标记文案
 */
@property (nonatomic ,copy) NSString *startMarkString;

/**
 @optional
 结束日期标记文案
 */
@property (nonatomic ,copy) NSString *endMarkString;

/************************ 👉Calendar Section Header 属性设置👈 ************************/
@property (nonatomic ,assign) LLCalendarSectionHeaderConfiguration sectionHeaderConfiguration;

/************************ 👉CalendarWeekDayHeader 属性设置👈 ************************/
@property (nonatomic ,assign) LLCalendarWeekDayHeaderConfiguration weekDayHeaderConfiguration;

@end


@interface LLCalendarView : UIView

/**
 日历配置项
 */
@property (nonatomic ,strong) LLCalendarViewConfiguration *configuration;

/**
 选中日期数据
 */
@property (nonatomic ,strong ,readonly) NSArray <LLCalendarDayModel *> *selectedDates;

/**
 选择完成后回调
 */
@property (nonatomic ,copy) void (^finishSelectBlock) (NSArray <LLCalendarDayModel *> *selectedDates);


@end

NS_ASSUME_NONNULL_END
