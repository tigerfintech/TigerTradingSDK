
#import <Foundation/Foundation.h>

@interface DSCallInfo : NSObject
@property (nullable, nonatomic, copy) NSString *method;
@property (nullable, nonatomic, strong) NSNumber *id;
@property (nullable, nonatomic, copy) NSArray *args;
@end
