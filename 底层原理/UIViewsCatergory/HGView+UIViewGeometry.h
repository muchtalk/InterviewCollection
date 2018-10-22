//
//  HGView+UIViewGeometry.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"



/** 自动调整大小方式
typedef NS_OPTIONS(NSUInteger, UIViewAutoresizing) {
    UIViewAutoresizingNone                 = 0,     //!< 不自动调整.
    UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,//!< 自动调整与superView左边的距离，保证与superView右边的距离不变.
    UIViewAutoresizingFlexibleWidth        = 1 << 1,//!< 自动调整自己的宽度，保证与superView左边和右边的距离不变.
    UIViewAutoresizingFlexibleRightMargin  = 1 << 2,//!< 自动调整与superView的右边距离，保证与superView左边的距离不变.
    UIViewAutoresizingFlexibleTopMargin    = 1 << 3,//!< 自动调整与superView顶部的距离，保证与superView底部的距离不变.
    UIViewAutoresizingFlexibleHeight       = 1 << 4,//!< 自动调整自己的高度，保证与superView顶部和底部的距离不变.
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5 //!< 自动调整与superView底部的距离，也就是说，与superView顶部的距离不变.
};
*/

//UIView 几何学
@interface HGView (UIViewGeometry)

@property(nonatomic) CGRect            frame;/** 位置和尺寸(以父控件的左上角为坐标原点(0, 0)) */
@property(nonatomic) CGRect            bounds;/** 位置和尺寸(以自己的左上角为坐标原点(0, 0)) */
@property(nonatomic) CGPoint           center;/** 中心点(以父控件的左上角为坐标原点(0, 0)) */
@property(nonatomic) CGAffineTransform transform;/** 变形属性(平移\缩放\旋转) */
@property(nonatomic) CGFloat           contentScaleFactor NS_AVAILABLE_IOS(4_0);/** 视图内容的缩放比例 */

@property(nonatomic,getter=isMultipleTouchEnabled) BOOL multipleTouchEnabled __TVOS_PROHIBITED;/** 是否支持多点触摸，默认NO */
@property(nonatomic,getter=isExclusiveTouch) BOOL       exclusiveTouch __TVOS_PROHIBITED;/** 是否独占整个Touch事件，默认NO */

- (nullable UIView *)hitTest:(CGPoint)point withEvent:(nullable UIEvent *)event;/** 在指定点上点击测试指定事件 */
- (BOOL)pointInside:(CGPoint)point withEvent:(nullable UIEvent *)event;/** 判断当前的点击或者触摸事件的点是否在当前的view中，默认返回YES */


- (CGPoint)convertPoint:(CGPoint)point toView:(nullable UIView *)view;/** 将像素point由point所在视图转换到目标视图view中，返回在目标视图view中的像素值 */
- (CGPoint)convertPoint:(CGPoint)point fromView:(nullable UIView *)view;/** 将像素point由point所在视图转换到目标视图view中，返回在目标视图view中的像素值 */
- (CGRect)convertRect:(CGRect)rect toView:(nullable UIView *)view;/** 将rect由rect所在视图转换到目标视图view中，返回在目标视图view中的rect */
- (CGRect)convertRect:(CGRect)rect fromView:(nullable UIView *)view;/** 将rect从view中转换到当前视图中，返回在当前视图中的rect */

@property(nonatomic) BOOL               autoresizesSubviews;/** 自动调整子视图尺寸，默认YES则会根据autoresizingMask属性自动调整子视图尺寸 */
@property(nonatomic) UIViewAutoresizing autoresizingMask;/** 自动调整子视图与父视图的位置，默认UIViewAutoresizingNone */

- (CGSize)sizeThatFits:(CGSize)size;/** 返回“最佳”大小适合给定的大小 */

- (void)sizeToFit;/** 调整为刚好合适子视图大小 calls sizeThatFits: with current view bounds and changes bounds size.*/




@end

