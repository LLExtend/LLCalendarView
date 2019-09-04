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
    configuration.endCount = self.DayCountTextField.text.integerValue;
    configuration.endCountType = self.CalculateSegmentControl.selectedSegmentIndex==0 ? LLEndCountTypeDay :LLEndCountTypeMonth;
    configuration.isOpenSingleSelect = !self.SelectTypeSegmentControl.selectedSegmentIndex;
    
    configuration.selectedBackgroundColor = [UIColor colorWithRed:42/255.0 green:134/255.0 blue:232/255.0 alpha:1];
    configuration.weekendTextColor = UIColor.orangeColor;
    configuration.selectedMiddleBackgroundColor = [UIColor colorWithRed:.9 green:.9 blue:.9 alpha:1];
    vc.configuration = configuration;
    
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
    
    
    
//    LLCalendarView *calendarView = [[LLCalendarView alloc] initWithFrame:UIScreen.mainScreen.bounds];
//    [self.view addSubview:calendarView];
//
//    LLCalendarViewConfiguration *configuration = LLCalendarViewConfiguration.new;
//    configuration.endCount = 365;
//    configuration.endCountType = LLEndCountTypeDay;
//    configuration.isOpenSingleSelect = NO;
//
//    configuration.selectedBackgroundColor = [UIColor colorWithRed:42/255.0 green:134/255.0 blue:232/255.0 alpha:1];
//    configuration.weekendTextColor = UIColor.orangeColor;
//    configuration.selectedMiddleBackgroundColor = [UIColor colorWithRed:.9 green:.9 blue:.9 alpha:1];
//    calendarView.configuration = configuration;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [UIApplication.sharedApplication.delegate.window endEditing:YES];
}


@end
