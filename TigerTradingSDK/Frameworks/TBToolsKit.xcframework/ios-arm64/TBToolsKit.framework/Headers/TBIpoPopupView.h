//
//  TBIpoPopupView.h
//  TBToolsKit
//
//  Created by dulijun on 2023/6/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TBPopupsSymbolInfoModel;

@interface TBIpoPopupView : UIView

- (instancetype)initWithSymbolsArray:(NSArray<TBPopupsSymbolInfoModel *> *)symbolsArray type:(NSString *)type width:(CGFloat)width;

@end

NS_ASSUME_NONNULL_END
