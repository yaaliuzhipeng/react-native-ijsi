#import "Ijsi.h"
#import "react-native-ijsi.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <sys/utsname.h>
#import <jsi/jsi.h>

using namespace facebook::jsi;
using namespace std;

@implementation Ijsi

RCT_EXPORT_MODULE(Ijsi)

+ (BOOL) requiresMainQueueSetup {
    return YES;
}

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(init){
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)bridge;
    
    auto jsiRuntime = (Runtime*) cxxBridge.runtime;
    
    ijsi::install(*(Runtime *) jsiRuntime);
    return self;
}

@end
