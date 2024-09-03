//
//  TBCardShareUnlockRuleCollectionViewCell.h
//  TBShareKit
//
//  Created by chenxin on 2023/4/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TBCardShareUnlockRuleClickBlock)(void);

@interface TBCardShareUnlockRuleCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) TBCardShareUnlockRuleClickBlock clickBlock;

@end

NS_ASSUME_NONNULL_END
