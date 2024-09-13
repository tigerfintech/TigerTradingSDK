//
//  TBOptionBaseInfoTableviewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/8/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@interface TBOptionBaseInfoTableviewCell : TBTableViewCell

@end

@interface TBOptionBaseInfoTableviewCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, assign,getter=isLastDay) BOOL lastDay;
- (void) applySymbol:(NSString *)symbol nameCN:(NSString *)nameCN right:(NSString *)right expiry:(NSString *)expiry strike:(NSString *)strike;
@end

