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

typedef NS_ENUM(NSInteger ,LLEndCountType) {
    // 按月计算
    LLEndCountTypeMonth = 0 ,
    // 按天计算
    LLEndCountTypeDay
};

@interface LLCalendarViewConfiguration : NSObject

/**
 @required
 日历结束日期数量
 */
@property (nonatomic ,assign) NSInteger endCount;

/**
 @required
 结束日期计算方式
 */
@property (nonatomic ,assign) LLEndCountType endCountType;

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

/************************ 👉section View 属性设置👈 ************************/
/**
 @optional
 悬停section View 字体颜色
 */
@property (nonatomic ,strong) UIColor *sectionMonthTextColor;

/**
 @optional
 悬停section View 背景颜色
 */
@property (nonatomic ,strong) UIColor *sectionMonthBackgroundColor;

/**
 @optional
 悬停section View 字体
 */
@property (nonatomic ,strong) UIFont *sectionMonthTextFont;

/************************ 👉weekDayView 属性设置👈 ************************/
/**
 @optional
 @[@"日",@"一",@"二",@"三",@"四",@"五",@"六"];
 周六日 字体颜色
 */
@property (nonatomic ,strong) UIColor *weekendTitleTextColor;

/**
 @optional
 @[@"日",@"一",@"二",@"三",@"四",@"五",@"六"];
 周一-周五 字体颜色
 */
@property (nonatomic ,strong) UIColor *weekDayTitleTextColor;

/**
 @optional
 @[@"日",@"一",@"二",@"三",@"四",@"五",@"六"];
 周六日 字体
 */
@property (nonatomic ,strong) UIFont *weekendTitleTextFont;

/**
 @optional
 @[@"日",@"一",@"二",@"三",@"四",@"五",@"六"];
 周一-周五 字体
 */
@property (nonatomic ,strong) UIFont *weekDayTitleTextFont;

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
