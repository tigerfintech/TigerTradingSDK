//
//  TBTestFlightUpgradeModel.h
//  Stock
//
//  Created by chenxin on 2020/11/19.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTestFlightUpgradeModel : JSONModel

@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *titleCN;
@property (nonatomic, copy) NSString *messageCN;
@property (nonatomic, copy) NSString *titleEN;
@property (nonatomic, copy) NSString *messageEN;
@property (nonatomic, copy) NSString *titleTW;
@property (nonatomic, copy) NSString *messageTW;
@property (nonatomic, copy) NSString *btnTitleCN;
@property (nonatomic, copy) NSString *btnTitleEN;
@property (nonatomic, copy) NSString *btnTitleTW;

@end

NS_ASSUME_NONNULL_END
