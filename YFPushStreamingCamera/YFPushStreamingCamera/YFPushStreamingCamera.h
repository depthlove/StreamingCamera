//
//  YFPushStreamingCamera.h
//  YFPushStreamingCamera
//
//  Created by suntongmian@163.com
//  Copyright © 2015年 YunFan. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  使用MRC（-fno-objc-arc）
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <CoreVideo/CoreVideo.h>
#import <AVFoundation/AVFoundation.h>

typedef void (^CallbackBlock)(void);

@class YFPushStreamingCamera;

typedef NS_ENUM(NSInteger, YFPushStreamingCameraState)
{
    YFPushStreamingCameraStateFront, // 前置摄像头
    YFPushStreamingCameraStateBack   // 后置摄像头
};

@protocol YFPushStreamingCameraDelegate <NSObject>
@required
/**
 * @brief   摄像头图像数据输出回调
 * @param   INPUT   pixelBufferRef          摄像头图像数据
 * @param   INPUT   pixelBufferSize         摄像头图像数据的size
 * @return  无返回
 */
- (void)pushStreamingCameraSourceOutput:(CVPixelBufferRef)pixelBufferRef;
@end

@interface YFPushStreamingCamera : NSObject

@property (nonatomic, assign) YFPushStreamingCameraState cameraState; // 前后摄像头切换
@property (nonatomic, assign) BOOL cameraTorch; // YES：闪光灯打开，NO：关闭

@property (nonatomic, assign)id<YFPushStreamingCameraDelegate> delegate;

/**
 * @brief   获取摄像头视图AVCaptureVideoPreviewLayer
 * @param   INPUT   outAVCaptureVideoPreviewLayer       摄像头视图的引用
 * @return  无返回
 */
- (void)getPreviewLayer:(AVCaptureVideoPreviewLayer**)outAVCaptureVideoPreviewLayer;

/**
 * @brief   设置摄像头的参数
 * @param   INPUT   fps                         帧率
 * @param   INPUT   useFront                    front-facing camera
 * @param   INPUT   useInterfaceOrientation     video capture旋转
 * @param   INPUT   sessionPreset               capture session的名称
 * @param   INPUT   callbackBlock               回调
 * @return  无返回
 */
- (void)setupCameraFPS:(int)fps
              useFront:(bool)useFront
useInterfaceOrientation:(bool)useInterfaceOrientation
         sessionPreset:(NSString*)sessionPreset
         callbackBlock:(CallbackBlock)callbackBlock;

/**
 * @brief   返回旋转锁定的状态
 * @return  如果locked，返回true
 */
- (bool)orientationLocked;

/**
 * @brief   Capture Session
 * @param   INPUT   pixelBufferRef   相机捕获的图像数据
 * @return  无返回
 */
- (void)bufferCaptured:(CVPixelBufferRef)pixelBufferRef;

/**
 * @brief   Device/Interface 旋转事件
 * @return  无返回
 */
- (void)reorientCamera;
@end
