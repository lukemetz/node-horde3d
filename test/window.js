var glfw = require('node-glfw');
var horde = require('../index');

var setupGLFW = function() {
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
}
var setup = function() {
  setupGLFW()
  horde.init();

  horde.setOption(horde.H3DOptions.LoadTextures, 1);

  var hdrPipe = horde.addResource(horde.H3DResTypes.Pipeline, "pipelines/hdr.pipeline.xml", 0);
  horde.util.loadResourcesFromDisk("/home/luke/Dropbox/hordejs/Content/");


  camera = horde.addCameraNode(horde.RootNode, "Camera", hdrPipe);
  horde.setNodeTransform(camera, 5, 3, 19, 7, 15, 0, 1, 1, 1);
  var width = 800;
  var height = 600;

  horde.setupCameraView(camera, 45.0, width/height, 0.1, 1000);
  horde.resizePipelineBuffers(hdrPipe, width, height);
  horde.setNodeParamI(camera, horde.H3DCamera.ViewportXI, 0);
  horde.setNodeParamI(camera, horde.H3DCamera.ViewportYI, 0);
  horde.setNodeParamI(camera, horde.H3DCamera.ViewportWidthI, width);
  horde.setNodeParamI(camera, horde.H3DCamera.ViewportHeightI, height);

  return camera
}
camera = setup();

var knightScene = horde.addResource(horde.H3DResTypes.SceneGraph, "models/knight/knight.scene.xml", 0);
var knightAnimRes1 = horde.addResource(horde.H3DResTypes.Animation, "animations/knight_order.anim", 0);
var knightAnimRes2 = horde.addResource(horde.H3DResTypes.Animation, "animations/knight_attack.anim", 0);

var envRes = horde.addResource(horde.H3DResTypes.SceneGraph, "models/sphere/sphere.scene.xml");

horde.util.loadResourcesFromDisk("/home/luke/Dropbox/hordejs/Content/");

var knight = horde.addNodes(horde.RootNode, knightScene);
horde.setNodeTransform(knight, 0, 0, 0, 0, 180, 0, 0.1, 0.1, 0.1);
horde.setupModelAnimStage(knight, 0, knightAnimRes1, 0, "", false);
horde.setupModelAnimStage(knight, 1, knightAnimRes2, 0, "", false);


var setupLight = function() {
  var light = horde.addLightNode(horde.RootNode, "Light1", 0, "LIGHTING", "SHADOWMAP");
  horde.setNodeTransform(light, 0, 15, 10, -60, 0, 0, 1, 1, 1);
  horde.setNodeParamF(light, horde.H3DLight.RadiusF, 0, 30);
  horde.setNodeParamF(light, horde.H3DLight.FovF, 0, 90);
  horde.setNodeParamI(light, horde.H3DLight.ShadowMapCountI, 1);
  horde.setNodeParamF(light, horde.H3DLight.ShadowMapBiasF, 0, 0.01);
  return light
}
var light = setupLight()

var env = horde.addNodes(horde.RootNode, envRes);
horde.setNodeTransform(env, 0, -20, 0,
                            0, 0, 0,
                            20, 20, 20);

var px = 5;
var py = 3;
var pz = 19;
var rx = 7;
var ry = 15;
var rz = 0;
var vel = .1;

var degToRad = function(v) {
  return v/180*Math.PI;
}

var key = function(code) {
  return code.charCodeAt(code)
};

var move_camera = function() {
  if (glfw.GetKey(key('W'))) {
    px -= Math.sin(degToRad(ry)) * Math.cos(-degToRad(rx)) * vel;
    py -= Math.sin(-degToRad(rx)) * vel;
    pz -= Math.cos(degToRad(ry)) * Math.cos(-degToRad(rx)) * vel;
  }

  if (glfw.GetKey(key('S'))) {
    px += Math.sin(degToRad(ry)) * Math.cos(-degToRad(rx)) * vel;
    py += Math.sin(-degToRad(rx)) * vel;
    pz += Math.cos(degToRad(ry)) * Math.cos(-degToRad(rx)) * vel;
  }

  if (glfw.GetKey(key('A'))) {
    px += Math.sin(degToRad(ry - 90)) * vel;
    pz += Math.cos(degToRad(ry - 90)) * vel;
  }

  if (glfw.GetKey(key('D'))) {
    px += Math.sin(degToRad(ry + 90)) * vel;
    pz += Math.cos(degToRad(ry + 90)) * vel;
  }
}

var prev_x = undefined;
var prev_Y = undefined;

glfw.events.on('mousemove', function(evt) {
  if (prev_x == undefined) {
    prev_x = evt.x;
    prev_y = evt.y;
  }
  ry -= (evt.x - prev_x ) / 100.0 * 30;
  rx -= (evt.y - prev_y ) / 100.0 * 30;
  if (rx > 90) rx = 90;
  if (rx < -90) rx = 90;
  prev_x = evt.x;
  prev_y = evt.y;
});

var pos = glfw.GetMousePos();
var old_time = Date.now();
var anim_timer = 0;
var weight = 1;

do {
  var dt = Date.now() - old_time;
  old_time = Date.now();
  anim_timer += dt;

  move_camera();
  horde.render(camera);
  horde.finalizeFrame();
  horde.clearOverlays();
  horde.util.dumpMessages();
  glfw.SwapBuffers();
  glfw.GetKey(glfw.KEY_W);
  horde.setNodeTransform(camera, px, py, pz, rx, ry, rz, 1, 1, 1);
  horde.setModelAnimParams(knight, 0, anim_timer * 24/1000, weight);
  horde.setModelAnimParams(knight, 1, anim_timer * 24/1000, weight);

} while (!glfw.GetKey(glfw.KEY_ESC) && glfw.GetWindowParam(glfw.OPENED));

glfw.Terminate();
