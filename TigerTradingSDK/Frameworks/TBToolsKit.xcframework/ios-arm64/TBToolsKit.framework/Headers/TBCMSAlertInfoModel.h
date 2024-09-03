//
//  TBCMSAlertInfoModel.h
//  Stock
//
//  Created by JustLee on 2020/7/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCMSAlertInfoModel : TBBaseModel

@property (nonatomic, copy) NSString *gid;
@property (nonatomic, copy) NSString *show_type;
@property (nonatomic, copy) NSArray <NSString *> *promotion_position;
@property (nonatomic, copy) NSArray <NSString *> *deposit_status;
@property (nonatomic, copy) NSArray <NSString *> *push_account;
@property (nonatomic, copy) NSArray <NSString *> *platform;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSArray <NSString *> *symbols;// 指定所在标的详情页

/**
  promotion_position参数定义
 '1': '自选',
 '2': '个股详情页-美股',
 '3': '个股详情页-港股',
 '4': '个股详情页-沪深',
 '5': '个股详情页-伦敦',
 '6': '个股详情页-新加坡',
 '7': '个股详情页-澳大利亚',
 '8': '个股详情页-期货',
 '9': '市场-美股',
 '10': '市场-港股',
 '11': '市场-沪深',
 '12': '市场-伦敦',
 '13': '市场-新加坡',
 '14': '市场-期货',
 '15': '下单页',
 '16': '改单页',
 '17': '持仓页',
 '18': '资产页',
 '19': '订单页'
 
 deposit_status
 入金状态
 '1': '未开户',
 '2': '开户未入金',
 '3': '已入金'
 
 push_account
 推送账号

 '1': '环球-FD',
 '2': '环球-ND',
 '3': '综合',
 
 */

@end

NS_ASSUME_NONNULL_END
