/**
 * Copyright (c) 2016-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <TBThirdParty/IGListCompatibility.h>

/**
 * Project version number for IGListKit.
 */
FOUNDATION_EXPORT double IGListKitVersionNumber;

/**
 * Project version string for IGListKit.
 */
FOUNDATION_EXPORT const unsigned char IGListKitVersionString[];

#if TARGET_OS_EMBEDDED || TARGET_OS_SIMULATOR

// iOS and tvOS only:

#import <TBThirdParty/IGListAdapter.h>
#import <TBThirdParty/IGListAdapterDataSource.h>
#import <TBThirdParty/IGListAdapterDelegate.h>
#import <TBThirdParty/IGListAdapterUpdateListener.h>
#import <TBThirdParty/IGListAdapterUpdater.h>
#import <TBThirdParty/IGListAdapterUpdaterDelegate.h>
#import <TBThirdParty/IGListBatchContext.h>
#import <TBThirdParty/IGListBindable.h>
#import <TBThirdParty/IGListBindable.h>
#import <TBThirdParty/IGListBindingSectionController.h>
#import <TBThirdParty/IGListBindingSectionControllerDataSource.h>
#import <TBThirdParty/IGListBindingSectionControllerSelectionDelegate.h>
#import <TBThirdParty/IGListCollectionContext.h>
#import <TBThirdParty/IGListCollectionView.h>
#import <TBThirdParty/IGListCollectionViewLayout.h>
#import <TBThirdParty/IGListDisplayDelegate.h>
#import <TBThirdParty/IGListExperiments.h>
#import <TBThirdParty/IGListGenericSectionController.h>
#import <TBThirdParty/IGListCollectionViewDelegateLayout.h>
#import <TBThirdParty/IGListReloadDataUpdater.h>
#import <TBThirdParty/IGListScrollDelegate.h>
#import <TBThirdParty/IGListSectionController.h>
#import <TBThirdParty/IGListSingleSectionController.h>
#import <TBThirdParty/IGListStackedSectionController.h>
#import <TBThirdParty/IGListSupplementaryViewSource.h>
#import <TBThirdParty/IGListTransitionDelegate.h>
#import <TBThirdParty/IGListUpdatingDelegate.h>
#import <TBThirdParty/IGListWorkingRangeDelegate.h>
#import <TBThirdParty/IGListCollectionViewDelegateLayout.h>

#endif

// Shared (iOS, tvOS, macOS compatible):

#import <TBThirdParty/IGListAssert.h>
#import <TBThirdParty/IGListBatchUpdateData.h>
#import <TBThirdParty/IGListDiff.h>
#import <TBThirdParty/IGListDiffable.h>
#import <TBThirdParty/IGListExperiments.h>
#import <TBThirdParty/IGListIndexPathResult.h>
#import <TBThirdParty/IGListIndexSetResult.h>
#import <TBThirdParty/IGListMoveIndex.h>
#import <TBThirdParty/IGListMoveIndexPath.h>
#import <TBThirdParty/NSNumber+IGListDiffable.h>
#import <TBThirdParty/NSString+IGListDiffable.h>
