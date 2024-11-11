//
//  TBStockLabelMatrix.h
//  MaxtriView
//
//  Created by Pengfei_Luo on 15/12/13.
//  Copyright © 2015年 骆朋飞. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBStockLabelMatrix : UIView

/**
 *  初始化
 *
 *  @param frame   frame
 *  @param columns 每列宽度数组
 */
- (id)initWithFrame:(CGRect)frame andColumnsWidths:(NSArray*)columns;

@property (nonatomic, strong) UIColor *textColor;

/**
 *  添加行
 *
 *  @param record 每行数据数组
 *  @param changeColor 需要变色索引
 */
- (void)addRecord: (NSArray*)record changeColor:(NSInteger)changeColor section:(NSInteger)section;
- (void)addRecord: (NSArray*)record;

- (void)addRecord: (NSArray*)record firColor:(UIColor *)firColor secColor:(UIColor *)secColor;

- (void)addRecordMap:(NSArray<NSDictionary *> *)record drawBottom:(BOOL)drawBottom;
@end
