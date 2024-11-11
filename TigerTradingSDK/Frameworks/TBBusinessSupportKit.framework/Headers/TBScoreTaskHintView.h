//
//  TBScoreTaskHintView.h
//  Stock
//
//  Created by chenxin on 2019/7/1.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBScoreTaskHintView : UIView

@property (nonatomic, copy) NSString *hint;
@property (nonatomic, copy) NSString *btnTitle;
@property (nonatomic, strong) void(^buttonBlock)(void);

- (instancetype)initWithHint:(NSString *)hint btnTitle:(NSString *)btnTitle buttonBlock:(void(^)(void))buttonBlock;

@end

NS_ASSUME_NONNULL_END

