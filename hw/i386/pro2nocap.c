/*
 * Dell Precision 16s Pro2NoCap machine type.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/units.h"
#include "hw/i386/pc.h"
#include "qom/compat-properties.h"
#include "qemu/module.h"

static GlobalProperty pro2nocap_compat_defaults[] = {
    { "VGA", "xres", "1920" },
    { "VGA", "yres", "1200" },
};

static void pro2nocap_machine_options(MachineClass *m)
{
    pc_q35_machine_options(m);
    m->desc = "Dell Precision 16s Pro2NoCap (Q35 + ICH9)";
    m->alias = "Pro2NoCap";
    m->default_cpus = 32;
    m->default_ram_size = 32 * GiB;
    compat_props_add(m->compat_props, pro2nocap_compat_defaults,
                     G_N_ELEMENTS(pro2nocap_compat_defaults));
}

DEFINE_SECURE_PC_MACHINE(pro2nocap, "pro2nocap", pc_q35_init,
                         pro2nocap_machine_options);
