//
//  TBHomePageWatchListLabelCell.h
//  Pods
//
//  Created by zlc on 2022/5/13.
//  
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageWatchListLabelCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL hasLabel;
@property (nonatomic, copy) NSString *label;

@end

@interface TBHomePageWatchListLabelCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
