//
//  TBCustomDefineColorProtocol.h
//  TBUIKit
//
//  Created by zhengzhiwen on 2021/5/25.
//

#ifndef TBCustomDefineColorProtocol_h
#define TBCustomDefineColorProtocol_h

@protocol TBCustomDefineColorProtocol <NSObject>

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

#endif /* TBCustomDefineColorProtocol_h */
