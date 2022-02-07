package com.reactnativeijsi;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = IjsiModule.NAME)
public class IjsiModule extends ReactContextBaseJavaModule {
    public static final String NAME = "Ijsi";
    public static final String TAG = "IjsiTAG";

    public IjsiModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    /**
     * Native Methods
     */
    public native void nativeInstall(long jsi);

    @ReactMethod(isBlockingSynchronousMethod = true)
    public void init() {
        Log.i(TAG, "Ijsi init方法开始执行");
        try {
            System.loadLibrary("ijsi");
            JavaScriptContextHolder contextHolder = getReactApplicationContext().getJavaScriptContextHolder();
            long jsi = contextHolder.get();
            if(jsi != 0) {
                nativeInstall(jsi);
            }
        } catch (Exception ignored) {}
    }
}
