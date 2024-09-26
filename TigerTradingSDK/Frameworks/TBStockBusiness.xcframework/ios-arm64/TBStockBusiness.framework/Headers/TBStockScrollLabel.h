//
//  TBStockScrollLabel.h
//  scroll
//
//  Created by 王灵博 on 2020/7/13.
//  Copyright © 2020 Tiger. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockScrollLabel : UIView

@property (nonatomic, copy) NSArray *dataArr;
@property (nonatomic, strong) UILabel *currentLabel;
@property (nonatomic, strong) UILabel *nextLabel;
@property (nonatomic, copy) void (^(selectIndex))(NSInteger index);

- (void)invalidateTimer;

@end

NS_ASSUME_NONNULL_END
