//
//  TBBaseSectionAdapter.h
//  Stock
//
//  Created by dull grass on 2019/11/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//
#import "TBBaseCellAdapter.h"
#import <Foundation/Foundation.h>

@protocol TBSectionAdapterProtocol <NSObject,UITableViewDataSource,UITableViewDelegate>

- (CGFloat)tableView:(UITableView *_Nonnull)tableView heightForHeaderInSection:(NSInteger)section;

- (NSString *_Nullable)tableView:(UITableView *_Nullable)tableView titleForHeaderInSection:(NSInteger)section;

- (UIView *_Nullable)tableView:(UITableView *_Nullable)tableView viewForHeaderInSection:(NSInteger)section;

- (CGFloat)tableView:(UITableView *_Nullable)tableView heightForFooterInSection:(NSInteger)section;

- (UIView *_Nullable)tableView:(UITableView *_Nullable)tableView viewForFooterInSection:(NSInteger)section;

@end

NS_ASSUME_NONNULL_BEGIN

// Section适配器层依赖了cell适配器层，所以需要cell适配器层的内容转发到cell适配器层
// 转发部分用到了OC中的respondsToSelector和ForwardingTargetForSelector
@interface TBBaseSectionAdapter : NSObject <TBSectionAdapterProtocol,TBCellAdapterProtocol>

@property (nonatomic, copy) NSString *sectionTitle;

@property (nonatomic, assign) CGFloat sectionHeight;

@property (nonatomic, strong) id <TBCellAdapterProtocol> cellAdapter;

- (instancetype)initWithCellAdapter:(id<TBCellAdapterProtocol>)cellAdapter sectionTitle:(nullable NSString *)sectionTitle sectionHeight:(CGFloat)sectionHeight;
@end

NS_ASSUME_NONNULL_END
