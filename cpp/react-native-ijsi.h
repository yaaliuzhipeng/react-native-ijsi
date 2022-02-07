#ifndef REACT_NATIVE_IJSI_H
#define REACT_NATIVE_IJSI_H

#include "jsi/jsi.h"

using namespace facebook::jsi;
using namespace std;

namespace ijsi {
    void install(Runtime &jsiRuntime);
}

#endif
