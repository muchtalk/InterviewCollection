//
//  HGView+UIStateRestoration.h
//  底层原理
//
//  Created by HG on 2018/10/22.
//  Copyright © 2018年 HG. All rights reserved.
//

#import "HGView.h"

#pragma mark - View状态保存恢复

@interface HGView (UIStateRestoration)


@property (nullable, nonatomic, copy) NSString *restorationIdentifier NS_AVAILABLE_IOS(6_0);/** 标示是否支持保存,恢复视图状态信息 */

- (void) encodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);/** 保存视图状态相关的信息 */
- (void) decodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);/** 恢复和保持视图状态相关信息 */


@end
