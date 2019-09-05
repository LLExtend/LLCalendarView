//
//  ViewController.m
//  LLCalendarView
//
//  Created by Mac on 2019/9/4.
//  Copyright © 2019 zyl. All rights reserved.
//

#import "ViewController.h"
#import "CalendarViewController.h"
#import "LLCalendarView/LLCalendarView.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *DayCountTextField;
@property (weak, nonatomic) IBOutlet UISegmentedControl *CalculateSegmentControl;
@property (weak, nonatomic) IBOutlet UISegmentedControl *SelectTypeSegmentControl;
@property (weak, nonatomic) IBOutlet UIButton *StartButton;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.DayCountTextField.keyboardType = UIKeyboardTypePhonePad;
    
    [self.StartButton addTarget:self action:@selector(StartButton:) forControlEvents:UIControlEventTouchUpInside];
    
}

- (void)StartButton:(UIButton *)button {
    
    CalendarViewController *vc = CalendarViewController.new;
    LLCalendarViewConfiguration *configuration = LLCalendarViewConfiguration.new;
    configuration.calculateRangeCount = self.DayCountTextField.text.integerValue;
    configuration.calculateRangeCountType = self.CalculateSegmentControl.selectedSegmentIndex==0 ? LLCalendarCalculateRangeCountTypeDay :LLCalendarCalculateRangeCountTypeMonth;
    configuration.isOpenSingleSelect = !self.SelectTypeSegmentControl.selectedSegmentIndex;
    
    configuration.weekendTextColor = UIColor.orangeColor;
    configuration.selectedBackgroundColor = [UIColor colorWithRed:42/255.0 green:134/255.0 blue:232/255.0 alpha:1];
    configuration.selectedMiddleBackgroundColor = [UIColor colorWithRed:.9 green:.9 blue:.9 alpha:1];
    
    if (configuration.isOpenSingleSelect) {
        configuration.startMarkString = @"出发";
    } else {
        configuration.startMarkString = @"入住";
        configuration.endMarkString = @"离店";
    }
    
    // 日 一 二 三 四 五 六 配置项
    LLCalendarWeekDayHeaderConfiguration weekDayHeaderStruct = LLCalendarWeekDayHeaderConfigurationMake(UIColor.orangeColor,
                                                                                                        UIColor.blackColor,
                                                                                                        [UIFont systemFontOfSize:16],
                                                                                                        [UIFont systemFontOfSize:16]);
    weekDayHeaderStruct.weekDayHeaderBackgroundColor = [UIColor colorWithRed:250/255.0f green:250/255.0f blue:250/255.0f alpha:1];
    configuration.weekDayHeaderConfiguration = weekDayHeaderStruct;
    
    // 悬停年月 配置项
    LLCalendarSectionHeaderConfiguration sectionHeaderConfiguration = LLCalendarSectionHeaderConfigurationMake(UIColor.blueColor, nil, [UIFont boldSystemFontOfSize:18]);
    configuration.sectionHeaderConfiguration = sectionHeaderConfiguration;
    
    vc.configuration = configuration;
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [UIApplication.sharedApplication.delegate.window endEditing:YES];
}


@end
