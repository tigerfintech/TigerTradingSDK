//
//  TBSwiftComponentServiceImplementation.h
//  AFNetworking
//
//  Created by linbingjie on 2023/1/5.
//

#import <Foundation/Foundation.h>
#import <TBServiceProtocolKit/TBSwiftComponentService.h>
#import <TBBaseKit/TBBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSwiftComponentServiceImplementation : NSObject
<
  TBSwiftComponentService,
  TBServiceBaseProtocol
>
DECLARE_SHARED_INSTANCE(TBSwiftComponentServiceImplementation);

@end

NS_ASSUME_NONNULL_END
