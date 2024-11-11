//
//  TBOmnibusAPICheckOrderModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
#import "TBOmnibusAPIAssetPreviewModel.h"
#import "TBOmnibusAPIOrderPreviewModel.h"
#import "TBOmnibusAPIOrderBondPreivewModel.h"
#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import "TBOmnibusAPIOptionExercisePreview.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAPICheckOrderModel : JSONModel

//@property (nonatomic, strong) NSNumber *commission; // 佣金（预估佣金  遗弃，orderPreview.commissionPreview.commission替换）
//@property (nonatomic, strong) NSNumber *margin; // 保证金增减（预估增加保证金 遗弃，orderPreview.initMargin替换）
@property (nonatomic, strong) TBOmnibusAPIAssetPreviewModel *assetPreview; // 资产预览
@property (nonatomic, strong) TBOmnibusAPIAssetPreviewModel *assetPreviewChange; // 成交变化资产预览
@property (nonatomic, strong) TBOmnibusAPIOrderPreviewModel *orderPreview; // 订单预览
@property (nonatomic, strong) TBOmnibusAPIOrderBondPreivewModel *bondPreview; // 债券预览信息

@property (nonatomic, strong) TBOmnibusAPIOptionExercisePreview *optionExercisePreview; // 订单预览


@end

@interface TBOmnibusAPICheckOrderItemModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAPICheckOrderModel *data; // 佣金
@end

NS_ASSUME_NONNULL_END
