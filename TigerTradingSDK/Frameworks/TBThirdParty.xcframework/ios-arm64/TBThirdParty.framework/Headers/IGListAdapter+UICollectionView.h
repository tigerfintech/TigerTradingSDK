/**
 * Copyright (c) 2016-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <TBThirdParty/IGListAdapter.h>
#import <TBThirdParty/IGListCollectionViewDelegateLayout.h>

@interface IGListAdapter (UICollectionView)
<
UICollectionViewDataSource,
IGListCollectionViewDelegateLayout
>
@end
