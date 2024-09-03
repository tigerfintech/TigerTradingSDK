//
//  TBHtmlMessageBox.h
//  Stock
//
//  Created by yangfan on 2019/9/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBMessageBox.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHtmlMessageBox : TBMessageBox

@property (nonatomic, copy) void(^didTappedLinkBlock)(NSString * url);

@end

NS_ASSUME_NONNULL_END
