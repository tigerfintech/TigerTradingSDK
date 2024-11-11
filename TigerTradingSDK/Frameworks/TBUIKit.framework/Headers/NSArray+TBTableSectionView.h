//
//  NSArray+TBTableSectionView.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBTableViewCellItem.h"

@interface NSArray (TBTableSectionView)

@property (nonatomic, strong) TBTableViewCellItem *sectionHeaderItem;
@property (nonatomic, strong) TBTableViewCellItem *sectionFooterItem;

@end

@interface TBTableSectionView : UIControl

@property (nonatomic, strong) TBTableViewCellItem *sectionItem;



@end
