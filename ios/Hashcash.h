#ifdef __cplusplus
#import "react-native-hashcash.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNHashcashSpec.h"

@interface Hashcash : NSObject <NativeHashcashSpec>
#else
#import <React/RCTBridgeModule.h>

@interface Hashcash : NSObject <RCTBridgeModule>
#endif

@end
