//
//  TBPlaceOrderCheckAlertModel.h
//  Stock
//
//  Created by zhengzhiwen on 2021/3/10.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TTHeader.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderCheckAlertModel : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSDictionary *links;
@property (nonatomic, assign) BOOL checkbox;
@property (nonatomic, copy) NSString *checkboxText;
@property (nonatomic, copy) NSString *cancelTitle;
@property (nonatomic, copy) NSString *confirmTitle;
@property (nonatomic, strong) TTURLAction *urlAction;
@property (nonatomic, copy) void(^completion)(void);
@property (nonatomic, copy) void(^linkBlock)(NSURL *url);

@end

NS_ASSUME_NONNULL_END
