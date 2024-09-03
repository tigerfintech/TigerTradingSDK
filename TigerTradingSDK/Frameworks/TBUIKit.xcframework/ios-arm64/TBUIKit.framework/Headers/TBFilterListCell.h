//
//  TBFilterListCell.h
//  Stock
//
//  Created by swordzhou on 2021/5/24.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFilterListCell : UITableViewCell

@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, copy) NSString *selectedIconName;
@property (nonatomic, assign) BOOL showSelectedIcon;
@property (nonatomic, assign) BOOL bottomLineHidden;
@property (nonatomic, strong) UIFont *selectedTextFont;

@end

NS_ASSUME_NONNULL_END
