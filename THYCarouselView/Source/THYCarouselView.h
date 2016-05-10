//
//  THYCarouselView.h
//  THYCarouselView
//
//  Created by tianhy on 16/5/10.
//  Copyright © 2016年 tianhy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class THYCarouselView;
@protocol THYCarouselViewDelegate <NSObject>
/**
 *  轮播视图，将要滚动时的回调
 *
 *  @param carouseView 轮播视图
 *  @param pageIndex 即将要滚动的页面的索引
 */
- (void)carouseView:(THYCarouselView * _Nonnull )carouseView willMoveToPage:(NSInteger)pageIndex;

/**
 *  轮播视图滚动完成时的回调
 *
 *  @param carouseView 轮播视图
 *  @param pageIndex   当前的页面索引
 */
- (void)carouseView:(THYCarouselView * _Nonnull )carouseView didMoveToPage:(NSInteger)pageIndex;

/**
 *  用户手动划动轮播视图时的回调
 */
- (void)userDidScroll;

@end

@interface THYCarouselView : NSObject

@property (nullable, nonatomic, weak) id<THYCarouselViewDelegate> delegate;
/**
 *  必传参数，待显示图片的数据源
 */
@property (nonnull, nonatomic, strong) NSArray *imageURLs;

/**
 *  占位图，当网络图片未下载完成时，展示
 */
@property (nullable, nonatomic, strong) UIImage *placeholder;

/**
 *  标示是否自动滚动（默认支持）
 */
@property (nonatomic, assign) BOOL autoScroller;

/**
 *  标示是否显示默认的page control视图(默认显示)
 */
@property (nonatomic, assign) BOOL showPageControl;

/**
 *  是否支持循环滚动（这个参数只能在视图创建时传入，视图显示过程中，修改无效，默认支持）
 */
@property (nonatomic, assign) BOOL loopScroll;

/**
 *  开始自动轮播
 */
- (void)startAutoScroll;

/**
 * 停止自动轮播
 */
- (void)stopAutoScroll;

/**
 *  返回当前的索引
 *
 *  @return 当前索引
 */
- (NSInteger)currentIndex;


@end
