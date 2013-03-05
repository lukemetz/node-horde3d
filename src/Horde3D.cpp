#include <Horde3D.h>
#include <Horde3DUtils.h>
#include <node.h>

using namespace v8;
#define JS_FUNC(name) Handle<Value> name(const Arguments &args) \
{\
  HandleScope scope;

#define JS_RETURN_BOOL(expr) return scope.Close(Boolean::New(expr)); }

#define JS_RETURN_INT(expr) return scope.Close(Integer::New(static_cast<int>(expr))); }

#define JS_RETURN_STRING(expr) return scope.Close(String::New(expr)); }

#define JS_RETURN_FLOAT(expr) return scope.Close(Number::New(expr)); }

#define JS_RETURN_UNDF(expr) expr;\
  return scope.Close(Undefined()); }

#define JS_ARG_INT(indx) args[indx]->Int32Value()

#define JS_ARG_FLOAT(indx) args[indx]->NumberValue()

#define JS_ARG_BOOL(indx) args[indx]->Int32Value()

#define JS_ARG_STRING(indx) *String::AsciiValue((args[indx]->ToString()))

namespace h3d
{

  JS_FUNC(getVersionString)
    JS_RETURN_STRING(h3dGetVersionString())

  JS_FUNC(checkExtension)
    JS_RETURN_BOOL(h3dCheckExtension(JS_ARG_STRING(0)))
  
  JS_FUNC(getError)
    JS_RETURN_BOOL(h3dGetError())

  JS_FUNC(init)
    JS_RETURN_BOOL(h3dInit())
  
  JS_FUNC(release)
    JS_RETURN_UNDF(h3dRelease())

  JS_FUNC(render)
    JS_RETURN_UNDF(h3dRender(JS_ARG_INT(0)))

  JS_FUNC(finalizeFrame)
    JS_RETURN_UNDF(h3dFinalizeFrame())
  
  JS_FUNC(clear)
    JS_RETURN_UNDF(h3dClear())

  /*JS_FUNC(getMessage) */

  JS_FUNC(getOption)
    JS_RETURN_UNDF(h3dGetOption(static_cast<H3DOptions::List>(JS_ARG_INT(0))))

  JS_FUNC(setOption)
    JS_RETURN_UNDF(h3dSetOption(static_cast<H3DOptions::List>(JS_ARG_INT(0)), JS_ARG_INT(1)))

  JS_FUNC(getStat)
    JS_RETURN_FLOAT(h3dGetStat(static_cast<H3DStats::List>(JS_ARG_INT(0)), JS_ARG_BOOL(1)))

  /* JS_FUNC(showOverlays) */
  JS_FUNC(clearOverlays)
    JS_RETURN_UNDF(h3dClearOverlays())
  
  JS_FUNC(getResName)
    JS_RETURN_STRING(h3dGetResName(JS_ARG_INT(0)))

  JS_FUNC(getNextResource)
    JS_RETURN_INT(h3dGetNextResource(JS_ARG_INT(0), JS_ARG_INT(1)))

  JS_FUNC(findResource)
    JS_RETURN_INT(h3dFindResource(JS_ARG_INT(0), JS_ARG_STRING(1)))
  
  JS_FUNC(addResource)
    JS_RETURN_INT(h3dAddResource(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2)))
  
  JS_FUNC(cloneResource)
    JS_RETURN_INT(h3dCloneResource(JS_ARG_INT(0), JS_ARG_STRING(1)))
  
  JS_FUNC(removeResource)
    JS_RETURN_INT(h3dRemoveResource(JS_ARG_INT(0)))

  JS_FUNC(isResLoaded)
    JS_RETURN_INT(h3dIsResLoaded(JS_ARG_INT(0)))

  JS_FUNC(loadResource)
    JS_RETURN_BOOL(h3dLoadResource(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2)))

  JS_FUNC(unloadResource)
    JS_RETURN_UNDF(h3dUnloadResource(JS_ARG_INT(0)))

  JS_FUNC(getResElemCount)
    JS_RETURN_INT(h3dGetResElemCount(JS_ARG_INT(0), JS_ARG_INT(1)))

  JS_FUNC(findResElem)
    JS_RETURN_INT(h3dFindResElem(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_STRING(3)))

  JS_FUNC(getResParamI)
    JS_RETURN_INT(h3dGetResParamI(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3)))
  
  JS_FUNC(setResParamI)
    JS_RETURN_UNDF(h3dSetResParamI(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4)))

  JS_FUNC(getResParamF)
    JS_RETURN_FLOAT(h3dGetResParamF(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4)))
  
  JS_FUNC(setResParamF)
    JS_RETURN_UNDF(h3dSetResParamF(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4), JS_ARG_FLOAT(5)))

  JS_FUNC(getResParamStr)
    JS_RETURN_STRING(h3dGetResParamStr(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3)))

  JS_FUNC(setResParamStr)
    JS_RETURN_UNDF(h3dSetResParamStr(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_STRING(4)))

  /* JS_FUNC(mapResStream) */
  /* JS_FUNC(unmapResStream) */

  JS_FUNC(queryUnloadedResource)
    JS_RETURN_INT(h3dQueryUnloadedResource(JS_ARG_INT(0)))

  JS_FUNC(createTexture)
    JS_RETURN_INT(h3dCreateTexture(JS_ARG_STRING(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4)))
  
  JS_FUNC(setShaderPreambles)
    JS_RETURN_UNDF(h3dSetShaderPreambles(JS_ARG_STRING(0), JS_ARG_STRING(1)))

  JS_FUNC(setMaterialUniform)
    JS_RETURN_BOOL(h3dSetMaterialUniform(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_FLOAT(2), JS_ARG_FLOAT(3), JS_ARG_FLOAT(4), JS_ARG_FLOAT(5)))

  JS_FUNC(resizePipelineBuffers)
    JS_RETURN_UNDF(h3dResizePipelineBuffers(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2)))

  /* JS_FUNC(getRenderTargetData) */
  
  JS_FUNC(getNodeType)
    JS_RETURN_INT(h3dGetNodeType(JS_ARG_INT(0)))

  JS_FUNC(getNodeParent)
    JS_RETURN_INT(h3dGetNodeParent(JS_ARG_INT(0)))

  JS_FUNC(setNodeParent)
    JS_RETURN_BOOL(h3dSetNodeParent(JS_ARG_INT(0), JS_ARG_INT(1)))

  JS_FUNC(GetNodeChild)
    JS_RETURN_INT(h3dGetNodeChild(JS_ARG_INT(0), JS_ARG_INT(1)))

  JS_FUNC(addNodes)
    JS_RETURN_INT(h3dAddNodes(JS_ARG_INT(0), JS_ARG_INT(1)))
  
  JS_FUNC(removeNodes)
    JS_RETURN_UNDF(h3dRemoveNode(JS_ARG_INT(0)))
  
  JS_FUNC(checkNodeTransFlag)
    JS_RETURN_BOOL(h3dCheckNodeTransFlag(JS_ARG_INT(0), JS_ARG_BOOL(1)))

  /* JS_FUNC(getNodeTransform) */

  JS_FUNC(setNodeTransform)
    JS_RETURN_UNDF(h3dSetNodeTransform(JS_ARG_INT(0), JS_ARG_FLOAT(1), JS_ARG_FLOAT(2), JS_ARG_FLOAT(3),
                                                      JS_ARG_FLOAT(4), JS_ARG_FLOAT(5), JS_ARG_FLOAT(6),
                                                      JS_ARG_FLOAT(7), JS_ARG_FLOAT(8), JS_ARG_FLOAT(9)))
  /* JS_FUNC(getNodeTransform) */
  /* JS_FUNC(getNodeTransMats)
     JS_FUNC(setNodeTransMats) */
  
    JS_FUNC(getNodeParamI)
    JS_RETURN_INT(h3dGetNodeParamI(JS_ARG_INT(0), JS_ARG_INT(1)))
  
  JS_FUNC(setNodeParamI)
    JS_RETURN_UNDF(h3dSetNodeParamI(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2)))

  JS_FUNC(getNodeParamF)
    JS_RETURN_FLOAT(h3dGetNodeParamF(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2)))
  
  JS_FUNC(setNodeParamF)
    JS_RETURN_UNDF(h3dSetNodeParamF(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_FLOAT(3)))

  JS_FUNC(getNodeParamStr)
    JS_RETURN_STRING(h3dGetNodeParamStr(JS_ARG_INT(0), JS_ARG_INT(1)))

  JS_FUNC(setNodeParamStr)
    JS_RETURN_UNDF(h3dSetNodeParamStr(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_STRING(2)))

  JS_FUNC(getNodeFlags)
    JS_RETURN_INT(h3dGetNodeFlags(JS_ARG_INT(0)))

  JS_FUNC(setNodeFlags)
    JS_RETURN_UNDF(h3dSetNodeFlags(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_BOOL(2)))
  
  /* JS_FUNC(getNodeAABB) */

  JS_FUNC(findNodes)
    JS_RETURN_INT(h3dFindNodes(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2)))

  JS_FUNC(getNodeFindResult)
    JS_RETURN_INT(h3dGetNodeFindResult(JS_ARG_INT(0)))

  JS_FUNC(castRay)
    JS_RETURN_INT(h3dCastRay(JS_ARG_INT(0), JS_ARG_FLOAT(1), JS_ARG_FLOAT(2), JS_ARG_FLOAT(3),
                                            JS_ARG_FLOAT(4), JS_ARG_FLOAT(5), JS_ARG_FLOAT(6),
                                            JS_ARG_INT(7)))
  /* JS_FUNC(getCastRayResults) */ 
 
  JS_FUNC(checkNodeVisibility)
    JS_RETURN_INT(h3dCheckNodeVisibility(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_BOOL(2), JS_ARG_BOOL(3)))
  
  JS_FUNC(addGroupNode)
    JS_RETURN_INT(h3dAddGroupNode(JS_ARG_INT(0), JS_ARG_STRING(1)))

  JS_FUNC(addModelNode)
    JS_RETURN_INT(h3dAddModelNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2)))

  JS_FUNC(setupModelAnimStage)
    JS_RETURN_UNDF(h3dSetupModelAnimStage(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_STRING(4), JS_ARG_BOOL(5)))
  
  JS_FUNC(setModelAnimParams)
    JS_RETURN_UNDF(h3dSetModelAnimParams(JS_ARG_INT(0), JS_ARG_INT(1), JS_ARG_FLOAT(2), JS_ARG_FLOAT(3)))

  JS_FUNC(setModelMorpher)
    JS_RETURN_BOOL(h3dSetModelMorpher(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_FLOAT(2)))

  JS_FUNC(addMeshNode)
    JS_RETURN_INT(h3dAddMeshNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4), JS_ARG_INT(5), JS_ARG_INT(6)))

  JS_FUNC(addJointNode)
    JS_RETURN_INT(h3dAddJointNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(1)))
  
  JS_FUNC(addLightNode)
    JS_RETURN_INT(h3dAddLightNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2), JS_ARG_STRING(3), JS_ARG_STRING(4)))

  JS_FUNC(addCameraNode)
    JS_RETURN_INT(h3dAddCameraNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2)))

  JS_FUNC(setupCameraView)
    JS_RETURN_UNDF(h3dSetupCameraView(JS_ARG_INT(0), JS_ARG_FLOAT(1), JS_ARG_FLOAT(2), JS_ARG_FLOAT(3), JS_ARG_FLOAT(4)))

  /* JS_FUNC(getCameraProjMat) */

  JS_FUNC(addEmitterNode)
    JS_RETURN_INT(h3dAddEmitterNode(JS_ARG_INT(0), JS_ARG_STRING(1), JS_ARG_INT(2), JS_ARG_INT(3), JS_ARG_INT(4), JS_ARG_INT(5)))

  JS_FUNC(advanceEmitterTime)
    JS_RETURN_UNDF(h3dAdvanceEmitterTime(JS_ARG_INT(0), JS_ARG_FLOAT(1)))

  JS_FUNC(hasEmitterFinished)
    JS_RETURN_BOOL(h3dHasEmitterFinished(JS_ARG_INT(0)))
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
    NODE_SET_METHOD(target, "getVersionString", h3d::getVersionString);
    NODE_SET_METHOD(target, "checkExtension", h3d::checkExtension);
    NODE_SET_METHOD(target, "getError", h3d::getError);
    NODE_SET_METHOD(target, "init", h3d::init);
    NODE_SET_METHOD(target, "release", h3d::release);
    NODE_SET_METHOD(target, "render", h3d::render);
    NODE_SET_METHOD(target, "finalizeFrame", h3d::finalizeFrame);
    NODE_SET_METHOD(target, "clear", h3d::clear);
    NODE_SET_METHOD(target, "getOption", h3d::getOption);
    NODE_SET_METHOD(target, "setOption", h3d::setOption);
    NODE_SET_METHOD(target, "getStat", h3d::getStat);
    NODE_SET_METHOD(target, "clearOverlays", h3d::clearOverlays);
    NODE_SET_METHOD(target, "getResName", h3d::getResName);
    NODE_SET_METHOD(target, "getNextResource", h3d::getNextResource);
    NODE_SET_METHOD(target, "findResource", h3d::findResource);
    NODE_SET_METHOD(target, "addResource", h3d::addResource);
    NODE_SET_METHOD(target, "cloneResource", h3d::cloneResource);
    NODE_SET_METHOD(target, "removeResource", h3d::removeResource);
    NODE_SET_METHOD(target, "isResLoaded", h3d::isResLoaded);
    NODE_SET_METHOD(target, "loadResource", h3d::loadResource);
    NODE_SET_METHOD(target, "unloadResource", h3d::unloadResource);
    NODE_SET_METHOD(target, "getResElemCount", h3d::getResElemCount);
    NODE_SET_METHOD(target, "findResElem", h3d::findResElem);
    NODE_SET_METHOD(target, "getResParamI", h3d::getResParamI);
    NODE_SET_METHOD(target, "setResParamI", h3d::setResParamI);
    NODE_SET_METHOD(target, "getResParamF", h3d::getResParamF);
    NODE_SET_METHOD(target, "setResParamF", h3d::setResParamF);
    NODE_SET_METHOD(target, "getResParamStr", h3d::getResParamStr);
    NODE_SET_METHOD(target, "setResParamStr", h3d::setResParamStr);
    NODE_SET_METHOD(target, "queryUnloadedResource", h3d::queryUnloadedResource);
    NODE_SET_METHOD(target, "createTexture", h3d::createTexture);
    NODE_SET_METHOD(target, "setShaderPreambles", h3d::setShaderPreambles);
    NODE_SET_METHOD(target, "setMaterialUniform", h3d::setMaterialUniform);
    NODE_SET_METHOD(target, "resizePipelineBuffers", h3d::resizePipelineBuffers);
    NODE_SET_METHOD(target, "getNodeType", h3d::getNodeType);
    NODE_SET_METHOD(target, "getNodeParent", h3d::getNodeParent);
    NODE_SET_METHOD(target, "setNodeParent", h3d::setNodeParent);
    NODE_SET_METHOD(target, "GetNodeChild", h3d::GetNodeChild);
    NODE_SET_METHOD(target, "addNodes", h3d::addNodes);
    NODE_SET_METHOD(target, "removeNodes", h3d::removeNodes);
    NODE_SET_METHOD(target, "checkNodeTransFlag", h3d::checkNodeTransFlag);
    NODE_SET_METHOD(target, "setNodeTransform", h3d::setNodeTransform);
    NODE_SET_METHOD(target, "setNodeParamI", h3d::setNodeParamI);
    NODE_SET_METHOD(target, "getNodeParamF", h3d::getNodeParamF);;
    NODE_SET_METHOD(target, "setNodeParamF", h3d::setNodeParamF);;
    NODE_SET_METHOD(target, "getNodeParamStr", h3d::getNodeParamStr);;
    NODE_SET_METHOD(target, "setNodeParamStr", h3d::setNodeParamStr);
    NODE_SET_METHOD(target, "getNodeFlags", h3d::getNodeFlags);
    NODE_SET_METHOD(target, "setNodeFlags", h3d::setNodeFlags);
    NODE_SET_METHOD(target, "findNodes", h3d::findNodes);
    NODE_SET_METHOD(target, "getNodeFindResult", h3d::getNodeFindResult);
    NODE_SET_METHOD(target, "castRay", h3d::castRay);
    NODE_SET_METHOD(target, "checkNodeVisibility", h3d::checkNodeVisibility);
    NODE_SET_METHOD(target, "addGroupNode", h3d::addGroupNode);
    NODE_SET_METHOD(target, "addModelNode", h3d::addModelNode);
    NODE_SET_METHOD(target, "setupModelAnimStage", h3d::setupModelAnimStage);
    NODE_SET_METHOD(target, "setModelAnimParams", h3d::setModelAnimParams);
    NODE_SET_METHOD(target, "setModelMorpher", h3d::setModelMorpher);
    NODE_SET_METHOD(target, "addMeshNode", h3d::addMeshNode);
    NODE_SET_METHOD(target, "addJointNode", h3d::addJointNode);
    NODE_SET_METHOD(target, "addLightNode", h3d::addLightNode);
    NODE_SET_METHOD(target, "addCameraNode", h3d::addCameraNode);
    NODE_SET_METHOD(target, "setupCameraView", h3d::setupCameraView);
    NODE_SET_METHOD(target, "addEmitterNode", h3d::addEmitterNode);
    NODE_SET_METHOD(target, "advanceEmitterTime", h3d::advanceEmitterTime);
    NODE_SET_METHOD(target, "hasEmitterFinished", h3d::hasEmitterFinished);

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
