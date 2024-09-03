//
//  TBFuturesPriceUtil.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBFuturesContractModel.h"

@class TBFuturesProductPriceConfigsModel;
@class TBFuturesContractModel;

/*
 价格为空时的展示内容
 */
extern NSString *const TBDefaultDisplayFuturesPrice;


/*
 利率价格的小数部分其实是一个分数的表现形式，如  x + y/4 , 其中y转换成小数对应如下：
 y --> 分数部分f
 0      0
 1      3
 2      5
 3      7
 分数部分转换后正常只能是 0 3 5 7
 转换后的利率小数部分为  x * 10 + f
 
 如  30'107，实际应该是 30 + (10 + 3 / 4.0) / 128.0
 */


@interface TBFuturesPriceUtil : NSObject

/**
将数值型的价格转换成展示的利率价格

@param price 完全计算好后的价格，因为有转换乘数的存在，所以这里的价格只能是计算过以后的，不能是后台直接传来的价格
@param need 是否需要正数的 + 号前缀
@return 转换后的符合利率规则的价格字符串
*/
+ (NSString *)displayForInterestPrice:(NSNumber *)price needPositivePrefix:(BOOL)need;

/**
 将价格转换成有效的数值类型
 主要的目的是用来将字符串的价格转换成数值类型，再者因为有利率合约的存在，
 在从显示的价格转换成数值的时候不能直接转，需要一番计算，如 0'027  -->  0.0859375

 @param price 需要计算的价格可以是数值类型和字符串，如果是数值类型，则会直接返回
 @return 计算好的数值类型的价格
 */
+ (NSNumber *)realPriceFromDisplayPrice:(id)price ;

+ (void)preload;


/**
 将给出的id类型价格转换成number类型 (907 开放出来给别的类用）

 @param price 外部传进来的，可以为 NSString NSNumber TBDecimal
 @return 转换的数值类型
 */
+ (NSNumber *)_numberFromPrice:(id)price;

@end


// 因为期货价格的计算都是跟合约密切相关的，没有合约信息就无法做价格的计算，所以相关的操作都封装在合约的category中

@interface TBFuturesContractModel (TBFuturesPriceUtil)


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/*

 期货端的价格分为三种：

 价格类型    说明
 行情价     从行情系统获取到的价格，如最新价、昨收价、昨结价等等
 展示价     展示给用户看的价格
 交易价     从交易系统获取到的价格，如下单交易和订单详情里的订单价格等

 他们间的转换关系如 ：

 行情价 * displayMultiplier = 展示价
 交易价 / tradeMultiplier = 展示价

 对于前端来说，基本上所有的价格都会经过展示价的转换，如行情过来的价格给用户看，
 需要经过转换，订单来的价格给用户看也需要转换，下单的时候价格计算也需要给用户看到。
 所以，为了计算的方便和统一，所有操作的价格都转换成展示价格最好最方便

*/

/*
 将价格转换成前端展示的数值型价格，在APP端，为了方便的计算和展示，其实是将各个系统间的价格转换成展示价格的精度，
 此处的价格是各系统传过来的原始值，可以是原始的TBDecimal类型，也可以是未经过multipler转换过的Number类型的价格
 */

@property (copy, nonatomic, readonly) NSNumber *(^priceFromQuotesPrice)(id quotesPrice);
@property (copy, nonatomic, readonly) NSNumber *(^quotesPriceFromPrice)(id quotesPrice);

@property (copy, nonatomic, readonly) NSNumber *(^priceFromTradePrice)(id tradePrice);


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
 将给定的价格转换成对应的展示给用户看的价格字符串
 */

#pragma mark - 计算行情价格

/**
 将行情系统过来的原始价格转换成展示的字符串型价格

 @param price 行情系统过来的价格，可以为NSNumber、TBDecimal型
 @param scale 展示的最大小数位数
 @param needPositivePrefix 正数数值是否需要前面的正号
 @return 转换好的字符串型价格
 */
- (NSString *)displayForQuotesPrice:(id)price scale:(short)scale needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForQuotesPrice:(id)price needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForQuotesPrice:(id)price scale:(short)scale;
- (NSString *)displayForQuotesPrice:(id)price;

#pragma mark - 计算交易价格

/**
 将交易系统过来的原始价格转换成展示的字符串型价格

 @param price 交易系统过来的价格，可以为NSNumber、TBDecimal型
 @param scale 展示的最大小数位数
 @param needPositivePrefix 正数数值是否需要前面的正号
 @return 转换好的字符串型价格
 */
- (NSString *)displayForTradePrice:(id)price scale:(short)scale needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForTradePrice:(id)price needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForTradePrice:(id)price scale:(short)scale;
- (NSString *)displayForTradePrice:(id)price;

#pragma mark - 计算经过multipler处理过的价格

/**
 将经过转换乘数转换过的价格转换成展示的字符串型价格

 @param price 经过转换乘数转换过的价格，一定注意是经过转换乘数转换过，如果是各系统获取到的原始价格的话，没有经过乘数转换会出不对
 @param scale 展示的最大小数位数
 @param needPositivePrefix 正数数值是否需要前面的正号
 @return 转换好的字符串型价格
 */
- (NSString *)displayForPrice:(id)price scale:(short)scale needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForPrice:(id)price needPositivePrefix:(BOOL)needPositivePrefix;
- (NSString *)displayForPrice:(id)price scale:(short)scale;
- (NSString *)displayForPrice:(id)price;




#pragma mark - 价格最小变动单位相关计算


/**
 获取给定价格对应的最小变动单位的数值
 
 @param price 要计算的价格，可以为Number、String，必须是经过乘数转换过的价格，因为行情系统、交易系统过来的价格来算最小变动单位没有意义
 @return 最小变动单位数值，如果合约数据中没有相关变动单位的话，则返回nil，否则会返回一个有效的数值
 */
- (NSNumber *)increasementForPrice:(id)price;

/**
 获取给定价格对应的最小变动单位的展示的数值
 
 @param price 要计算的价格，可以为Number、String，必须是经过乘数转换过的价格，因为行情系统、交易系统过来的价格来算最小变动单位没有意义
 @return 最小变动单位的展示数值
 */
- (NSString *)displayIncreasementForPrice:(id)price;

/**
 根据给定的价格获取对应的价格变动的信息
 
 @param price 要计算的价格，可以为Number、String，必须是经过乘数转换过的价格，因为行情系统、交易系统过来的价格来算最小变动单位没有意义
 @return 价格变动的数据
 */
- (TBFuturesProductPriceConfigsModel *)priceConfigsFormPrice:(id)price;


#pragma mark - 价格计算

/**
 根据给定的价格信息等计算处理过的价格
 
 @param price 要计算的价格，可以为Number、String
 @param factor 要加上的最小变动单位的倍数
 @param inscrement 此时价格所对应的最小变动单位的指针
 @param negativeEnable 是否可以为负数，默认为NO，当价格小于0的话，会返回0
 @return 计算过的价格
 */
- (NSNumber *)operateForPrice:(id)price factor:(NSInteger)factor
             inscrementString:(NSString *__autoreleasing *)inscrement
               negativeEnable:(BOOL)negativeEnable;
- (NSNumber *)operateForPrice:(id)price factor:(NSInteger)factor
             inscrementString:(NSString **)inscrement;
- (NSNumber *)operateForPrice:(id)price factor:(NSInteger)factor
             inscrementNumber:(NSNumber *__autoreleasing *)inscrement
               negativeEnable:(BOOL)negativeEnable;
- (NSNumber *)operateForPrice:(id)price factor:(NSInteger)factor
             inscrementNumber:(NSNumber **)inscrement;

- (NSNumber *)operateForPrice:(id)price factor:(NSInteger)factor;






#pragma mark - 安全的判断
#pragma mark -

/**
 根据合约信息，计算是否是有效合法的价格，
 
 @param price 要判断计算的价格
 @return 是否合法有效
 */
- (BOOL)isValidatePrice:(id)price;

/**
 根据给定的价格范围来给出一个符合最小变动单位的价格
 
 @param price 要判断的价格
 @param min 最小值
 @param max 最大值
 @return 符合最小变动单位的价格
 */
- (NSNumber *)validatePrice:(id)price minPrice:(NSNumber *)min maxPrice:(NSNumber *)max;
- (NSNumber *)validatePrice:(id)price;


@end

