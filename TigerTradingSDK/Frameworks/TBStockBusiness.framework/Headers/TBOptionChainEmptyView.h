//
//  TBOptionChainEmptyView.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/11/16.
//

#import "TBOptionEmptyView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainEmptyView : TBOptionEmptyView

@property(nonatomic, strong) UILabel *relateIndexTitleLabel;
@property(nonatomic, strong) UILabel *relateIndexContentLabel;

@property(nonatomic, copy) void(^tapRelateViewBlock)(void);

@end

NS_ASSUME_NONNULL_END
