//
//  TBMarketPackageSectionIndicatorHeaderItem.h
//  Stock
//
//  Created by PXJ on 2020/10/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMarketPackageSectionHeaderItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketPackageSectionIndicatorHeaderItem : TBMarketPackageSectionHeaderItem
@property (nonatomic, copy) NSString *indicatorDes;
@property (nonatomic, copy) NSDictionary *explainInfo;//给问号添加方法，必须传此参数
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) BOOL onlyShowDesText;//不要小箭头只要右边文字
@end

@interface TBMarketPackageSectionIndicatorHeaderView : TBMarketPackageSectionHeaderView
@property (nonatomic, strong) UILabel *indicatorDesLabel;
@end

NS_ASSUME_NONNULL_END
