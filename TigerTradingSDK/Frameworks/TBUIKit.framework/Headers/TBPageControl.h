//
//  TBPageControl.h
//  Stock
//
//  Created by chenxin on 2019/5/15.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBPageControl : UIControl

@property(nonatomic) NSInteger numberOfPages;
@property(nonatomic) NSInteger currentPage;

@property(nonatomic) BOOL hidesForSinglePage;

@property(nonatomic, strong) UIColor *currentIndexColor;
@property(nonatomic, strong) UIColor *otherIndexColor;
@property(nonatomic, strong) NSNumber *indicatorHeight;
@property(nonatomic, strong) NSNumber *currentIndexWidth;
@property(nonatomic, strong) NSNumber *otherIndexWidth;

- (void)updateIndicatorColor;

@end
