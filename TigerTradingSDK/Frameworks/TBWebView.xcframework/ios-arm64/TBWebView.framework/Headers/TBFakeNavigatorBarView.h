//
//  TBFakeNavigatorBarView.h
//  Stock
//
//  Created by 王昌阳 on 2020/5/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBFakeNavigatorBarOptions) {
    TBFakeNavigatorBarOptionsBack  = 1 << 0,
    TBFakeNavigatorBarOptionsClose = 1 << 1,
    TBFakeNavigatorBarOptionsTitle = 1 << 2,
};


NS_ASSUME_NONNULL_BEGIN

@interface TBFakeNavigatorBarView : UIView

@property (nonatomic, copy) dispatch_block_t backActionBlock;///< 关闭按钮
@property (nonatomic, copy) dispatch_block_t dismissActionBlock;///< 关闭按钮

@property (nonatomic, copy) NSString *title;///< 标题

- (instancetype)initWithOptions:(TBFakeNavigatorBarOptions)options;

- (void)changeAppColorStyle;
@end

NS_ASSUME_NONNULL_END
