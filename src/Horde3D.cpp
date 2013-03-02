#include <Horde3D.h>
#include <Horde3DUtils.h>
#include <node.h>

using namespace v8;

namespace h3d
{
  Handle<Value> init(const Arguments &args)
  {
    HandleScope scope;
    return scope.Close(Boolean::New(h3dInit()==1));
  }

  Handle<Value> addResource(const Arguments &args)
  {
    HandleScope scope;
    String::AsciiValue str(args[1]->ToString());
    H3DRes res = h3dAddResource(args[0]->Int32Value(), *str, args[2]->Int32Value());
    Local<Integer> ret = Integer::New(static_cast<int>(res));
    return scope.Close(ret);
  }

  Handle<Value> setOption(const Arguments &args)
  {
    HandleScope scope;
    h3dSetOption(static_cast<H3DOptions::List>(args[0]->Int32Value()), args[1]->Int32Value());
    return scope.Close(Undefined());
  }

  Handle<Value> addNodes(const Arguments &args)
  {
    HandleScope scope;
    H3DNode node = h3dAddNodes(args[0]->Int32Value(), args[1]->Int32Value());
    Local<Integer> ret = Integer::New(static_cast<int>(node));
    return scope.Close(ret);
  }

  Handle<Value> addCameraNode(const Arguments &args)
  {
    HandleScope scope;
    String::AsciiValue str(args[1]->ToString());
    H3DNode node = h3dAddCameraNode(args[0]->Int32Value(), *str, args[2]->Int32Value());
    Local<Integer> ret = Integer::New(static_cast<int>(node));
    return scope.Close(ret);
  }

  Handle<Value> setupCameraView(const Arguments &args)
  {
    HandleScope scope;
    h3dSetupCameraView(args[0]->Int32Value(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue(), args[4]->NumberValue());
    return scope.Close(Undefined());
  }

  Handle<Value> resizePipelineBuffers(const Arguments &args)
  {
    HandleScope scope;
    h3dResizePipelineBuffers(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value());
    return scope.Close(Undefined());
  }

  Handle<Value> addLightNode(const Arguments &args)
  {
    HandleScope scope;
    String::AsciiValue name (args[1]->ToString());
    //TODO fill in names of these
    String::AsciiValue str1(args[3]->ToString());
    String::AsciiValue str2(args[4]->ToString());
    H3DNode node = h3dAddLightNode(args[0]->Int32Value(), *name, args[2]->Int32Value(), *str1, *str2);
    Local<Integer> ret = Integer::New(static_cast<int>(node));
    return scope.Close(ret);
  }

  Handle<Value> setNodeParamF(const Arguments &args)
  {
    HandleScope scope;
    h3dSetNodeParamF(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->NumberValue());
    return scope.Close(Undefined());
  }

  Handle<Value> setNodeParamI(const Arguments &args)
  {
    HandleScope scope;
    h3dSetNodeParamI(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value());
    return scope.Close(Undefined());
  }

  Handle<Value> render(const Arguments &args)
  {
    HandleScope scope;
    h3dRender(args[0]->Int32Value());
    return scope.Close(Undefined());
  }

  Handle<Value> finalizeFrame(const Arguments &args)
  {
    HandleScope scope;
    h3dFinalizeFrame();
    return scope.Close(Undefined());
  }

  Handle<Value> clearOverlays(const Arguments &args)
  {
    HandleScope scope;
    h3dClearOverlays();
    return scope.Close(Undefined());
  }


  Handle<Value> setNodeTransform(const Arguments &args)
  {
    HandleScope scope;
    int res = args[0]->Int32Value();
    double px = args[1]->NumberValue();
    double py = args[2]->NumberValue();
    double pz = args[3]->NumberValue();

    double rx = args[4]->NumberValue();
    double ry = args[5]->NumberValue();
    double rz = args[6]->NumberValue();

    double sx = args[7]->NumberValue();
    double sy = args[8]->NumberValue();
    double sz = args[9]->NumberValue();

    h3dSetNodeTransform(res, px, py, pz, rx, ry, rz, sx, sy, sz);
    return scope.Close(Undefined());
  }

  //Utility functions
  Handle<Value> loadResourcesFromDisk(const Arguments &args)
  {
    HandleScope scope;
    String::AsciiValue str(args[0]->ToString());
    h3dutLoadResourcesFromDisk(*str);
    return scope.Close(Undefined());
  }

  Handle<Value> dumpMessages(const Arguments &args)
  {
    HandleScope scope;
    h3dutDumpMessages();
    return scope.Close(Undefined());
  }

}

extern "C" {
  void init(Handle<Object> target)
  {
    HandleScope scope;

    NODE_SET_METHOD(target, "init", h3d::init);
    NODE_SET_METHOD(target, "setOption", h3d::setOption);
    NODE_SET_METHOD(target, "addResource", h3d::addResource);
    NODE_SET_METHOD(target, "addNodes", h3d::addNodes);
    NODE_SET_METHOD(target, "addCameraNode", h3d::addCameraNode);
    NODE_SET_METHOD(target, "addLightNode", h3d::addLightNode);
    NODE_SET_METHOD(target, "setNodeTransform", h3d::setNodeTransform);
    NODE_SET_METHOD(target, "setNodeParamF", h3d::setNodeParamF);
    NODE_SET_METHOD(target, "setNodeParamI", h3d::setNodeParamI);
    
    NODE_SET_METHOD(target, "render", h3d::render);
    NODE_SET_METHOD(target, "finalizeFrame", h3d::finalizeFrame);
    NODE_SET_METHOD(target, "clearOverlays", h3d::clearOverlays);
    
    NODE_SET_METHOD(target, "setupCameraView", h3d::setupCameraView);
    NODE_SET_METHOD(target, "resizePipelineBuffers", h3d::resizePipelineBuffers);

    //utility functions
    NODE_SET_METHOD(target, "loadResourcesFromDisk", h3d::loadResourcesFromDisk);
    NODE_SET_METHOD(target, "dumpMessages", h3d::dumpMessages);


    //Constants
    //H3DOptions
    target->Set(String::New("LoadTextures"), Integer::New(H3DOptions::LoadTextures));
    target->Set(String::New("DebugViewMode"), Integer::New(H3DOptions::DebugViewMode));
    target->Set(String::New("DebugViewMode"), Integer::New(H3DOptions::WireframeMode));
    //H3DResTypes
    target->Set(String::New("Pipeline"), Integer::New(H3DResTypes::Pipeline));
    target->Set(String::New("Material"), Integer::New(H3DResTypes::Material));
    target->Set(String::New("SceneGraph"), Integer::New(H3DResTypes::SceneGraph));
    target->Set(String::New("Animation"), Integer::New(H3DResTypes::Animation));
    
    //H3DCamera
    target->Set(String::New("ViewportXI"), Integer::New(H3DCamera::ViewportXI));
    target->Set(String::New("ViewportYI"), Integer::New(H3DCamera::ViewportYI));
    target->Set(String::New("ViewportWidthI"), Integer::New(H3DCamera::ViewportWidthI));
    target->Set(String::New("ViewportHeightI"), Integer::New(H3DCamera::ViewportHeightI));
    
    
    target->Set(String::New("RootNode"), Integer::New(H3DRootNode));

  }
  NODE_MODULE(horde3d, init)
}
