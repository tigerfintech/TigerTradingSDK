//
//  TBCardShareModel.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#import <Foundation/Foundation.h>

@class TBCardShareView;
@class TBShareInfoModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareModel : NSObject

@property (nonatomic, assign) NSInteger shareType;
@property (nonatomic, strong) TBCardShareView *shareCardView;
@property (nonatomic, strong) TBShareInfoModel *shareInfo;

@end

NS_ASSUME_NONNULL_END
