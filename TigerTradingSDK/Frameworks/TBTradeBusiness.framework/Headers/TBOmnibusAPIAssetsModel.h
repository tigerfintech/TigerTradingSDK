//
//  TBOmnibusAPIAssetsModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import "TBOmnibusAPIAssetModel.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark

@interface TBOmnibusAPIAssetsDataModel : JSONModel

@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *total;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *sec;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *fut;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *digi;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *fund;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *cashPlus;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *aggregated;
@property (nonatomic, strong) TBOmnibusAPIAssetModel <Optional,TBAsset> *card;


@end

#pragma mark - /portfolio/assets Model

@interface TBOmnibusAPIAssetsModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAPIAssetsDataModel <Optional> *data;

@end

@protocol TBOmnibusPortfolioConsolidatedAssetsDataModel;

@interface TBOmnibusPortfolioConsolidatedAssetsDataModel : JSONModel

@property (nonatomic, strong) NSNumber *portfolioId;

@property (nonatomic, copy) NSString *portfolioName;
@property (nonatomic, copy) TBOmnibusAPIAssetModel <Optional, TBAsset> *assetDetails;

@end


@interface TBOmnibusPortfolioConsolidatedAssetsModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusPortfolioConsolidatedAssetsDataModel> *data;

@end


NS_ASSUME_NONNULL_END
