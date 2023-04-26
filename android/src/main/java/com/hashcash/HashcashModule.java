package com.hashcash;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.bridge.Promise;

@ReactModule(name = HashcashModule.NAME)
public class HashcashModule extends NativeHashcashSpec {
  public static final String NAME = "Hashcash";

  public HashcashModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  static {
    System.loadLibrary("cpp");
  }

  private static native String nativeCalculateHashcash(double k, String identifier);

  // Example method
  // See https://reactnative.dev/docs/native-modules-android
  @Override
  public void calculateHashcash(double k, String identifier, Promise promise) {
    promise.resolve(nativeCalculateHashcash(k, identifier));
  }
}
