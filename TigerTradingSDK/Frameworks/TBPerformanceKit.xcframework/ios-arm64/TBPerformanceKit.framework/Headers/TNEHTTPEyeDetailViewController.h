//
//  TNEHTTPEyeDetailViewController.h
//  TigerNetworkEye
//
//  Created by donggongfu on 2021/12/29.
//  Copyright © 2021 Tiger Brokers. All rights reserved.
//

#import <UIKit/UIKit.h>

#define TIGER_TRADE 1

#ifdef TIGER_TRADE
#import <TBUIKit/TBBaseViewController.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class TNEHTTPModel;

#ifndef TIGER_TRADE
@interface TNEHTTPEyeDetailViewController : UIViewController
#else
@interface TNEHTTPEyeDetailViewController : TBBaseViewController
#endif

/**
 *  detail page's data model,about request,response and data
 */
@property (nonatomic, strong) TNEHTTPModel *model;

@end

NS_ASSUME_NONNULL_END
