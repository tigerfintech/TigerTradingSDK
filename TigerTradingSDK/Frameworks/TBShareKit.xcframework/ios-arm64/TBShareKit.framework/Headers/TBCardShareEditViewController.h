//
//  TBCardShareEditViewController.h
//  TBShareKit
//
//  Created by chenxin on 2023/4/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// emojiDict有两个key，分别为iconName和code
typedef void (^TBCardShareEditSelectEmojiBlock)(NSDictionary *emojiDict);
// textDict有两个key，分别为content和code
typedef void (^TBCardShareEditSelectTextBlock)(NSDictionary *textDict);

typedef void (^TBCardShareEditDismissBlock)(void);

@interface TBCardShareEditViewController : UIViewController

@property (nonatomic, strong, readonly) UIScrollView *scrollView;

@property (nonatomic, strong) TBCardShareEditSelectEmojiBlock selectEmojiBlock;

@property (nonatomic, strong) TBCardShareEditSelectTextBlock selectTextBlock;

@property (nonatomic, strong, nullable) TBCardShareEditDismissBlock willDismissBlock;

@property (nonatomic, copy) NSString *selectedEmojiCode;

//@property (nonatomic, copy) NSString *selectedTextCode;
@property (nonatomic, copy) NSString *selectedText;

@end

NS_ASSUME_NONNULL_END
