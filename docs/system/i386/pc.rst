i440fx PC (``pc-i440fx``, ``pc``)
=================================

Peripherals
~~~~~~~~~~~

.. include:: ../target-i386-desc.rst.inc

Dell Precision 16s (``pro``, alias ``Pro``)
==========================================

The ``pro`` machine is a Q35/ICH9 x86 PC preset with 12 virtual CPUs and
32 GiB of RAM by default. These defaults can be changed with ``-smp`` and
``-m``. QEMU does not create a disk image or install a guest operating system.
With a GTK-enabled build and a Debian installer ISO, create a 512 GiB virtual
disk and start the graphical installer:

.. code-block:: sh

   qemu-img create -f qcow2 pro-ssd.qcow2 512G
   qemu-system-x86_64 -machine pro -display gtk \
     -cdrom debian.iso -boot order=d \
     -drive file=pro-ssd.qcow2,if=none,id=ssd,format=qcow2 \
     -device nvme,drive=ssd,serial=pro-ssd

The command uses the machine defaults. After installing Debian, remove
``-cdrom debian.iso -boot order=d`` to boot from the virtual SSD. Set the
desired 1920x1200 resolution in the guest's display settings.

This machine type does not reproduce the physical laptop hardware. QEMU does
not model the Core Ultra 5 336H CPU, its NPU, the integrated Intel GPU, Wi-Fi 7,
or the built-in display panel. The guest CPU model, graphics, network, storage
image, operating system, display resolution, and DPI must be configured
separately. For KVM acceleration on a compatible Intel host, ``-cpu host`` can
expose the host CPU model; it does not emulate the 336H on other hosts.

Dell Precision 16s Pro2 (``pro2``, alias ``Pro2``)
================================================

The separate ``pro2`` machine uses the Q35/ICH9 platform with 16 virtual CPUs
and 16 GiB of RAM by default. Its default VGA device advertises a preferred
EDID mode of 1920x1200; the guest display driver determines whether that mode
is used. QEMU does not create disk image files automatically. Create a sparse
1024 GiB qcow2 image and attach it as an NVMe disk:

.. code-block:: sh

   qemu-img create -f qcow2 pro2-ssd.qcow2 1024G
   qemu-system-x86_64 -machine pro2 -display gtk \
     -cdrom debian.iso -boot order=d \
     -drive file=pro2-ssd.qcow2,if=none,id=ssd,format=qcow2 \
     -device nvme,drive=ssd,serial=pro2-ssd

The command uses the machine defaults. After installing Debian, remove
``-cdrom debian.iso -boot order=d`` to boot from the virtual SSD.

Dell Precision 16s Pro2NoCap (``pro2nocap``, alias ``Pro2NoCap``)
===============================================================

The ``pro2nocap`` machine uses the Q35/ICH9 platform with 32 virtual CPUs and
32 GiB of RAM by default. Its default VGA device advertises a preferred EDID
mode of 1920x1200. Create a sparse 1024 GiB qcow2 image and attach it as NVMe:

.. code-block:: sh

   qemu-img create -f qcow2 pro2nocap-ssd.qcow2 1024G
   qemu-system-x86_64 -machine pro2nocap -display gtk \
     -cdrom debian.iso -boot order=d \
     -drive file=pro2nocap-ssd.qcow2,if=none,id=ssd,format=qcow2 \
     -device nvme,drive=ssd,serial=pro2nocap-ssd

The qcow2 image has 1024 GiB of virtual capacity and is not allocated in full
at creation. QEMU requires an explicit host image file; the machine type does
not create one automatically.
