/*
**  Oricutron
**  Copyright (C) 2009-2014 Peter Gordon
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation, version 2
**  of the License.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
**  SDL System specific stuff
*/

#ifndef ORICUTRON_SYSTEM_SDL_H
#define ORICUTRON_SYSTEM_SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_version.h>

#ifdef WANT_WMINFO
#include <SDL2/SDL_syswm.h>
#endif

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
#define _LE32(X) (X)
#define _LE16(X) (X)
#define _BE32(X) SDL_Swap32(X)
#define _BE16(X) SDL_Swap16(X)
#define _MAKE_LE32(X)
#define _MAKE_LE16(X)
#define _MAKE_BE32(X) X = SDL_Swap32(X)
#define _MAKE_BE16(X) X = SDL_Swap16(X)
#else
#define _LE32(X) SDL_Swap32(X)
#define _LE16(X) SDL_Swap16(X)
#define _BE32(X) (X)
#define _BE16(X) (X)
#define _MAKE_LE32(X) X = SDL_Swap32(X)
#define _MAKE_LE16(X) X = SDL_Swap16(X)
#define _MAKE_BE32(X)
#define _MAKE_BE16(X)
#endif

/* SDL compatability definitions and macroses */
typedef Uint32 SDL_COMPAT_KEY;        /* Used in 8912.c */
typedef SDL_Keysym SDL_KEYSYM;
typedef SDL_RendererInfo SDL_COMPAT_VideoInfo;

#define SDL_COMPAT_HWSURFACE          0 /* FIXME */
#define SDL_COMPAT_HWPALETTE          0 /* FIXME */
#define SDL_COMPAT_FULLSCREEN         SDL_WINDOW_FULLSCREEN

#ifdef __OPENGL_AVAILABLE__
#define SDL_COMPAT_OPENGL             SDL_WINDOW_OPENGL
#endif

#define SDL_COMPAT_LOGPAL             0 /* FIXME */
#define SDL_COMPAT_PHYSPAL            0 /* FIXME */

#define SDL_COMPAT_ACTIVEEVENT        SDL_WINDOWEVENT

#define SDL_DEFAULT_REPEAT_DELAY      0 /* FIXME */
#define SDL_DEFAULT_REPEAT_INTERVAL   0 /* FIXMR */

#define SDLK_KP0                      SDLK_KP_0
#define SDLK_KP1                      SDLK_KP_1
#define SDLK_KP2                      SDLK_KP_2
#define SDLK_KP3                      SDLK_KP_3
#define SDLK_KP4                      SDLK_KP_4
#define SDLK_KP5                      SDLK_KP_5
#define SDLK_KP6                      SDLK_KP_6
#define SDLK_KP7                      SDLK_KP_7
#define SDLK_KP8                      SDLK_KP_8
#define SDLK_KP9                      SDLK_KP_9

#define SDLK_PRINT                    SDLK_PRINTSCREEN

/* SDL compatability protos */
#ifdef WANT_WMINFO
int SDL_COMPAT_GetWMInfo(SDL_SysWMinfo *info);
#endif

int SDL_COMPAT_Init(Uint32 flags);
void SDL_COMPAT_WM_SetIcon(SDL_Surface *icon, Uint8 *mask);
void SDL_COMPAT_WM_SetCaption(const char *title, const char *icon);
SDL_bool SDL_COMPAT_IsAppActive(SDL_Event* event);
SDL_bool SDL_COMPAT_IsAppFocused(SDL_Event* event);
int SDL_COMPAT_EnableKeyRepeat(int delay, int interval);
int SDL_COMPAT_EnableUNICODE(int enable);
SDL_COMPAT_KEY SDL_COMPAT_GetKeysymUnicode(SDL_KEYSYM keysym);
SDL_COMPAT_KEY SDL_COMPAT_TranslateUnicode(SDL_KEYSYM keysym);
int SDL_COMPAT_Flip(SDL_Surface* screen);
int SDL_COMPAT_GetBitsPerPixel(void);
int SDL_COMPAT_WM_ToggleFullScreen(SDL_Surface *surface);
SDL_Surface* SDL_COMPAT_SetVideoMode(int width, int height, int bitsperpixel, Uint32 flags);
int SDL_COMPAT_SetPalette(SDL_Surface *surface, int flags, SDL_Color *colors, int firstcolor, int ncolors);
void SDL_COMPAT_SetEventFilter(SDL_EventFilter filter);
void SDL_COMPAT_Quit(SDL_bool freeall);
void SDL_COMPAT_TakeScreenshot(char *fname);

#ifdef __OPENGL_AVAILABLE__
void SDL_COMPAT_GL_SwapBuffers(void);
#endif


#ifdef __ANDROID__
#include <android/log.h>
#define  LOG_TAG    "Oricutron"
#define  debug_printf(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  error_printf(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#else
#define  debug_printf(...)  fprintf(stdout,__VA_ARGS__)
void error_printf( char *fmt, ... );
#endif

#endif /* ORICUTRON_SYSTEM_SDL_H */
