//
//  TBThirdLevelSegmentView.h
//  Stock
//
//  Created by zhenglanchun on 2021/6/4.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBThirdLevelSegmentView : UIView

@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy) NSArray <NSString *> *titles;

@property (nonatomic, copy) void(^segmentChangedBlock)(NSInteger indqex);

- (void)changeAppColorStyle;

+ (CGFloat)viewHeight;

@end

NS_ASSUME_NONNULL_END
