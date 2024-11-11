//
//  TBHomepageShortcutsCollectionViewCell.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/9/14.
//

#import <TBUIKit/TBCollectionViewCell.h>
#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBShortcutsModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomepageShortcutsCollectionViewCell : TBCollectionViewCell

@property (nonatomic, strong) TBShortcutsModel *cellItem;

@end

NS_ASSUME_NONNULL_END
