//
//  JustSectionTableViewCell.h
//  TBComponentTableView
//
//  Created by Just on 2019/4/1.
//  Copyright © 2019 Just. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentTableViewCellItem.h"

@interface TBComponentTableViewSectionView : UITableViewHeaderFooterView

/**
 sectionView item, as a container for the sectionView
 */
@property (nonatomic, strong) TBComponentTableViewCellItem *tableViewCellItem;

@property (nonatomic, assign) BOOL enableTapAction;

@property (nonatomic, assign) BOOL enableLongPressAction;

@end
