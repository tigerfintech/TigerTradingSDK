//
//  TBStrikeAndSaveDetailBudgetFitActionView.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStrikeAndSaveDetailBudgetFitActionView : UIView

@property (nonatomic, assign) BOOL isSelected;

@property (nonatomic, copy) void(^onTappedSelectBtnBlock)(void);
@property (nonatomic, copy) void(^onTappedHintBtnBlock)(void);

@end

NS_ASSUME_NONNULL_END
