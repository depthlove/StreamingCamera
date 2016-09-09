//
//  ViewController.m
//  YFPushStreamingCameraDemo
//
//  Created by suntongmian on 16/6/13.
//  Copyright © 2016年 YunFan. All rights reserved.
//

#import "ViewController.h"

#import "YFPushStreamingCamera.h"

@interface ViewController () <YFPushStreamingCameraDelegate>
{
    YFPushStreamingCamera       *_cameraSource;
    UIView                      *_avCaptureVideoPreview;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _cameraSource = [[YFPushStreamingCamera alloc] init];
    [_cameraSource setupCameraFPS:15 useFront:false useInterfaceOrientation:YES sessionPreset:nil callbackBlock:nil];
    _cameraSource.delegate = self;
    
    _avCaptureVideoPreview = [[UIView alloc] init];
    _avCaptureVideoPreview.frame =  self.view.bounds;
    [self.view addSubview:_avCaptureVideoPreview];
    
    AVCaptureVideoPreviewLayer *previewLayer = nil;
    [_cameraSource getPreviewLayer:&previewLayer];
    previewLayer.frame = self.view.bounds;
    previewLayer.masksToBounds = YES;
    [_avCaptureVideoPreview.layer addSublayer:previewLayer];
}

#pragma mark ------- YFPushStreamingCameraDelegate methods --------
- (void)pushStreamingCameraSourceOutput:(CVPixelBufferRef)pixelBufferRef
{
    NSLog(@"%s", __FUNCTION__);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
