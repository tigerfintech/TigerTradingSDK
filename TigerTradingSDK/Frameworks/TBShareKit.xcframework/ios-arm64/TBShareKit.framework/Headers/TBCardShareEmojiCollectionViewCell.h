//
//  TBCardShareEmojiCollectionViewCell.h
//  TBShareKit
//
//  Created by chenxin on 2023/4/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareEmojiCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView *emojiView;

@property (nonatomic, assign) BOOL emojiSelected;

@property (nonatomic, assign) BOOL emojiLocked;

@end

NS_ASSUME_NONNULL_END
