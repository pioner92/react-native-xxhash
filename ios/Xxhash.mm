#import "Xxhash.h"
#import <React/RCTBridge+Private.h>
#import <ReactCommon/RCTTurboModule.h>
#import <React/RCTBridge.h>
#import <React/RCTUtils.h>
#import <jsi/jsi.h>

@implementation Xxhash
RCT_EXPORT_MODULE(xxhash)

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install){
	NSLog(@"Installing JSI bindings for xxhash ...");
	RCTBridge* bridge = [RCTBridge currentBridge];
	RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;

	if (cxxBridge == nil) {
		return @false;
	}

	auto jsiRuntime = (jsi::Runtime*) cxxBridge.runtime;
	if (jsiRuntime == nil) {
		return @false;
	}

	xxhash::install(jsiRuntime);

	return @true;
}


@end
