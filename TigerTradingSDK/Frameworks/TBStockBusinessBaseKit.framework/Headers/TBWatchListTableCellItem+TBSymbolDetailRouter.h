//
//  TBWatchListTableCellItem+TBSymbolDetailRouter.h
//  TBStockBusinessBaseKit
//
//  Created by 王昌阳 on 2023/11/24.
//

#import "TBWatchListTableCellItem.h"
#import <TBBusinessSupportKit/TBSymbolDetailRouterParamsProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListTableCellItem (TBSymbolDetailRouter)<TBSymbolDetailBondParamsProtocol,
TBSymbolDetailFundParamsProtocol,
TBSymbolDetailMLegParamsProtocol,
TBSymbolDetailOptionParamsProtocol,
TBSymbolDetailStockParamsProtocol,
TBSymbolDetailWARIOPTParamsProtocol>

@end

NS_ASSUME_NONNULL_END
