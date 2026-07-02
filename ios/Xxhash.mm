#import "Xxhash.h"
#import <React/RCTBridge+Private.h>
#import <ReactCommon/RCTTurboModule.h>
#import <React/RCTBridge.h>
#import <React/RCTUtils.h>
#import <jsi/jsi.h>

#ifdef RCT_NEW_ARCH_ENABLED
#import <ReactCommon/RCTTurboModuleWithJSIBindings.h>
#import <ReactCommon/TurboModule.h>
#import <ReactCommon/CallInvoker.h>
#endif

using namespace facebook;

#ifdef RCT_NEW_ARCH_ENABLED
namespace {
class XxhashTurboModule : public facebook::react::TurboModule {
 public:
  XxhashTurboModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker)
      : facebook::react::TurboModule("xxhash", std::move(jsInvoker)) {}
};
} // namespace

@interface Xxhash () <RCTTurboModule, RCTTurboModuleWithJSIBindings>
@end
#endif

@implementation Xxhash
RCT_EXPORT_MODULE(xxhash)

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

+ (BOOL)requiresMainQueueSetup {
  return NO;
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install){
	NSLog(@"Installing JSI bindings for xxhash ...");

#ifdef RCT_NEW_ARCH_ENABLED
  if (self.bridge == nil) {
    return @true;
  }
#endif

	RCTBridge* bridge = self.bridge ?: [RCTBridge currentBridge];
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

#ifdef RCT_NEW_ARCH_ENABLED
- (void)installJSIBindingsWithRuntime:(jsi::Runtime &)runtime
                          callInvoker:(const std::shared_ptr<react::CallInvoker> &)callInvoker {
  xxhash::install(&runtime);
}

- (void)installJSIBindingsWithRuntime:(jsi::Runtime &)runtime {
  xxhash::install(&runtime);
}

- (std::shared_ptr<react::TurboModule>)getTurboModule:(const react::ObjCTurboModule::InitParams &)params {
  return std::make_shared<XxhashTurboModule>(params.jsInvoker);
}
#endif

@end
