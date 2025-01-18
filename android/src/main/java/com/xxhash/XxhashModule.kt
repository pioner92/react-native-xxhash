package com.xxhash

import android.util.Log
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.common.annotations.FrameworkAPI

class XxhashModule internal constructor(val context: ReactApplicationContext) :
  ReactContextBaseJavaModule(context) {

    companion object {
    const val NAME = "xxhash"

    init {
          System.loadLibrary("react-native-xxhash")
    }

    @OptIn(FrameworkAPI::class)
    @JvmStatic
    external fun nativeInstall(jsiRuntimePointer: Long)
    }

  private val reactContext = context

  override fun getName(): String {
    return NAME
  }
  
  @OptIn(FrameworkAPI::class)
  @ReactMethod(isBlockingSynchronousMethod = true)
  fun install():Boolean  {
    Log.d("xxhash", "install() called")

    nativeInstall(
      context.javaScriptContextHolder!!.get(),
    )

    return true
  }
}
