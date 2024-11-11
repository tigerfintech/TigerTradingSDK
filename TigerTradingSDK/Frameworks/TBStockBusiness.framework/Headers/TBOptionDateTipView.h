//
//  TBOptionDateTipView.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/9/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionDateTipView : UIView
@property(nonatomic, strong)UIColor *textColor;
@property(nonatomic, assign)BOOL useBlueUpRight;
- (void)setTitleText:(NSString *)text;

- (void)useLeftImg:(BOOL)useLeft;
@end

NS_ASSUME_NONNULL_END
