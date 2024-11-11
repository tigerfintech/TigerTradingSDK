//
//  TBOptionChangeSegmentCell.h
//  Stock
//
//  Created by 王灵博 on 2021/1/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionAnalysisHeader.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChangeSegmentCell : TBTableViewCell

@end


@interface TBOptionChangeSegmentCellItem : TBTableViewCellItem
@property(nonatomic, assign)TBOptionChangeType changeType;
@end

NS_ASSUME_NONNULL_END
