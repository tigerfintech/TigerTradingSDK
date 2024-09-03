//
//  TBWealthCheckPreconditionItem.h
//  TBAccountSystemKit
//
//  Created by swordzhou on 12/15/23.
//

#import "TBWealthCheckBaseItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBWealthCheckPreconditionItem : TBWealthCheckBaseItem

- (void)handleWithActionType:(void(^)(BOOL next, NSDictionary * _Nullable resultInfo))completion;

@end

NS_ASSUME_NONNULL_END
