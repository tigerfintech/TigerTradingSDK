//
//  TBOptionCallPutRatioHeaderView.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/12/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionCallPutRatioHeaderView : TBTableViewCell

@end

@interface TBOptionCallPutRatioHeaderViewItem : TBTableViewCellItem

@property (nonatomic, strong) NSNumber *currentValue;
@property (nonatomic, copy) NSString *ratioSetting;

@end

NS_ASSUME_NONNULL_END
