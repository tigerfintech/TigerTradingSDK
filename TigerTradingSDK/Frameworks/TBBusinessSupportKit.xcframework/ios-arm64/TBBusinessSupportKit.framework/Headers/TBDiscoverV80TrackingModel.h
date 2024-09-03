//
//  TBDiscoverV80TrackingModel.h
//  TBStockBusiness
//
//  Created by 秦晓强 on 2024/5/16.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDiscoverV80TrackingModel : JSONModel

@property (nonatomic, copy) NSString *summary;
@property (nonatomic, assign) NSInteger trackId;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSArray *symbols;
@property (nonatomic, copy) NSString *image;
@property (nonatomic, copy) NSString *tag;
@property (nonatomic, copy) NSString *url;

@end

NS_ASSUME_NONNULL_END
