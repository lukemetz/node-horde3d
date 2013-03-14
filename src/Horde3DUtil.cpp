#include "common.h"
#include <Horde3D.h>
#include <Horde3DUtils.h>

using namespace v8;

namespace h3dut {
  JS_FUNC(loadResourcesFromDisk)
    JS_RETURN_UNDF(h3dutLoadResourcesFromDisk(JS_ARG_STRING(0)))
  JS_FUNC(dumpMessages)
    JS_RETURN_UNDF(h3dutDumpMessages())
  JS_FUNC(screenshot)
    JS_RETURN_BOOL(h3dutScreenshot(JS_ARG_STRING(0)))
  JS_FUNC(pickNode)
    JS_RETURN_INT(h3dutPickNode(JS_ARG_INT(0), JS_ARG_FLOAT(1), JS_ARG_FLOAT(2)))
}

extern "C" {
  void init(Handle<Object> target)
  {
    HandleScope scope;
    NODE_SET_METHOD(target, "loadResourcesFromDisk", h3dut::loadResourcesFromDisk);
    NODE_SET_METHOD(target, "dumpMessages", h3dut::dumpMessages);
    NODE_SET_METHOD(target, "screenshot", h3dut::screenshot);
    NODE_SET_METHOD(target, "pickNode", h3dut::pickNode);
  }
  NODE_MODULE(horde3dut, init)
}
