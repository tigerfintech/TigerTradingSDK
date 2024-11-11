//
//  TBCollegeRequestManager.h
//  Stock
//
//  Created by chenxin on 2019/6/5.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

@interface TBCollegeRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBCollegeRequestManager)

/*
 在一些说明页展示学院的链接，key为name和url
 */
@property (nonatomic, copy) NSDictionary *riskStock; // 显示在风控值说明页的链接
@property (nonatomic, copy) NSDictionary *assetsStock; // 显示在证券账户说明页的链接
@property (nonatomic, copy) NSDictionary *assetsFutures; // 显示在期货账户说明页的链接
@property (nonatomic, copy) NSDictionary *fundamentalStock; // 显示在个股基本面信息说明页的链接

- (void)fetchCollegeExposure;

@end
