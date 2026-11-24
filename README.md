# QEMU Pro - Dell Precision 16s machine presets

This is an independent downstream QEMU 11.2.0-rc0 source tree with three
x86_64 Q35/ICH9 machine presets inspired by the Dell Precision 16s:

| Machine | Default vCPUs | Default RAM | Included qcow2 disk |
| --- | ---: | ---: | ---: |
| `pro` | 12 | 32 GiB | 512 GiB |
| `pro2` | 16 | 16 GiB | 1 TiB |
| `pro2nocap` | 32 | 32 GiB | 1 TiB |

The Pro2 and Pro2NoCap presets advertise a preferred 1920x1200 VGA mode.
The Pro preset uses the standard VGA mode; set 1920x1200 in the guest OS.
These are Q35/ICH9 virtual PCs, not full emulations of the laptop's Core Ultra
CPU, NPU, Intel GPU, Wi-Fi 7 adapter, or internal display.

## Website and downloads

- Project site: <https://greeneyezad.github.io/qemu-pro/>
- Source and machine documentation: [docs/system/i386/pc.rst](docs/system/i386/pc.rst)
- x86_64 packages: [GitHub Releases](https://github.com/greeneyezad/qemu-pro/releases)

Each package includes QEMU, `qemu-img`, PC firmware, a blank sparse qcow2 disk,
a launcher, instructions, and the modified source archive. The packages target
Debian 13 (trixie) amd64 and list their runtime dependencies in their README.

## Performance and limits

QEMU does not impose an 8.20 GHz execution cap, and it cannot make guest code
execute at 8.20 GHz. Actual throughput depends on the host CPU and accelerator.
On a compatible Linux host, KVM can approach host CPU performance. A guest TSC
frequency setting changes guest-reported timing only.

The Q35 machine can be configured for 64 vCPUs. A 64 GiB guest requires
sufficient host memory. A 2 TiB qcow2 image is supported and can be created
sparsely; the included profiles use the disk sizes listed above.

## License

QEMU is distributed under the licenses described in [LICENSE](LICENSE).
