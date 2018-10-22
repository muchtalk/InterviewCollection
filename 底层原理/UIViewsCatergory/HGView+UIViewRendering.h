//
//  HGView+UIViewRendering.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"


/*
//!< UIView内容填充模式.
 
typedef NS_ENUM(NSInteger, UIViewContentMode) {
    UIViewContentModeScaleToFill,       //!< 缩放内容到合适比例大小.
    UIViewContentModeScaleAspectFit,    //!< 缩放内容到合适的大小，边界多余部分透明.
    UIViewContentModeScaleAspectFill,   //!< 缩放内容填充到指定大小，边界多余的部分省略.
    UIViewContentModeRedraw,            //!< 重绘视图边界 (需调用 -setNeedsDisplay).
    UIViewContentModeCenter,            //!< 视图保持等比缩放.
    UIViewContentModeTop,               //!< 视图顶部对齐.
    UIViewContentModeBottom,            //!< 视图底部对齐.
    UIViewContentModeLeft,              //!< 视图左侧对齐.
    UIViewContentModeRight,             //!< 视图右侧对齐.
    UIViewContentModeTopLeft,           //!< 视图左上角对齐.
    UIViewContentModeTopRight,          //!< 视图右上角对齐.
    UIViewContentModeBottomLeft,        //!< 视图左下角对齐.
    UIViewContentModeBottomRight,       //!< 视图右下角对齐.
};
 
 
typedef NS_ENUM(NSInteger, UIViewTintAdjustmentMode) {
    UIViewTintAdjustmentModeAutomatic,  //!< 自动的，与父视图相同.
    UIViewTintAdjustmentModeNormal,     //!< 未经修改的.
    UIViewTintAdjustmentModeDimmed,     //!< 饱和、暗淡的原始色.
} NS_ENUM_AVAILABLE_IOS(7_0);
 
*/

@interface HGView (UIViewRendering)


- (void)drawRect:(CGRect)rect;/** 重写drawRect方法，在可以这里进行绘图操作。*/

- (void)setNeedsDisplay;/** 标记整个视图的边界矩形需要重绘, 调用这个方法会自动调用drawRect方法 */
- (void)setNeedsDisplayInRect:(CGRect)rect;/** 标记在指定区域内的视图的边界需要重绘, 调用这个方法会自动调用drawRect方法 */

@property(nonatomic)                 BOOL              clipsToBounds;/** 是否裁剪超出Bounds范围的子控件，默认NO */
@property(nullable, nonatomic,copy)  UIColor          *backgroundColor UI_APPEARANCE_SELECTOR;/** 设置背景颜色，默认nil */
@property(nonatomic)                 CGFloat           alpha;   /** 设置透明度(范围0.0~1.0)，默认1.0 */
@property(nonatomic,getter=isOpaque) BOOL              opaque;  /** 设置是否不透明，默认YES不透明 */
@property(nonatomic)                 BOOL              clearsContextBeforeDrawing;/** 视图重绘前是否先清理以前的内容，默认YES */
@property(nonatomic,getter=isHidden) BOOL              hidden;  /** 设置是否隐藏，默认NO不隐藏 */
@property(nonatomic)                 UIViewContentMode contentMode;/** 内容显示的模式，默认UIViewContentModeScaleToFill */
@property(nonatomic)                 CGRect            contentStretch NS_DEPRECATED_IOS(3_0,6_0) __TVOS_PROHIBITED;/** 拉伸属性，如图片拉伸 */


@property(nullable, nonatomic,strong)          UIView           *maskView NS_AVAILABLE_IOS(8_0);/** 蒙板view */

@property(null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(7_0);/** 改变应用程序的外观的颜色。默认为nil */

@property(nonatomic) UIViewTintAdjustmentMode tintAdjustmentMode NS_AVAILABLE_IOS(7_0);/** 可以使tintColor变暗，因此整个视图层次变暗 */


/** 覆盖这个方法的目的是为了当tintColor改变的时候自定义一些行为 */
- (void)tintColorDidChange NS_AVAILABLE_IOS(7_0);

@end
