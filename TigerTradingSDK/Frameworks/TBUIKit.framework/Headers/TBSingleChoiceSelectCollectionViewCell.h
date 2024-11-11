//
//  TBSingleChoiceSelectCollectionViewCell.h
//  AFNetworking
//
//  Created by linbingjie on 2023/8/16.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBSelectBaseBorderCollectionViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSingleChoiceSelectCollectionViewCell : TBSelectBaseBorderCollectionViewCell


- (void)updateTitle:(NSString *)strTitle selectedStatus:(BOOL)isSelected;

@end

NS_ASSUME_NONNULL_END

