//
//  HGView+UIConstraintBasedLayoutLayering.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

@interface HGView (UIConstraintBasedLayoutLayering)

- (CGRect)alignmentRectForFrame:(CGRect)frame NS_AVAILABLE_IOS(6_0);/** 返回给定框架的视图的对齐矩阵 */
- (CGRect)frameForAlignmentRect:(CGRect)alignmentRect NS_AVAILABLE_IOS(6_0);/** 返回给定对齐矩形的视图的frame */

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) UIEdgeInsets alignmentRectInsets NS_AVAILABLE_IOS(6_0);/** 返回从视图的frame上定义的对齐矩阵的边框 */
#else
- (UIEdgeInsets)alignmentRectInsets NS_AVAILABLE_IOS(6_0);
#endif

/** 返回满足基线约束条件的视图 */
- (UIView *)viewForBaselineLayout NS_DEPRECATED_IOS(6_0, 9_0, "Override -viewForFirstBaselineLayout or -viewForLastBaselineLayout as appropriate, instead") __TVOS_PROHIBITED;

@property(readonly,strong) UIView *viewForFirstBaselineLayout NS_AVAILABLE_IOS(9_0);/** 返回用于满足第一基线约束的视图 */
@property(readonly,strong) UIView *viewForLastBaselineLayout NS_AVAILABLE_IOS(9_0);/** 返回用于满足上次基线约束的视图 */

UIKIT_EXTERN const CGFloat UIViewNoIntrinsicMetric NS_AVAILABLE_IOS(6_0); // -1

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) CGSize intrinsicContentSize NS_AVAILABLE_IOS(6_0);/** 返回接收对象的原本大小 */
#else
- (CGSize)intrinsicContentSize NS_AVAILABLE_IOS(6_0);
#endif

- (void)invalidateIntrinsicContentSize NS_AVAILABLE_IOS(6_0);/** 废除视图原本内容的size */

- (UILayoutPriority)contentHuggingPriorityForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);/** 设置当视图要变大时，视图的压缩改变方式，返回一个优先权（确定view有多大的优先级阻止自己变大） */

- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);/** 设置放先权 */

- (UILayoutPriority)contentCompressionResistancePriorityForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);/** 设置当视图要变小时，视图的压缩改变方式，是水平缩小还是垂直缩小，并返回一个优先权（确定有多大的优先级阻止自己变小） */

- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);/** 设置优先权 */
@end

