/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Configuration for MediaTek MT7981 SoC
 *
 * Copyright (C) 2022 MediaTek Inc.
 * Author: Sam Shih <sam.shih@mediatek.com>
 */

#ifndef __MT7981_H
#define __MT7981_H

/* Extra environment variables */
#ifdef CONFIG_MTK_DEFAULT_FIT_BOOT_CONF
#define FIT_BOOT_CONF_ENV	"bootconf=" CONFIG_MTK_DEFAULT_FIT_BOOT_CONF "\0"
#else
#define FIT_BOOT_CONF_ENV
#endif

/*
 * Built-in defaults, so a cold boot works even with an empty environment.
 *
 * bootcmd: mtkautoboot only *displays* the bootmenu; mtkboardboot is the
 * menu's "Startup system (Default)" command and boots the FIT directly.
 *
 * glbtn_key: the board has "reset" and "mesh" buttons in its DT (no "wps").
 * The stock list "reset,wps,mesh" makes glbtn fall back to the mesh button,
 * which reads as held down on this hardware, so the web failsafe UI was
 * started on every cold boot before autoboot could run. Restrict the
 * failsafe trigger key to reset.
 */
#define CFG_EXTRA_ENV_SETTINGS	\
	FIT_BOOT_CONF_ENV \
	"bootcmd=mtkboardboot\0" \
	"glbtn_key=reset\0"

#endif
