//
//  TBPopView.h
//  Stock
//
//  Created by dull grass on 2019/11/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TBPopTypeDirection) {
    TBPopTypeDirectionUp,
    TBPopTypeDirectionDown,
};

typedef void (^TBPopBlock) (NSInteger index);
NS_ASSUME_NONNULL_BEGIN

@interface TBPopView : UIControl

@property (nonatomic, strong) UIView *exchangeView;

- (void)showWithFrame:(CGRect )frame
           anglePoint:(CGPoint )anglePoint
       arrowDirection:(TBPopTypeDirection)arrowDirection
            doneBlock:(nullable TBPopBlock)doneBlock;


@end


@interface TBPopMenu : NSObject

+ (void) showForSender:(UIView *)sender
              withView:(TBPopView *)view
             doneBlock:(nullable TBPopBlock)doneBlock;

+ (void)dismiss;


@end

NS_ASSUME_NONNULL_END
