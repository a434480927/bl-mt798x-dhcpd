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
 * Boot straight into the installed system.
 *
 * mtkautoboot only *displays* the bootmenu command that pauses
 * indefinitely waiting for a key press, which this board cannot provide
 * (no serial console attached), so autoboot never reached the system.
 * mtkboardboot is the menu's own "Startup system (Default)" command.
 */
#define CFG_EXTRA_ENV_SETTINGS	\
	FIT_BOOT_CONF_ENV \
	"bootcmd=mtkboardboot\0"

#endif
