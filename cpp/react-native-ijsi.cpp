#include "react-native-ijsi.h"

namespace ijsi {
    void install(Runtime &jsiRuntime) {
        auto greet = Function::createFromHostFunction(
                jsiRuntime,
                PropNameID::forAscii(jsiRuntime,"greet"),
                0,
                [](Runtime &runtime,const Value &,const Value *,size_t count) -> Value {
                   string words = "hello, this is value from jni";
                   return Value(runtime,String::createFromUtf8(runtime,words));
                });
        jsiRuntime.global().setProperty(jsiRuntime,"greet",move(greet));
    }
}
