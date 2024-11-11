//
//  TBCustomDefineTigerTradeColor.h
//  TBUIKit
//
//  Created by zhengzhiwen on 2021/5/25.
//

#import <Foundation/Foundation.h>
#import "TBCustomDefineColorProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCustomDefineTigerTradeColor : NSObject<TBCustomDefineColorProtocol>

- (UIColor *)yellowColor;
- (UIColor *)loginTitleColor;
- (UIColor *)buttonYellowBackgroundHighlightColor;
- (UIColor *)buttonGrayBackgroundTitleColor;
- (UIColor *)buttonGrayBackgroundImageColor;
- (UIColor *)segmentSelectedTextColor;
- (UIColor *)segmentNormalTextColor;
- (UIColor *)segmentSelectedBackColor;
- (UIColor *)segmentNormalBackColor;
- (UIColor *)segmentBorderColor;
- (UIColor *)segmentIOS13BGColor;
- (UIColor *)alertControllerContentBGColor;
- (UIColor *)alertControllerTitleColor;
- (UIColor *)alertControllerMessageColor;
- (UIColor *)cancelContinueButtonBorderColor;
- (UIColor *)commonTintColor;
- (UIColor *)checkBoxConfirmHintColor;
- (UIColor *)commonConfirmBGColor;
- (UIColor *)commonConfirmTitleColor;
- (UIColor *)commonConfirmCancelBorderColor;
- (UIColor *)commonConfirmCancelTitleColor;
- (UIColor *)commonConfirmConfirmButtonColor;
- (UIColor *)datePickerTextColor;
- (UIColor *)datePickerPlaceHolderColor;
- (UIColor *)messageBoxContentColor;
- (UIColor *)stringOptionCellTitleColor;
- (UIColor *)stringOptionCellSeparatorColor;
- (UIColor *)stringOptionCellCreateButtonColor;

@end

NS_ASSUME_NONNULL_END
