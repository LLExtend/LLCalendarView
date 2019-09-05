//
//  CalendarViewController.m
//  LLCalendarView
//
//  Created by Mac on 2019/9/4.
//  Copyright © 2019 zyl. All rights reserved.
//

#import "CalendarViewController.h"

#import "LLCalendarView/LLCalendarView.h"

@interface CalendarViewController ()

@property (nonatomic ,strong) LLCalendarView *calendarView;

@end

@implementation CalendarViewController

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
    self.calendarView.frame = self.view.bounds;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = UIColor.whiteColor;
    self.title = @"日历";
    UIBarButtonItem *bar = [[UIBarButtonItem alloc] initWithTitle:@"关闭" style:UIBarButtonItemStylePlain target:self action:@selector(dismiss)];
    
    self.navigationItem.leftBarButtonItem = bar;

    self.navigationController.navigationBar.translucent = NO;
    self.calendarView = [[LLCalendarView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:self.calendarView];
   
    self.calendarView.configuration = self.configuration;
    
    self.calendarView.finishSelectBlock = ^(NSArray<LLCalendarDayModel *> * _Nonnull selectedDates) {
        NSLog(@"finishSelectBlock %@",selectedDates);
    };
}


- (void)dismiss {
    
    NSLog(@"selectedDates %@",self.calendarView.selectedDates);
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
