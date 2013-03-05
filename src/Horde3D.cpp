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

namespace globals {
    Persistent<FunctionTemplate> H3DOptions, H3DStats, H3DResTypes,
      H3DResFlags, H3DFormats, H3DGeoRes, H3DAnimRes, H3DMatRes,
      H3DShaderRes, H3DTexRes, H3DPartEffRes, H3DPipeRes, H3DNodeTypes,
      H3DNodeFlags, H3DNodeParams, H3DModel, H3DMesh, H3DJoint, H3DLight, H3DCamera, H3DEmitter;
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

    #define BEGIN_TYPE(name) { \
    Local<FunctionTemplate> function_template = FunctionTemplate::New();\
    globals::name = Persistent<FunctionTemplate>::New(function_template); \
    globals::name->InstanceTemplate()->SetInternalFieldCount(1); \
    globals::name->SetClassName(String::New(#name));
    
    #define SET_CONST(group, name) \
      globals::group->Set(String::NewSymbol(#name), Integer::New(group::name), \
        static_cast<PropertyAttribute>(v8::ReadOnly | v8::DontDelete));

    #define END_TYPE(name) \
      target->Set(String::New(#name), globals::name->GetFunction()); \
    }

    BEGIN_TYPE(H3DOptions)
      SET_CONST(H3DOptions, MaxLogLevel)
      SET_CONST(H3DOptions, MaxNumMessages)
      SET_CONST(H3DOptions, TrilinearFiltering)
      SET_CONST(H3DOptions, MaxAnisotropy)
      SET_CONST(H3DOptions, TexCompression)
      SET_CONST(H3DOptions, SRGBLinearization)
      SET_CONST(H3DOptions, LoadTextures)
      SET_CONST(H3DOptions, FastAnimation)
      SET_CONST(H3DOptions, ShadowMapSize)
      SET_CONST(H3DOptions, SampleCount)
      SET_CONST(H3DOptions, WireframeMode)
      SET_CONST(H3DOptions, DebugViewMode)
      SET_CONST(H3DOptions, DumpFailedShaders)
      SET_CONST(H3DOptions, GatherTimeStats)
    END_TYPE(H3DOptions)
    BEGIN_TYPE(H3DStats)
      SET_CONST(H3DStats, TriCount)
      SET_CONST(H3DStats, BatchCount)
      SET_CONST(H3DStats, LightPassCount)
      SET_CONST(H3DStats, FrameTime)
      SET_CONST(H3DStats, AnimationTime)
      SET_CONST(H3DStats, GeoUpdateTime)
      SET_CONST(H3DStats, ParticleSimTime)
      SET_CONST(H3DStats, FwdLightsGPUTime)
      SET_CONST(H3DStats, DefLightsGPUTime)
      SET_CONST(H3DStats, ShadowsGPUTime)
      SET_CONST(H3DStats, ParticleGPUTime)
      SET_CONST(H3DStats, TextureVMem)
      SET_CONST(H3DStats, GeometryVMem)
    END_TYPE(H3DStats)
    BEGIN_TYPE(H3DResTypes)
      SET_CONST(H3DResTypes, Undefined)
      SET_CONST(H3DResTypes, SceneGraph)
      SET_CONST(H3DResTypes, Geometry)
      SET_CONST(H3DResTypes, Animation)
      SET_CONST(H3DResTypes, Material)
      SET_CONST(H3DResTypes, Code)
      SET_CONST(H3DResTypes, Shader)
      SET_CONST(H3DResTypes, Texture)
      SET_CONST(H3DResTypes, ParticleEffect)
      SET_CONST(H3DResTypes, Pipeline)
    END_TYPE(H3DResTypes)
    BEGIN_TYPE(H3DResFlags)
      SET_CONST(H3DResFlags, NoQuery)
      SET_CONST(H3DResFlags, NoTexCompression)
      SET_CONST(H3DResFlags, NoTexMipmaps)
      SET_CONST(H3DResFlags, TexCubemap)
      SET_CONST(H3DResFlags, TexDynamic)
      SET_CONST(H3DResFlags, TexRenderable)
      SET_CONST(H3DResFlags, TexSRGB)
    END_TYPE(H3DResFlags)
    BEGIN_TYPE(H3DFormats)
      SET_CONST(H3DFormats, Unknown)
      SET_CONST(H3DFormats, TEX_BGRA8)
      SET_CONST(H3DFormats, TEX_DXT1)
      SET_CONST(H3DFormats, TEX_DXT3)
      SET_CONST(H3DFormats, TEX_DXT5)
      SET_CONST(H3DFormats, TEX_RGBA16F)
      SET_CONST(H3DFormats, TEX_RGBA32F)
    END_TYPE(H3DFormats)
    BEGIN_TYPE(H3DGeoRes)
      SET_CONST(H3DGeoRes, GeometryElem)
      SET_CONST(H3DGeoRes, GeoIndexCountI)
      SET_CONST(H3DGeoRes, GeoVertexCountI)
      SET_CONST(H3DGeoRes, GeoIndices16I)
      SET_CONST(H3DGeoRes, GeoIndexStream)
      SET_CONST(H3DGeoRes, GeoVertPosStream)
      SET_CONST(H3DGeoRes, GeoVertTanStream)
      SET_CONST(H3DGeoRes, GeoVertStaticStream)
    END_TYPE(H3DGeoRes)
    BEGIN_TYPE(H3DAnimRes)
      SET_CONST(H3DAnimRes, EntityElem)
      SET_CONST(H3DAnimRes, EntFrameCountI)
    END_TYPE(H3DAnimRes)
    BEGIN_TYPE(H3DMatRes)
      SET_CONST(H3DMatRes, MaterialElem)
      SET_CONST(H3DMatRes, SamplerElem)
      SET_CONST(H3DMatRes, UniformElem)
      SET_CONST(H3DMatRes, MatClassStr)
      SET_CONST(H3DMatRes, MatLinkI)
      SET_CONST(H3DMatRes, MatShaderI)
      SET_CONST(H3DMatRes, SampNameStr)
      SET_CONST(H3DMatRes, SampTexResI)
      SET_CONST(H3DMatRes, UnifNameStr)
      SET_CONST(H3DMatRes, UnifValueF4)
    END_TYPE(H3DMatRes)
    BEGIN_TYPE(H3DShaderRes)
      SET_CONST(H3DShaderRes, ContextElem)
      SET_CONST(H3DShaderRes, SamplerElem)
      SET_CONST(H3DShaderRes, UniformElem)
      SET_CONST(H3DShaderRes, ContNameStr)
      SET_CONST(H3DShaderRes, SampNameStr)
      SET_CONST(H3DShaderRes, UnifNameStr)
      SET_CONST(H3DShaderRes, UnifSizeI)
      SET_CONST(H3DShaderRes, UnifDefValueF4)
    END_TYPE(H3DShaderRes)
    BEGIN_TYPE(H3DTexRes)
      SET_CONST(H3DTexRes, TextureElem)
      SET_CONST(H3DTexRes, ImageElem)
      SET_CONST(H3DTexRes, TexFormatI)
      SET_CONST(H3DTexRes, TexSliceCountI)
      SET_CONST(H3DTexRes, ImgWidthI)
      SET_CONST(H3DTexRes, ImgHeightI)
      SET_CONST(H3DTexRes, ImgPixelStream)
    END_TYPE(H3DTexRes)
    BEGIN_TYPE(H3DPartEffRes)
      SET_CONST(H3DPartEffRes, ParticleElem)
      SET_CONST(H3DPartEffRes, ChanMoveVelElem)
      SET_CONST(H3DPartEffRes, ChanRotVelElem)
      SET_CONST(H3DPartEffRes, ChanSizeElem)
      SET_CONST(H3DPartEffRes, ChanColRElem)
      SET_CONST(H3DPartEffRes, ChanColGElem)
      SET_CONST(H3DPartEffRes, ChanColBElem)
      SET_CONST(H3DPartEffRes, ChanColAElem)
      SET_CONST(H3DPartEffRes, PartLifeMinF)
      SET_CONST(H3DPartEffRes, PartLifeMaxF)
      SET_CONST(H3DPartEffRes, ChanStartMinF)
      SET_CONST(H3DPartEffRes, ChanStartMaxF)
      SET_CONST(H3DPartEffRes, ChanEndRateF)
      SET_CONST(H3DPartEffRes, ChanDragElem)
    END_TYPE(H3DPartEffRes)
    BEGIN_TYPE(H3DPipeRes)
      SET_CONST(H3DPipeRes, StageElem)
      SET_CONST(H3DPipeRes, StageNameStr)
      SET_CONST(H3DPipeRes, StageActivationI)
    END_TYPE(H3DPipeRes)
    BEGIN_TYPE(H3DNodeTypes)
      SET_CONST(H3DNodeTypes, Undefined)
      SET_CONST(H3DNodeTypes, Group)
      SET_CONST(H3DNodeTypes, Model)
      SET_CONST(H3DNodeTypes, Mesh)
      SET_CONST(H3DNodeTypes, Joint)
      SET_CONST(H3DNodeTypes, Light)
      SET_CONST(H3DNodeTypes, Camera)
      SET_CONST(H3DNodeTypes, Emitter)
    END_TYPE(H3DNodeTypes)
    BEGIN_TYPE(H3DNodeFlags)
      SET_CONST(H3DNodeFlags, NoDraw)
      SET_CONST(H3DNodeFlags, NoCastShadow)
      SET_CONST(H3DNodeFlags, NoRayQuery)
      SET_CONST(H3DNodeFlags, Inactive)
    END_TYPE(H3DNodeFlags)
    BEGIN_TYPE(H3DNodeParams)
      SET_CONST(H3DNodeParams, NameStr)
      SET_CONST(H3DNodeParams, AttachmentStr)
    END_TYPE(H3DNodeParams)
    BEGIN_TYPE(H3DModel)
      SET_CONST(H3DModel, GeoResI)
      SET_CONST(H3DModel, SWSkinningI)
      SET_CONST(H3DModel, LodDist1F)
      SET_CONST(H3DModel, LodDist2F)
      SET_CONST(H3DModel, LodDist3F)
      SET_CONST(H3DModel, LodDist4F)
    END_TYPE(H3DModel)
    BEGIN_TYPE(H3DMesh)
      SET_CONST(H3DMesh, MatResI)
      SET_CONST(H3DMesh, BatchStartI)
      SET_CONST(H3DMesh, BatchCountI)
      SET_CONST(H3DMesh, VertRStartI)
      SET_CONST(H3DMesh, VertREndI)
      SET_CONST(H3DMesh, LodLevelI)
    END_TYPE(H3DMesh)
    BEGIN_TYPE(H3DJoint)
      SET_CONST(H3DJoint, JointIndexI)
    END_TYPE(H3DJoint)
    BEGIN_TYPE(H3DLight)
      SET_CONST(H3DLight, MatResI)
      SET_CONST(H3DLight, RadiusF)
      SET_CONST(H3DLight, FovF)
      SET_CONST(H3DLight, ColorF3)
      SET_CONST(H3DLight, ColorMultiplierF)
      SET_CONST(H3DLight, ShadowMapCountI)
      SET_CONST(H3DLight, ShadowSplitLambdaF)
      SET_CONST(H3DLight, ShadowMapBiasF)
      SET_CONST(H3DLight, LightingContextStr)
      SET_CONST(H3DLight, ShadowContextStr)
    END_TYPE(H3DLight)
    BEGIN_TYPE(H3DCamera)
      SET_CONST(H3DCamera, PipeResI)
      SET_CONST(H3DCamera, OutTexResI)
      SET_CONST(H3DCamera, OutBufIndexI)
      SET_CONST(H3DCamera, LeftPlaneF)
      SET_CONST(H3DCamera, RightPlaneF)
      SET_CONST(H3DCamera, BottomPlaneF)
      SET_CONST(H3DCamera, TopPlaneF)
      SET_CONST(H3DCamera, NearPlaneF)
      SET_CONST(H3DCamera, FarPlaneF)
      SET_CONST(H3DCamera, ViewportXI)
      SET_CONST(H3DCamera, ViewportYI)
      SET_CONST(H3DCamera, ViewportWidthI)
      SET_CONST(H3DCamera, ViewportHeightI)
      SET_CONST(H3DCamera, OrthoI)
      SET_CONST(H3DCamera, OccCullingI)
    END_TYPE(H3DCamera)
    BEGIN_TYPE(H3DEmitter)
      SET_CONST(H3DEmitter, MatResI)
      SET_CONST(H3DEmitter, PartEffResI)
      SET_CONST(H3DEmitter, MaxCountI)
      SET_CONST(H3DEmitter, RespawnCountI)
      SET_CONST(H3DEmitter, DelayF)
      SET_CONST(H3DEmitter, EmissionRateF)
      SET_CONST(H3DEmitter, SpreadAngleF)
      SET_CONST(H3DEmitter, ForceF3)
    END_TYPE(H3DEmitter)
    
    target->Set(String::New("RootNode"), Integer::New(H3DRootNode));

  }
  NODE_MODULE(horde3d, init)
}
