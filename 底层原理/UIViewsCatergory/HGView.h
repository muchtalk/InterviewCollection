//
//  HGView.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import <UIKit/UIKit.h>

/*
typedef NS_ENUM(NSInteger, UISemanticContentAttribute) {
    UISemanticContentAttributeUnspecified = 0,  //!< 未指定，默认值
    UISemanticContentAttributePlayback,         //!< 打开/ RW / FF等播放控制按钮
    UISemanticContentAttributeSpatial,          //!< 控制导致某种形式的定向改变UI中,如分段控制文本对齐方式或在游戏中方向键
    UISemanticContentAttributeForceLeftToRight, //!< 视图总是从左向右布局.
    UISemanticContentAttributeForceRightToLeft  //!< 视图总是从右向左布局.
} NS_ENUM_AVAILABLE_IOS(9_0);
*/

@protocol UICoordinateSpace <NSObject>

- (CGPoint)convertPoint:(CGPoint)point toCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);//将像素point由point所在视图转换到目标视图view中，返回在目标视图view中的像素值
- (CGPoint)convertPoint:(CGPoint)point fromCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);//将像素point由point所在视图转换到目标视图view中，返回在目标视图view中的像素值
- (CGRect)convertRect:(CGRect)rect toCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);//将rect由rect所在视图转换到目标视图view中，返回在目标视图view中的rect
- (CGRect)convertRect:(CGRect)rect fromCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);// 将rect从view中转换到当前视图中，返回在当前视图中的rect

@property (readonly, nonatomic) CGRect bounds NS_AVAILABLE_IOS(8_0);/** 获取bounds */

@end


@class UIBezierPath, UIEvent, UIWindow, UIViewController, UIColor, UIGestureRecognizer, UIMotionEffect, CALayer, UILayoutGuide;

@interface HGView : UIView <NSCoding, UIAppearance, UIAppearanceContainer, UIDynamicItem, UITraitEnvironment, UICoordinateSpace, UIFocusItem, CALayerDelegate>//UIView 遵循的协议


#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) Class layerClass;/** 返回主layer所使用的类 */
#else
+ (Class)layerClass;
#endif


- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;/** 通过Frame初始化UI对象 */
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;/** 用于xib初始化 */


@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;/** 设置用户交互，默认YES允许用户交互 */
@property(nonatomic)                                 NSInteger tag;     /** 控件标记(父控件可以通过tag找到对应的子控件)，默认为0 */
@property(nonatomic,readonly,strong)                 CALayer  *layer; /** 视图图层(可以用来设置圆角效果/阴影效果) */

/** 返回是否可以成为焦点, 默认NO */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic,readonly) BOOL canBecomeFocused NS_AVAILABLE_IOS(9_0);
#else
- (BOOL)canBecomeFocused NS_AVAILABLE_IOS(9_0);
#endif

@property (readonly, nonatomic, getter=isFocused) BOOL focused NS_AVAILABLE_IOS(9_0);/** 是否可以被聚焦 */
@property (nonatomic) UISemanticContentAttribute semanticContentAttribute NS_AVAILABLE_IOS(9_0);/** 左右滑动翻转效果 */

/** 获取视图的方向 */
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute NS_AVAILABLE_IOS(9_0);

/** 获取相对于指定视图的界面方向 */
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)semanticContentAttribute relativeToLayoutDirection:(UIUserInterfaceLayoutDirection)layoutDirection NS_AVAILABLE_IOS(10_0);

/** 返回即时内容的布局的方向 */
@property (readonly, nonatomic) UIUserInterfaceLayoutDirection effectiveUserInterfaceLayoutDirection NS_AVAILABLE_IOS(10_0);

@end
