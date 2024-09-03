//
//  TBAStockFundTableViewCell.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/9.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>


@protocol TBAStockFundTableViewCell <NSObject>
@end

@interface TBAStockFundTableViewCell : TBTableViewCell




@end

@interface TBAStockFundTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *message;

@property (nonatomic, copy) NSString *url;
- (instancetype)initWithTitle:(NSString *)title value:(NSString *)value message:(NSString *)message;

- (instancetype)initWithTitle:(NSString *)title value:(NSString *)value message:(NSString *)message url:(NSString *)url;
@end
