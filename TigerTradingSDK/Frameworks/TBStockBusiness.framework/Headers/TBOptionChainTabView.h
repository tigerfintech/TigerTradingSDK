//
//  TBOptionChainTabView.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//


NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainTabView : UIView

@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy) NSArray<NSString *> *dataSources;

@property (nonatomic, copy) void(^segementChangedBlock)(NSInteger index);

@end


NS_ASSUME_NONNULL_END
