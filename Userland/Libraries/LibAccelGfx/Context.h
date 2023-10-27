/*
 * Copyright (c) 2023, Aliaksandr Kalenik <kalenik.aliaksandr@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Assertions.h>
#include <AK/OwnPtr.h>

#ifdef AK_OS_LINUX
#    include <EGL/egl.h>
#endif

namespace AccelGfx {

class Context {
public:
    static Context& the();

    struct Surface {
        EGLSurface egl_surface { 0 };
    };

    Surface create_surface(int width, int height);
    void destroy_surface(Surface surface);
    void set_active_surface(Surface surface);

    static OwnPtr<Context> create();

    Context(EGLDisplay egl_display, EGLContext egl_context, EGLConfig egl_config)
        : m_egl_display(egl_display)
        , m_egl_context(egl_context)
        , m_egl_config(egl_config)
    {
    }

private:
    EGLDisplay m_egl_display { nullptr };
    EGLContext m_egl_context { nullptr };
    EGLConfig m_egl_config { nullptr };
};

}
