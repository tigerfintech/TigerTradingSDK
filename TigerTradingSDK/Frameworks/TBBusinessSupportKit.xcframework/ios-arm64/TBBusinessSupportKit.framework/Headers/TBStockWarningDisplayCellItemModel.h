//
//  TBStockWarningDisplayCellItemModel.h
//  TBStockKit
//
//  Created by linbingjie on 2021/5/11.
//

#import <Foundation/Foundation.h>
#import "TBStockWarningDisplayModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockWarningDisplayCellItemModel : NSObject

@property (nonatomic, strong) TBStockWarningDisplayModel * displayModel;
@property (nonatomic, strong) TBStockWarningDisplayStockInfo * stockInfo;
@property (nonatomic, copy) NSString *tradeCurrency;
@property (nonatomic, assign) BOOL showSwitch;

@end

NS_ASSUME_NONNULL_END
