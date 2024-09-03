//
//  TBBaseListAdapter.h
//  Stock
//
//  Created by dull grass on 2019/11/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//
#import "TBBaseSectionAdapter.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBListAdapterProtocol <NSObject,TBSectionAdapterProtocol,TBCellAdapterProtocol>

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;

@end

@interface TBBaseListAdapter : NSObject<TBListAdapterProtocol>

@property(nonatomic, strong) NSMutableArray <TBSectionAdapterProtocol> * sections;

@end

NS_ASSUME_NONNULL_END
