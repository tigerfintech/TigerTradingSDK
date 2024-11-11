//
//  TBFundTagView.h
//  TBFundMall
//
//  Created by wind on 2023/6/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFundTagDescriptionView : UIView

- (void)updateWithMaxWidth:(CGFloat)maxWidth fundDescription:(NSString *)fundDescription;

- (void)updateWithMaxWidth:(CGFloat)maxWidth baseTags:(nullable NSArray *)baseTags otherTags:(NSArray *)otherTags;

@end

NS_ASSUME_NONNULL_END
