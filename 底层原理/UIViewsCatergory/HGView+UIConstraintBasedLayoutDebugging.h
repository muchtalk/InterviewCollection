//
//  HGView+UIConstraintBasedLayoutDebugging.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UIConstraintBasedLayoutDebugging)


- (NSArray<__kindof NSLayoutConstraint *> *)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);/** 获得实体在不同方向上所有的布局约束 */


#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL hasAmbiguousLayout NS_AVAILABLE_IOS(6_0);/** 可以知道当前视图的布局是否会有歧义 */
#else
- (BOOL)hasAmbiguousLayout NS_AVAILABLE_IOS(6_0);
#endif


- (void)exerciseAmbiguityInLayout NS_AVAILABLE_IOS(6_0);/** 这个方法会随机改变视图的layout到另外一个有效的layout。这样我们就可以很清楚的看到哪一个layout导致了整体的布局约束出现了错误，或者我们应该增加更多的布局约束 */

@end
