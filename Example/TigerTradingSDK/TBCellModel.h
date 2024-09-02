//
//  TBCellModel.h
//  TigerQuoteSDK_Example
//
//  Created by linbingjie on 2024/8/12.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCellModel : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, copy) void (^action)(void);

- (instancetype)initWithTitle:(NSString *)title action:(void (^)(void))action;

@end

NS_ASSUME_NONNULL_END
