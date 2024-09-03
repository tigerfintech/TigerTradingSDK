//
//  TBOmnibusAPIAssetDataModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import "TBOmnibusAPIAssetModel.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - /portfolio/asset Model

@interface TBOmnibusAPIAssetDataModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *data;

@end

NS_ASSUME_NONNULL_END
