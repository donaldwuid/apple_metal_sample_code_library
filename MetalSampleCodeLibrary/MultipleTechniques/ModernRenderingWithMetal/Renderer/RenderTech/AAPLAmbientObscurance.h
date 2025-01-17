/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Header for class which manages state to render an scalable ambient obscurance (SAO) effect.
*/

#import "AAPLConfig.h"

#import <Metal/Metal.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/Foundation.h>

#if USE_SCALABLE_AMBIENT_OBSCURANCE

// Encapsulates the pipeline states and intermediate objects required for
//  Scalable Ambient Obscurance.
@interface AAPLAmbientObscurance : NSObject

// Initializes this object, allocating metal objects from the device based on
//  functions in the library.
- (nonnull instancetype)initWithDevice:(nonnull id<MTLDevice>)device
                                library:(nonnull id<MTLLibrary>)library;

// Writes commands to update the SAO texture using the command buffer, with
// AAPLFrameConstants from the frameDataBuffer with the latest depth data.
- (void)        update:(nonnull id<MTLCommandBuffer>)commandBuffer
       frameDataBuffer:(nonnull id<MTLBuffer>)frameDataBuffer
    cameraParamsBuffer:(nonnull id<MTLBuffer>)cameraParamsBuffer
                 depth:(nonnull id<MTLTexture>)depth
          depthPyramid:(nonnull id<MTLTexture>)depthPyramid;

// Resizes the internal data structures to the required output size.
- (void)resize:(CGSize)size;

// The SAO texture generated by the update.
@property _Nullable id<MTLTexture> texture;

@end

#endif // USE_SCALABLE_AMBIENT_OBSCURANCE
