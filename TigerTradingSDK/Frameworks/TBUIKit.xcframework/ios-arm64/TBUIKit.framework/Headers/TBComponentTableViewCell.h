//
//  TBComponentTableViewCell.h
//  TBComponentTableView
//
//  Created by Just on 2019/3/18.
//  Copyright © 2019 Just. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentTableViewCellItem.h"

@interface TBComponentTableViewCell : UITableViewCell

/**
 cell item, as a container for the cell
 */
@property (nonatomic, strong) TBComponentTableViewCellItem *tableViewCellItem;

@property (nonatomic, assign) BOOL enableLongPressAction;

@end
