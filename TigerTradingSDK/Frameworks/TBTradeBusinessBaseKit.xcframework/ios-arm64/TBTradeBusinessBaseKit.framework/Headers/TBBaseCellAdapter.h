//
//  TBBaseCellAdapter.h
//  Stock
//
//  Created by dull grass on 2019/11/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ TBCellAdapterBlock) (NSIndexPath *cellIndexPath);

@protocol TBCellAdapterProtocol <NSObject, UITableViewDelegate, UITableViewDataSource>

@end

//对应层需要做一个Base的实现，目的是为了拔通用的工作放在Base的实现类中，把差异的工作放到子类中。这样可以达到复用代码和减少实现代码的目的
@interface TBBaseCellAdapter : NSObject<TBCellAdapterProtocol>

@property (nonatomic, strong) NSMutableArray *data;

- (instancetype)initWithTableView:(UITableView *)tableView datas:(NSMutableArray *)data;

@property (nonatomic, copy) TBCellAdapterBlock block;

@end

NS_ASSUME_NONNULL_END
