/*
 * Dell Precision 16s Pro machine type.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/units.h"
#include "hw/i386/pc.h"
#include "qemu/module.h"

static void pro_machine_options(MachineClass *m)
{
    pc_q35_machine_options(m);
    m->desc = "Dell Precision 16s (Pro, Q35 + ICH9)";
    m->alias = "Pro";
    m->default_cpus = 12;
    m->default_ram_size = 32 * GiB;
}

DEFINE_SECURE_PC_MACHINE(pro, "pro", pc_q35_init, pro_machine_options);
