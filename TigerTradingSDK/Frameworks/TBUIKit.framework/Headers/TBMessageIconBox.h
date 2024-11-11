//
//  TBMessageIconBox.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/30.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBMessageBox.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBMessageIconBox : TBCommonConfirmView

- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message images:(NSArray *)images;
- (instancetype)initWithTitle:(NSString *)title subtitle:(nullable NSString *)subtitle message:(nullable NSString *)message images:(NSArray *)images;

@property (nonatomic, copy) NSArray *images;
@property (nonatomic, copy) NSString * message;

@end

NS_ASSUME_NONNULL_END
