var glfw = require('node-glfw');
var horde = require('../index');

var version = glfw.GetVersion();

console.log(version);

if (!glfw.Init()) {
  console.log("Failed to initialize GLFW");
  process.exit(-1);
}

glfw.OpenWindowHint(glfw.OPENGL_MAJOR_VERSION, 3);
glfw.OpenWindowHint(glfw.OPENGL_MINOR_VERSION, 2);
glfw.Disable(glfw.AUTO_POLL_EVENTS);

glfw.SwapInterval(0);

if (!glfw.OpenWindow(800, 600, 0, 0, 0, 0, 0, 0, glfw.WINDOW)) {
  console.log("Failed to open GLFW window");
  glfw.Terminate();
  process.exit(-1);
}

glfw.SetWindowTitle("Title here");

horde.init();

horde.setOption(horde.LoadTextures, 1);
//horde.setOption(horde.DebugViewMode, 1);
//horde.setOption(horde.TexCompression, 0);

var hdrPipe = horde.addResource(horde.Pipeline, "pipelines/hdr.pipeline.xml", 0);
var knightScene = horde.addResource(horde.SceneGraph, "models/knight/knight.scene.xml", 0);

horde.loadResourcesFromDisk("/home/luke/Dropbox/hordejs/Content/");


camera = horde.addCameraNode(horde.RootNode, "Camera", hdrPipe);
horde.setNodeTransform(camera, 5, 3, 19, 7, 15, 0, 1, 1, 1);
var width = 800;
var height = 600;

horde.setupCameraView(camera, 45.0, width/height, 0.1, 1000);
horde.resizePipelineBuffers(hdrPipe, width, height);
horde.setNodeParamI(camera, horde.ViewportXI, 0);
horde.setNodeParamI(camera, horde.ViewportYI, 0);
horde.setNodeParamI(camera, horde.ViewportWidthI, width);
horde.setNodeParamI(camera, horde.ViewportHeightI, height);

var knight = horde.addNodes(horde.RootNode, knightScene);
horde.setNodeTransform(knight, 0, 0, 0, 0, 180, 0, 0.1, 0.1, 0.1);

var light = horde.addLightNode(horde.RootNode, "Light1", 0, "LIGHTING", "SHADOWMAP");
horde.setNodeTransform(light, 0, 15, 10, -60, 0, 0, 1, 1, 1);


do {
  horde.render(camera);
  horde.finalizeFrame();
  horde.clearOverlays();
  horde.dumpMessages();
  glfw.SwapBuffers();
} while (!glfw.GetKey(glfw.KEY_ESC) && glfw.GetWindowParam(glfw.OPENED));

glfw.Terminate();

process.exit(0);
