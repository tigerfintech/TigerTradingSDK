//
//  TBSelectAndAddConfirmView.h
//  Stock
//
//  Created by yangfan on 2017/3/13.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

#define     TBCreateGroupSelectIndex        0xFE65ED

@interface TBSelectAndAddConfirmView : TBCommonConfirmView

//目前只支持展示字符串或者属性字符串选项数据
@property (nonatomic, copy) NSArray<NSString *>                   * optionArray;
@property (nonatomic, copy) NSArray<NSAttributedString *>         * attributedOptionArray;
//选中的选项
@property (nonatomic, copy) NSArray<NSNumber *>                   * selectedOptions;
//不可选中的选项
@property (nonatomic, copy) NSArray<NSNumber *>                   * ignoreOptions;
//是否可多选
@property (nonatomic, assign) BOOL                                    multipleSelection;

///在ignoreOptions中，disable时默认状态，默认：NO（对应的非选中图）
@property (nonatomic, assign) BOOL                                  disableSelectAtIgnoreOptions;

// 页面展示后，更新已选择的选项，会reloadTable
- (void)updateSelectedOptions: (NSArray<NSNumber *> *)selectedOptions;

// 滚动到底部
- (void)scrollToBottom;

@end
