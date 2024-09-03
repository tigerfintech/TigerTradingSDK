//
//  TBPagAnimationConfirmView.h
//  TBCommunityBusiness
//
//  Created by 秦晓强 on 2022/7/20.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBCommonConfirmView.h>
#import <libpag/PAGView.h>
#import <libpag/PAGFile.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPagAnimationConfirmView : TBCommonConfirmView

@property (nonatomic, copy) NSString *pagResource;
@property (nonatomic, copy) NSString *pagTitle;
@property (nonatomic, copy) NSString *pagContent;


@end

NS_ASSUME_NONNULL_END
