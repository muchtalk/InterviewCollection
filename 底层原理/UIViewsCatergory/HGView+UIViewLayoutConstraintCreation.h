//
//  HGView+UIViewLayoutConstraintCreation.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"
@class NSLayoutXAxisAnchor,NSLayoutYAxisAnchor,NSLayoutDimension;

@interface HGView (UIViewLayoutConstraintCreation)

/* Constraint creation conveniences. See NSLayoutAnchor.h for details.
 */


@property(readonly, strong) NSLayoutXAxisAnchor *leadingAnchor NS_AVAILABLE_IOS(9_0);/* 布局视图的前缘框的布局锚点 */
@property(readonly, strong) NSLayoutXAxisAnchor *trailingAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的后缘边框的布局锚点 */
@property(readonly, strong) NSLayoutXAxisAnchor *leftAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的左边框的布局锚点 */
@property(readonly, strong) NSLayoutXAxisAnchor *rightAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的右边框的布局锚点 */
@property(readonly, strong) NSLayoutYAxisAnchor *topAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的顶边框的布局锚点 */
@property(readonly, strong) NSLayoutYAxisAnchor *bottomAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的顶边框的布局锚点 */
@property(readonly, strong) NSLayoutDimension *widthAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的宽度 */
@property(readonly, strong) NSLayoutDimension *heightAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的高度 */
@property(readonly, strong) NSLayoutXAxisAnchor *centerXAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的水平中心轴 */
@property(readonly, strong) NSLayoutYAxisAnchor *centerYAnchor NS_AVAILABLE_IOS(9_0);/** 布局视图的垂直中心轴 */
@property(readonly, strong) NSLayoutYAxisAnchor *firstBaselineAnchor NS_AVAILABLE_IOS(9_0);/** 一个代表对视图中的文本的最高线基线布置锚 */
@property(readonly, strong) NSLayoutYAxisAnchor *lastBaselineAnchor NS_AVAILABLE_IOS(9_0);/** 一个代表对视图中的文本的最低线基线布置锚 */



@end

