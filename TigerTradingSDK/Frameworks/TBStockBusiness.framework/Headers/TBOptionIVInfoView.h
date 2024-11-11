//
//  TBOptionIVInfoView.h
//  Stock
//
//  Created by 王灵博 on 2021/1/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBOptionChainModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionIVInfoView : UIView
@property(nonatomic, strong) TBOptionChainModel *optionModel;
@end

NS_ASSUME_NONNULL_END
