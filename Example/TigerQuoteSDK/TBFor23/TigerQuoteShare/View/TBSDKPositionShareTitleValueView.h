//
//  TBSDKPositionShareTitleValueView.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/12.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface TBSDKPositionShareTitleValueView : UIView

@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, assign) NSInteger textColorValue;

@end

NS_ASSUME_NONNULL_END
