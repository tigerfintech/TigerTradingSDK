//
//  TBSNOptionsPickerViewController.h
//  TBTradeBusiness
//
//  Created by swordzhou on 10/11/23.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionsPickerViewController : TBBaseViewController

- (instancetype)initWithOptions:(NSArray *)options
                          title:(NSString *)title
               selectedIndex:(NSInteger)selectedIndex
   selectedIndexDidChangedBlock:(void(^)(NSInteger))selectedIndexDidChangedBlock;

- (CGFloat)contentHeight;

@end

NS_ASSUME_NONNULL_END
