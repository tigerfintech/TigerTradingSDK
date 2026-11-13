//
//  TBViewController+TBInternal.h
//  TigerQuoteSDK
//

#import "TBViewController.h"

@class TBDemoCustomHomeModule;
@class TBDemoQuoteProvider;

NS_ASSUME_NONNULL_BEGIN

@interface TBViewController ()

@property (nonatomic, strong, nullable) TBDemoCustomHomeModule *customHomeModule;
@property (nonatomic, strong) TBDemoQuoteProvider *quoteProvider;

@end

NS_ASSUME_NONNULL_END
