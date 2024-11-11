//
//  TBOptionSliderView.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/12/14.
//

#import <UIKit/UIKit.h>
@class TBOptionDetailIVIndexModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionSliderView : UIView
@property(nonatomic, assign) BOOL loadData;
@property(nonatomic, copy) NSArray <TBOptionDetailIVIndexModel *> * ivIndexArray;
@property(nonatomic, copy) void (^block)(double leftTime,double rightTime,CGFloat centerX,BOOL useLeft,BOOL isDefault);
@property(nonatomic, copy) void (^blockPan)(UIPanGestureRecognizer *panGe,UIGestureRecognizerState state);
- (void)setDefaultValues;
@end

NS_ASSUME_NONNULL_END
