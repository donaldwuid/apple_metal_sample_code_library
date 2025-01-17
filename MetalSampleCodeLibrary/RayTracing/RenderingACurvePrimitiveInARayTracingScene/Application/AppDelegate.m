/*
See the LICENSE.txt file for this sample’s licensing information.

Abstract:
The implementation of the cross-platform app delegate.
*/

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

#if !TARGET_OS_IPHONE
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}
#else
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    return YES;
}
#endif

@end
