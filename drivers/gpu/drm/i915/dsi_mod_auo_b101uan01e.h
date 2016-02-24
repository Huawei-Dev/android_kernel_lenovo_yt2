/*
 * Copyright (C) 2013 Intel Corporation
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
 *
 * Authors:
 *	Shobhit Kumar <yating.wang@intel.com>
 */
#ifndef __DSI_MOD_AUO_B101UAN01E_H__
#define __DSI_MOD_AUO_B101UAN01E_H__

#include <drm/drmP.h>
#include <drm/drm.h>
#include <drm/drm_crtc.h>
#include "intel_drv.h"
#include "lenovo_lcd_panel.h"

//CABC command
static u8 cabcoff_cmd1[]  = {0x15, 0xAA};
static u8 cabcon_cmd1[]	  = {0x15, 0x55};
//Color Enhance command
static u8 ceoff_cmd1[]    = {0x16, 0xAA};
static u8 ceon_cmd1[]     = {0x16, 0x55};

static struct lcd_cmd cabcoff_cmds[] = {
	{cabcoff_cmd1, ARRAY_SIZE(cabcoff_cmd1)},
};

static struct lcd_cmd cabcon_cmds[] = {
	{cabcon_cmd1, ARRAY_SIZE(cabcon_cmd1)},
};

static struct lcd_cmd ceoff_cmds[]  = {
	{ceoff_cmd1,  ARRAY_SIZE(ceoff_cmd1)},
};

static struct lcd_cmd ceon_cmds[] = {
	{ceon_cmd1,   ARRAY_SIZE(ceon_cmd1)},
};

static struct lcd_effect_cmd cabc_effect_cmds[] = {
	{ ARRAY_SIZE(cabcoff_cmds), cabcoff_cmds},
	{ ARRAY_SIZE(cabcon_cmds), cabcon_cmds},
};

static struct lcd_effect_cmd ce_effect_cmds[] = {
	{ARRAY_SIZE(ceoff_cmds), ceoff_cmds},
	{ARRAY_SIZE(ceon_cmds), ceon_cmds},
};
#if 1 
static struct lcd_mode_cmd standard_mode_cmds[] = {
    {ARRAY_SIZE(cabcon_cmds), cabcon_cmds},
    {ARRAY_SIZE(ceon_cmds), ceon_cmds},
};
static struct lcd_mode_cmd camera_mode_cmds[] = {
    {ARRAY_SIZE(cabcoff_cmds), cabcoff_cmds},
    {ARRAY_SIZE(ceoff_cmds), ceoff_cmds},
};
static struct lcd_mode_cmd blank_mode_cmds[] = {
    //{ARRAY_SIZE(ceoff_cmds), ceoff_cmds},
    //{ARRAY_SIZE(ceon_cmds), ceon_cmds},
};
static struct lcd_mode auo_b101uan01e_mode[] = {
    {"standard",  standard_mode_cmds,1},
    {"camera",  camera_mode_cmds,1},
    {"blank",  blank_mode_cmds,0},
};
static struct lcd_mode_data auo_b101uan01e_mode_data = { auo_b101uan01e_mode, ARRAY_SIZE(auo_b101uan01e_mode)};
#endif

static struct lcd_effect auo_b101uan01e_effect[] = {
	{"cabc", ARRAY_SIZE(cabc_effect_cmds), 1, cabc_effect_cmds},
	{"ce", ARRAY_SIZE(ce_effect_cmds), 1, ce_effect_cmds},
};

static struct lcd_effect_data auo_b101uan01e_effect_data = { auo_b101uan01e_effect, ARRAY_SIZE(auo_b101uan01e_effect)};

static struct lcd_data auo_b101uan01e_data = {
	&auo_b101uan01e_effect_data,
    &auo_b101uan01e_mode_data,
	//NULL,
};

#endif /* __DSI_MOD_AUO_B101UAN01E_H__ */
