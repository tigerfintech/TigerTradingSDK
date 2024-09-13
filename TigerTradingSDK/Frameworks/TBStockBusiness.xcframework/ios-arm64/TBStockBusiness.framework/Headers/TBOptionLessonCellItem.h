//
//  TBOptionLessonCellItem.h
//  TBStockBusiness
//
//  Created by chenxin on 2023/8/11.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionLessonCell : TBTableViewCell

@end

@interface TBOptionLessonCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray *dataArray;

@end

NS_ASSUME_NONNULL_END
