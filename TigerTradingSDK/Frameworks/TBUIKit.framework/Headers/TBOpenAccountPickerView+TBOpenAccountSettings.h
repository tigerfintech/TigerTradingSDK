//
//  TBOpenAccountPickerView+TBOpenAccountSettings.h
//  StockGlobal
//
//  Created by CharmingQin on 2018/11/12.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import "TBOpenAccountPickerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOpenAccountPickerView (TBOpenAccountSettings)

+ (NSDictionary *)tbPicker_optionsWithSelectedObjects:(NSArray *)selectedObjects;
+ (NSDictionary *)tbPicker_createPostVoteOptionsWithSelectedObjects:(NSArray *)selectedObjects;
@end

NS_ASSUME_NONNULL_END
