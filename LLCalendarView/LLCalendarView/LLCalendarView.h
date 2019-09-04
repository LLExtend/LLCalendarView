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
 若按月份计算最大支持36月
 若按天计算最大支持365
 */
@property (nonatomic ,assign) NSInteger endCount;

/**
 @required
 结束日期计算方式
 */
@property (nonatomic ,assign) LLEndCountType endCountType;

/**
 @optional
 是否开启 选中日期后自动dismiss defalut is NO
 */
@property (nonatomic ,assign) BOOL isOpenSelectedAutoDismiss;

/**
 @optional
 是否开启单选 defalut is NO|双选 YES|单选
 */
@property (nonatomic ,assign) BOOL isOpenSingleSelect;

/**
 @optional
 周六日字体颜色
 */
@property (nonatomic ,strong) UIColor *weekendTextColor;

/**
 @optional
 周一至周五字体颜色
 */
@property (nonatomic ,strong) UIColor *weeknormalTextColor;

/**
 @optional
 选中背景色
 */
@property (nonatomic ,strong) UIColor *selectedBackgroundColor;

/**
 @optional
 选择开始和结束日期的中间日期背景色
 */
@property (nonatomic ,strong) UIColor *selectedMiddleBackgroundColor;

/**
 @optional
 无点击日期字体颜色
 */
@property (nonatomic ,strong) UIColor *untouchTextColor;

/**
 @optional
 周六日字体
 */
@property (nonatomic ,strong) UIFont *weekendTextFont;

/**
 @optional
 周一至周五字体
 */
@property (nonatomic ,strong) UIFont *weeknormalTextFont;

/**
 @optional
 日历中 日期字体
 */
@property (nonatomic ,strong) UIFont *weekDayTextFont;

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
