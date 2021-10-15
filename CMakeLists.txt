cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(HIB)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "HIB")
set(VITA_TITLEID  "HIB000001")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -DVITA")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
  common
)

add_executable(${PROJECT_NAME}
  main.c
  input.c
  gui.c
  enemy.c
  ship.c
  spacestation.c
  bullet.c
  util.c
  display.c
)

target_link_libraries(${PROJECT_NAME}
  SDL2
  SDL2_ttf
  freetype
  SDL2_image
  png
  jpeg
  zip
  z
  webp
  pthread
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceAppMgr_stub
  SceTouch_stub
  SceHid_stub
  SceMotion_stub
  m
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  FILE font/8-bit-hud.ttf font/8-bit-hud.ttf
  FILE img/1.png img/1.png
  FILE img/2.png img/2.png
  FILE img/3.png img/3.png
  FILE img/4.png img/4.png
  FILE img/5.png img/5.png
  FILE img/6.png img/6.png
  FILE img/7.png img/7.png
  FILE img/8.png img/8.png
  FILE img/bg2.jpg img/bg2.jpg
  FILE img/d.png img/d.png
  FILE img/en1.png img/en1.png
  FILE img/l.png img/l.png
  FILE img/r.png img/r.png
  FILE img/sd.png img/sd.png
  FILE img/ship.png img/ship.png
  FILE img/u.png img/u.png
  FILE img/vbg.png img/vbg.png
  FILE level/1.txt level/1.txt
  FILE level/2.txt level/2.txt
)
