//
//  TBSkeletonTableViewCell.h
//  Stock
//
//  Created by JustLee on 2019/5/16.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

typedef NS_ENUM(NSUInteger, TBSkeletonType) {
    TBSkeletonTypeSingleCard = 0,
    TBSkeletonTypeHor2Cards,
    TBSkeletonTypeHor3Cards,
    TBSkeletonTypeInfo,
    TBSkeletonTypeVerItems,
    TBSkeletonTypeVerIconItems,
    TBSkeletonTypeHeaderView
};

@interface TBSkeletonView : UIView

@end


@interface TBSkeletonTableViewCell : TBTableViewCell

@end

@interface TBSkeletonTableViewCellItem : TBTableViewCellItem

+ (instancetype)skeletonWithType:(TBSkeletonType)type;

@property (nonatomic, assign) TBSkeletonType type;

@end



@interface TBSkeletonSingleCardTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonHor3CardsTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonHeaderTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonHor2CardsTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonInfoTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonVerItemsTableViewCell : TBSkeletonTableViewCell

@end

@interface TBSkeletonVerIconItemsTableViewCell : TBSkeletonTableViewCell

@end
