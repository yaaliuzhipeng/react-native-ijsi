#import <React/RCTBridgeModule.h>

#ifdef __cplusplus

#import "react-native-ijsi.h"

#endif

@interface Ijsi : NSObject<RCTBridgeModule>
@property (nonatomic, assign) BOOL setBridgeOnMainQueue;
@end
