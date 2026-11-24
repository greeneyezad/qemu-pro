/*
 * Dell Precision 16s Pro2 machine type.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/units.h"
#include "hw/i386/pc.h"
#include "qom/compat-properties.h"
#include "qemu/module.h"

static GlobalProperty pro2_compat_defaults[] = {
    { "VGA", "xres", "1920" },
    { "VGA", "yres", "1200" },
};

static void pro2_machine_options(MachineClass *m)
{
    pc_q35_machine_options(m);
    m->desc = "Dell Precision 16s Pro2 (Q35 + ICH9)";
    m->alias = "Pro2";
    m->default_cpus = 16;
    m->default_ram_size = 16 * GiB;
    compat_props_add(m->compat_props, pro2_compat_defaults,
                     G_N_ELEMENTS(pro2_compat_defaults));
}

DEFINE_SECURE_PC_MACHINE(pro2, "pro2", pc_q35_init, pro2_machine_options);
