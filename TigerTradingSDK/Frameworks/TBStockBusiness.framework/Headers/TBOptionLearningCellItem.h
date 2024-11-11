//
//  TBOptionLearningCellItem.h
//  TBStockBusiness
//
//  Created by chenxin on 2023/8/10.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionLearningCell : TBTableViewCell

@end

@interface TBOptionLearningCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray *dataArray;

@property (nonatomic, assign) BOOL timerEnabled;

@property (nonatomic, assign) BOOL noLessonData;

@end

NS_ASSUME_NONNULL_END
