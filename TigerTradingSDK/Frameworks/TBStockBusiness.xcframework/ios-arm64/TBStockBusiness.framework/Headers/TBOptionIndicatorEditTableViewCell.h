//
//  TBOptionIndicatorEditTableViewCell.h
//  Stock
//
//  Created by JustLee on 2021/3/24.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBOptionIndicatorManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionIndicatorEditTableViewCell : TBTableViewCell

@end

@interface TBOptionIndicatorEditTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBOptionDisplayType optionDataDisplayType;

@property (nonatomic, assign) TBOptionDetailIndicator indicatorType;

@property (nonatomic, copy) NSString *periodName;

@end


@interface TBOptionIndicatorEditHeaderTableViewCell : TBTableViewCell

@end

@interface TBOptionIndicatorEditHeaderTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBOptionDisplayType optionDataDisplayType;

@end



@interface TBOptionDisplayTypeTableViewCell : TBTableViewCell

@end

@interface TBOptionDisplayTypeTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBOptionDisplayType optionDataDisplayType;

@property (nonatomic, assign) BOOL selectedCurrentType;

@end

NS_ASSUME_NONNULL_END
