//
//  TBAutoCountingMessageBox.h
//  Stock
//
//  Created by yangfan on 2019/6/20.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBMessageBox.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBAutoCountingMessageBox : TBMessageBox

//自动计数的最大值，message box将每秒递减，然后自动选中
@property (nonatomic, assign) NSInteger count;
//将自动选中的索引值，0为取消，1为确认
@property (nonatomic, assign) NSInteger autoSelectedIndex;

@end

NS_ASSUME_NONNULL_END
