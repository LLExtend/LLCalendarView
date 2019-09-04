//
//  CalendarViewController.h
//  LLCalendarView
//
//  Created by Mac on 2019/9/4.
//  Copyright © 2019 zyl. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class LLCalendarViewConfiguration;

@interface CalendarViewController : UIViewController

@property (nonatomic ,strong) LLCalendarViewConfiguration *configuration;

@end

NS_ASSUME_NONNULL_END
