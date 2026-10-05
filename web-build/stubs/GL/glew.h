// GLEW stub for Emscripten/WebGL
#ifndef __GLEW_H__
#define __GLEW_H__

#include <GL/gl.h>

#define glewInit() (0)
#define GLEW_OK 0
#define GLEW_EXT_framebuffer_object 1
#define GLEW_ARB_framebuffer_object 1

// Framebuffer EXT functions - stub as no-ops for web build
// (render-to-texture not critical for basic functionality)
#include <stddef.h>
static inline void glBindFramebufferEXT(unsigned int t, unsigned int f) {}
static inline void glGenFramebuffersEXT(int n, unsigned int* f) {}
static inline void glDeleteFramebuffersEXT(int n, unsigned int* f) {}
static inline void glFramebufferTexture2DEXT(unsigned int t, unsigned int a, unsigned int tt, unsigned int tx, int l) {}
static inline unsigned int glCheckFramebufferStatusEXT(unsigned int t) { return 0x8CD5; } // GL_FRAMEBUFFER_COMPLETE
static inline void glGenerateMipmapEXT(unsigned int t) {}
static inline void glBindRenderbufferEXT(unsigned int t, unsigned int r) {}
static inline void glGenRenderbuffersEXT(int n, unsigned int* r) {}
static inline void glRenderbufferStorageEXT(unsigned int t, unsigned int f, int w, int h) {}
static inline void glFramebufferRenderbufferEXT(unsigned int t, unsigned int a, unsigned int rt, unsigned int r) {}

// Constants
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5

#endif

// Shader functions - available via WebGL, declare them
// (LEGACY_GL_EMULATION headers don't include modern GL)
#ifdef __EMSCRIPTEN__
#include <GLES3/gl3.h>
#endif
