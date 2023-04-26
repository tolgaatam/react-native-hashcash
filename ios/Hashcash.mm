#import "Hashcash.h"

@implementation Hashcash
RCT_EXPORT_MODULE()

-(void)calculateHashcash:
    (double)k identifier:(NSString *)identifier resolve:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject {
    std::string i = std::string([identifier UTF8String]);
    std::string result = hashcash::calculateHashcash(k, i);
    NSString * result2 = [NSString stringWithUTF8String:result.c_str()];
    resolve(result2);
    return;
}

// Don't compile this code when we build for the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativeHashcashSpecJSI>(params);
}
#endif

@end
