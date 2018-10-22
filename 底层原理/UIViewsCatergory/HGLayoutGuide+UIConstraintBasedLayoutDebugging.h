//
//  HGLayoutGuide+UIConstraintBasedLayoutDebugging.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGLayoutGuide.h"

@interface HGLayoutGuide (UIConstraintBasedLayoutDebugging)


/** 获得实体在不同方向上所有的布局约束 */
- (NSArray<__kindof NSLayoutConstraint *> *)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(10_0);

/** 可以知道当前视图的布局是否会有歧义 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL hasAmbiguousLayout NS_AVAILABLE_IOS(10_0);
#else
- (BOOL)hasAmbiguousLayout NS_AVAILABLE_IOS(10_0);
#endif
@end


