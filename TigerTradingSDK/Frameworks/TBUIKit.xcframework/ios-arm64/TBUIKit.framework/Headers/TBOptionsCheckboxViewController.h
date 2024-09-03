//
//  TBOptionsCheckboxViewController.h
//  TBTradeBusiness
//
//  Created by swordzhou on 10/11/23.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class MZFormSheetPresentationViewController;

@interface TBOptionsCheckboxViewController : TBListTableViewController

@property (nonatomic, assign, readonly) CGFloat contentHeight;

- (instancetype)initWithOptions:(NSArray *)options
                          title:(NSString *)title
                selectedIndices:(NSArray<NSNumber *> *)selectedIndices
        allowsMultipleSelection:(BOOL)allowsMultipleSelection
 selectedIndicesDidChangedBlock:(void(^)(NSArray<NSNumber *> *))selectedIndicesDidChangedBlock;


@end

NS_ASSUME_NONNULL_END
