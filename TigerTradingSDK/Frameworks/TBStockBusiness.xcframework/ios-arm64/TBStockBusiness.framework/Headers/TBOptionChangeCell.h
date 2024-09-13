//
//  TBOptionChangeCell.h
//  Stock
//
//  Created by 王灵博 on 2021/8/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBOptionRankChangeModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChangeCell : UITableViewCell
@property(nonatomic ,strong) TBOptionRankChangeModel *changeModel;
@end

NS_ASSUME_NONNULL_END
