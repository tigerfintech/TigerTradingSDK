//
//  TBFuturesContractModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/4.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBFuturesDefinetions.h"
#import <TBBaseKit/TBBaseModel.h>
#import "TBDecimal.h"
NS_ASSUME_NONNULL_BEGIN

@class TBDecimal;
@class TBFuturesCategoryModel;
@class TBFuturesExchangeModel;
@class TBFuturesContractDescriptionModel;
@class TBFuturesProductPriceConfigsModel;
@class TBFuturesContractTradingTimeModel;
@class TBFuturesContractMarginModel;
@class TBFuturesContractMarketStatusModel;

@interface TBFuturesContractModel : TBBaseModel

@property (copy, nonatomic) NSString *contractCode;         // 期货端没有，加入股票后加的字段
@property (copy, nonatomic) NSString *contractId;           // 合约id，股票端应该不用
@property (copy, nonatomic) NSString *categoryId;           // 类别id
@property (copy, nonatomic) NSString *exchangeId;           // 交易所id
@property (copy, nonatomic) NSString *exchangeCode;
@property (copy, nonatomic) NSString *productId;            //
@property (copy, nonatomic) NSString *symbolId;             // 合约symbolId   这个字段是未来客户端接资讯接口所需要的
@property (copy, nonatomic) NSString *name;                 // 合约英文名，在股票端展示名称用这个

@property (copy, nonatomic) NSString *securityType;         // 合约种类
@property (copy, nonatomic) NSString *symbol;               // 合约symbol
@property (copy, nonatomic) NSString *symbolName;           // 合约symbol的英文名
@property (copy, nonatomic) NSString *contractMonth;        // 合约月份
@property (copy, nonatomic) NSString *currency;             // 合约币种
@property (copy, nonatomic) NSString *currencyName;         // 币种名称
@property (copy, nonatomic) NSString *firstNoticeDate;      // 第一通知日
@property (assign, nonatomic) NSTimeInterval firstNoticeDateTimestamp;  // 第一通知日的时间戳
@property (copy, nonatomic)   NSString *lastTradingDate;      // 最后交易日
@property (assign, nonatomic) NSTimeInterval lastTradingDateTimestamp;  // 最后交易日的时间戳
@property (copy, nonatomic)   NSString *putOrCall;            // 期权合约方向
@property (retain, nonatomic) TBDecimal *strikePrice;      // 期权合约行权价
@property (assign, nonatomic) BOOL hasVWAP;                 // 是否有均价
@property (retain, nonatomic) TBFuturesContractDescriptionModel *contractDesc;                         // 合约描述
@property (assign, nonatomic) BOOL isMain;                  // 是否是主连合约
@property (assign, nonatomic) BOOL isContinuous;      // 是否是连续合约
@property (assign, nonatomic) BOOL isTrade;                 // 是否可交易
@property (copy, nonatomic)   NSString *referMainContractId;  //对应的主力合约
@property (copy, nonatomic)   NSString *referMainContractCode;    
@property (copy, nonatomic)   NSString *status;               // 合约状态
@property (copy, nonatomic)   NSString *quotesDisplayType;  // 合约行情展示类型

@property (copy, nonatomic)   NSString *deliveryMode;  // 交割方式字段

@property (assign, nonatomic)    CGFloat  halted;  // 停牌状态 0: 正常 3: 停牌 4: 退市 7: 新股 8: 变更
@property (copy, nonatomic)     NSString *secType;  // STK 股票, OPT 期权，WAR窝轮，IOPT牛熊证, FUT期货



@property (assign, nonatomic) NSInteger maxScale;           // 最大精度，用于展示时的最大的小数位数
@property (retain, nonatomic) TBDecimal *quotesScale;              // 行情系统输出精度
@property (retain, nonatomic) TBDecimal *multiplier;       // 合约乘数
@property (retain, nonatomic) TBDecimal *quotesVendorMultiplier;   // 行情系统计算行情乘数
@property (retain, nonatomic) TBDecimal *displayMultiplier;        // 客户端展示行情乘数
@property (retain, nonatomic) TBDecimal *tradeMultiplier;          // 客户端下单转换乘数
@property (retain, nonatomic) NSArray <TBFuturesProductPriceConfigsModel*> *priceIncrements;      // 合约最小变动单位


@property (retain, nonatomic) TBFuturesCategoryModel *categoryModel;   // 获取到合约详情后，需要同时获取合约的种类信息
@property (retain, nonatomic) TBFuturesExchangeModel *exchangeModel;   // 合约的交易所信息

@property (nonatomic, strong) TBFuturesContractMarketStatusModel *marketStatusModel;


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//                  后续保存进来的跟合约相关的属性

@property (retain, nonatomic) TBFuturesContractTradingTimeModel *contractTradingTime; // 合约的交易时段
@property (retain, nonatomic) TBFuturesContractMarginModel *contractMarginModel;      // 合约的保证金
@property (retain, nonatomic) TBFuturesContractModel *referContract;      // 如果是主连合约的话，需要请求接口获取主连合约关联的合约


@property (retain, nonatomic, readonly) NSString *warningTips;                          // 合约展示的时候，在cell上展示的即将下架、过期的提示信息


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#pragma mark - 主连合约关联的合约的一些属性
#pragma mark -

@property (assign, nonatomic) NSInteger referStart;     // 关联合约有效开始时间
@property (assign, nonatomic) NSInteger referEnd;       // 关联合约有效的结束时间

@end






///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//                  辅助的get属性





@interface TBFuturesContractModel (TBHelper)


@property (assign, nonatomic, readonly) TBContractTradingState contractTradingState;   // 合约的交易状态

// 合约的状态，根据第一通知日和最后交易日来算出，用来展示合约左上角的状态角标
@property (assign, nonatomic, readonly) TBContractState contractState;
// 合约的状态，根据后台给的字段得出，用于判断合约是出于被删除还是在线上的状态
@property (assign, nonatomic, readonly) TBContractStatus contractStatus;
// 用于订单相关操作的合约ID，如果是主连的话取得是referContract的合约id
@property (retain, nonatomic, readonly) NSString *orderedContractCode;
@property (assign, nonatomic, readonly, getter=isCashConversion) BOOL cashConversion;   // 是否是换汇的合约
@property (assign, nonatomic, readonly) TBQuotesDisplayType marketQuotesDisplayType;  // 是利率合约还是普通的合约
@property (assign, nonatomic, readonly) BOOL isTradeable;               // 是否可交易，如果是主连合约，则需要判断其关联合约

- (TBContractTradingState)contractTradingStateForTime:(NSTimeInterval)time;

@end

NS_ASSUME_NONNULL_END
