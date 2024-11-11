//
//  TBAuthAccountPermissionModel.h
//  TBAccountSystemKit
//
//  Created by linbingjie on 2021/2/5.
//

#import "TBAuthBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TBAuthAccountPermissionDataModel;

@interface TBAuthAccountPermissionModel : TBAuthBaseModel

@property (nonatomic, strong) TBAuthAccountPermissionDataModel *data;

@end


@interface TBAuthAccountPermissionDataModel : JSONModel

@property (nonatomic, copy) NSString *location;
@property (nonatomic, strong) NSNumber *version;
@property (nonatomic, copy) NSArray *quotePermission;
@property (nonatomic, copy) NSArray *tradePermission;
@property (nonatomic, copy) NSString *hkQuoteType;
@property (nonatomic, assign) BOOL signETF;
@property (nonatomic, strong) NSNumber *perm_version;

@property (nonatomic, copy) NSArray<Ignore> *permission; // 用拆分出的quotePermission和tradePermission代替

@end

NS_ASSUME_NONNULL_END
