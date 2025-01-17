#import "Xxhash.h"
#import <React/RCTBridge+Private.h>
#import <ReactCommon/RCTTurboModule.h>
#import <React/RCTBridge.h>
#import <React/RCTUtils.h>
#import <jsi/jsi.h>

@implementation Xxhash
RCT_EXPORT_MODULE()

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

+ (BOOL)requiresMainQueueSetup {
  return YES;
}


- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;

  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
  if (!cxxBridge.runtime) {
    return;
  }

  auto jsiRuntime =  (jsi::Runtime*)cxxBridge.runtime;

  xxhash::install(jsiRuntime);
}



@end
