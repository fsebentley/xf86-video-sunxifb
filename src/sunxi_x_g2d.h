/*
 * Copyright © 2013 Siarhei Siamashka <siarhei.siamashka@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SUNXI_X_G2D_H
#define SUNXI_X_G2D_H

#include "interfaces.h"

typedef struct {
    GCOps                  *pGCOps;

    CopyWindowProcPtr       CopyWindow;
    CreateGCProcPtr         CreateGC;

    /* SunxiG2D_Init copies these pointers here from blt2d_i struct */
    void *blt2d_self;
    int (*blt2d_overlapped_blt)(void     *self,
                                uint32_t *src_bits,
                                uint32_t *dst_bits,
                                int       src_stride,
                                int       dst_stride,
                                int       src_bpp,
                                int       dst_bpp,
                                int       src_x,
                                int       src_y,
                                int       dst_x,
                                int       dst_y,
                                int       w,
                                int       h);
    int (*blt2d_fill)(void     *self,
                uint32_t *bits,
                int       stride,
                int       bpp,
                int       x,
                int       y,
                int       width,
                int       height,
                uint32_t  color);
    blt2d_i *blt2d_cpu_backend;
} SunxiG2D;

SunxiG2D *SunxiG2D_Init(ScreenPtr pScreen, blt2d_i *blt2d, blt2d_i *blt2d_cpu_backend);
void SunxiG2D_Close(ScreenPtr pScreen);

#endif
