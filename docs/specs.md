# Hardware
```
nayeon@CLAPP-222-PC17:~/Desktop$ sudo lshw
[sudo] password for nayeon:
clapp-222-pc17
description: Notebook
product: Latitude 5490 (0816)
vendor: Dell Inc.
serial: G7QR5Q2
width: 64 bits
capabilities: smbios-3.1.1 dmi-3.1.1 smp vsyscall32
configuration: boot=normal chassis=notebook family=Latitude sku=0816 uuid=4c4c4544-0037-5110-8052-c7c04f355132
*-core
description: Motherboard
product: 0DH2HV
vendor: Dell Inc.
physical id: 0
version: A00
serial: /G7QR5Q2/CNCMK0086P0073/
*-firmware
description: BIOS
vendor: Dell Inc.
physical id: 0
version: 1.2.3
date: 03/21/2018
size: 64KiB
capacity: 16MiB
capabilities: pci pnp upgrade shadowing cdboot bootselect edd int13floppynec int13floppy1200 int13floppy720 int13floppy2880 int5printscreen int9keyboard int14serial int17printer acpi usb smartbattery biosbootspecification netboot uefi
*-memory
description: System Memory
physical id: 49
slot: System board or motherboard
size: 16GiB
*-bank:0
description: SODIMM DDR4 Synchronous Unbuffered (Unregistered) 2400 MHz (0.4 ns)
product: HMA82GS6AFR8N-UH
vendor: Hynix Semiconductor (Hyundai Electronics)
physical id: 0
serial: 2C77CD11
slot: DIMM A
size: 16GiB
width: 64 bits
clock: 2400MHz (0.4ns)
*-bank:1
description: [empty]
physical id: 1
slot: ChannelB-DIMM0
*-cache:0
description: L1 cache
physical id: 4d
slot: L1 Cache
size: 256KiB
capacity: 256KiB
capabilities: synchronous internal write-back unified
configuration: level=1
*-cache:1
description: L2 cache
physical id: 4e
slot: L2 Cache
size: 1MiB
capacity: 1MiB
capabilities: synchronous internal write-back unified
configuration: level=2
*-cache:2
description: L3 cache
physical id: 4f
slot: L3 Cache
size: 6MiB
capacity: 6MiB
capabilities: synchronous internal write-back unified
configuration: level=3
*-cpu
description: CPU
product: Intel(R) Core(TM) i5-8350U CPU @ 1.70GHz
vendor: Intel Corp.
physical id: 50
bus info: cpu@0
version: 6.142.10
serial: To Be Filled By O.E.M.
slot: U3E1
size: 2975MHz
capacity: 4005MHz
width: 64 bits
clock: 100MHz
capabilities: lm fpu fpu_exception wp vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp x86-64 constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb invpcid_single pti ssbd ibrs ibpb stibp tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp md_clear flush_l1d arch_capabilities cpufreq
configuration: cores=4 enabledcores=4 microcode=240 threads=8
*-pci
description: Host bridge
product: Xeon E3-1200 v6/7th Gen Core Processor Host Bridge/DRAM Registers
vendor: Intel Corporation
physical id: 100
bus info: pci@0000:00:00.0
version: 08
width: 32 bits
clock: 33MHz
configuration: driver=skl_uncore
resources: irq:0
*-display
description: VGA compatible controller
product: UHD Graphics 620
vendor: Intel Corporation
physical id: 2
bus info: pci@0000:00:02.0
logical name: /dev/fb0
version: 07
width: 64 bits
clock: 33MHz
capabilities: pciexpress msi pm vga_controller bus_master cap_list rom fb
configuration: depth=32 driver=i915 latency=0 resolution=1920,1080
resources: irq:128 memory:ee000000-eeffffff memory:d0000000-dfffffff ioport:f000(size=64) memory:c0000-dffff
*-generic:0
description: Signal processing controller
product: Xeon E3-1200 v5/E3-1500 v5/6th Gen Core Processor Thermal Subsystem
vendor: Intel Corporation
physical id: 4
bus info: pci@0000:00:04.0
version: 08
width: 64 bits
clock: 33MHz
capabilities: msi pm cap_list
configuration: driver=proc_thermal latency=0
resources: irq:16 memory:ef240000-ef247fff
*-usb
description: USB controller
product: Sunrise Point-LP USB 3.0 xHCI Controller
vendor: Intel Corporation
physical id: 14
bus info: pci@0000:00:14.0
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm msi xhci cap_list
configuration: driver=xhci_hcd latency=0
resources: irq:126 memory:ef230000-ef23ffff
*-usbhost:0
product: xHCI Host Controller
vendor: Linux 5.15.0-75-generic xhci-hcd
physical id: 0
bus info: usb@1
logical name: usb1
version: 5.15
capabilities: usb-2.00
configuration: driver=hub slots=12 speed=480Mbit/s
*-usb:0
description: Video
product: Integrated Webcam_HD: Integrate
vendor: CN0K49W1LOG0083SA0SMA01
physical id: 5
bus info: usb@1:5
logical name: input15
logical name: /dev/input/event12
version: 60.06
serial: 200901010001
capabilities: usb-2.00 usb
configuration: driver=uvcvideo maxpower=500mA speed=480Mbit/s
*-usb:1
description: Bluetooth wireless interface
product: Bluetooth wireless interface
vendor: Intel Corp.
physical id: 7
bus info: usb@1:7
version: 0.10
capabilities: bluetooth usb-2.00
configuration: driver=btusb maxpower=100mA speed=12Mbit/s
*-usbhost:1
product: xHCI Host Controller
vendor: Linux 5.15.0-75-generic xhci-hcd
physical id: 1
bus info: usb@2
logical name: usb2
version: 5.15
capabilities: usb-3.00
configuration: driver=hub slots=6 speed=5000Mbit/s
*-generic:1
description: Signal processing controller
product: Sunrise Point-LP Thermal subsystem
vendor: Intel Corporation
physical id: 14.2
bus info: pci@0000:00:14.2
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm msi cap_list
configuration: driver=intel_pch_thermal latency=0
resources: irq:18 memory:ef259000-ef259fff
*-generic:2
description: Signal processing controller
product: Sunrise Point-LP Serial IO I2C Controller #0
vendor: Intel Corporation
physical id: 15
bus info: pci@0000:00:15.0
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm bus_master cap_list
configuration: driver=intel-lpss latency=0
resources: irq:16 memory:ef258000-ef258fff
*-generic:3
description: Signal processing controller
product: Sunrise Point-LP Serial IO I2C Controller #1
vendor: Intel Corporation
physical id: 15.1
bus info: pci@0000:00:15.1
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm bus_master cap_list
configuration: driver=intel-lpss latency=0
resources: irq:17 memory:ef257000-ef257fff
*-communication:0
description: Communication controller
product: Sunrise Point-LP CSME HECI #1
vendor: Intel Corporation
physical id: 16
bus info: pci@0000:00:16.0
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm msi bus_master cap_list
configuration: driver=mei_me latency=0
resources: irq:129 memory:ef256000-ef256fff
*-communication:1
description: Serial controller
product: Sunrise Point-LP Active Management Technology - SOL
vendor: Intel Corporation
physical id: 16.3
bus info: pci@0000:00:16.3
version: 21
width: 32 bits
clock: 66MHz
capabilities: msi pm 16550 cap_list
configuration: driver=serial latency=0
resources: irq:19 ioport:f0a0(size=8) memory:ef255000-ef255fff
*-raid
description: RAID bus controller
product: 82801 Mobile SATA Controller [RAID mode]
vendor: Intel Corporation
physical id: 17
bus info: pci@0000:00:17.0
logical name: scsi2
version: 21
width: 32 bits
clock: 66MHz
capabilities: raid msi pm bus_master cap_list emulated
configuration: driver=ahci latency=0
resources: irq:125 memory:ef250000-ef251fff memory:ef254000-ef2540ff ioport:f090(size=8) ioport:f080(size=4) ioport:f060(size=32) memory:ef253000-ef2537ff
*-disk
description: ATA Disk
product: SK hynix SC311 S
physical id: 0.0.0
bus info: scsi@2:0.0.0
logical name: /dev/sda
version: 0P10
serial: MS85N722312305T2O
size: 238GiB (256GB)
capabilities: gpt-1.00 partitioned partitioned:gpt
configuration: ansiversion=5 guid=3c1e5612-7dbb-41df-97f9-e1f09b471575 logicalsectorsize=512 sectorsize=4096
*-volume:0 UNCLAIMED
description: Windows FAT volume
vendor: mkfs.fat
physical id: 1
bus info: scsi@2:0.0.0,1
version: FAT32
serial: 997c-a627
size: 1073MiB
capacity: 1074MiB
capabilities: boot fat initialized
configuration: FATs=2 filesystem=fat
*-volume:1
description: EXT4 volume
vendor: Linux
physical id: 2
bus info: scsi@2:0.0.0,2
logical name: /dev/sda2
logical name: /
logical name: /var/snap/firefox/common/host-hunspell
version: 1.0
serial: e64426ba-9842-4e8b-8e64-6cbc78d48a25
size: 237GiB
capabilities: journaled extended_attributes large_files huge_files dir_nlink recover 64bit extents ext4 ext2 initialized
configuration: created=2023-06-23 13:42:50 filesystem=ext4 lastmountpoint=/ modified=2023-12-10 01:32:18 mount.fstype=ext4 mount.options=ro,noexec,noatime mounted=2023-12-10 01:32:19 state=mounted
*-pci:0
description: PCI bridge
product: Sunrise Point-LP PCI Express Root Port #1
vendor: Intel Corporation
physical id: 1c
bus info: pci@0000:00:1c.0
version: f1
width: 32 bits
clock: 33MHz
capabilities: pci pciexpress msi pm normal_decode bus_master cap_list
configuration: driver=pcieport
resources: irq:122 memory:ef100000-ef1fffff
*-generic
description: MMC Host
product: RTS525A PCI Express Card Reader
vendor: Realtek Semiconductor Co., Ltd.
physical id: 0
bus info: pci@0000:01:00.0
logical name: mmc0
version: 01
width: 32 bits
clock: 33MHz
capabilities: pm msi pciexpress bus_master cap_list
configuration: driver=rtsx_pci latency=0
resources: irq:127 memory:ef100000-ef100fff
*-pci:1
description: PCI bridge
product: Sunrise Point-LP PCI Express Root Port #3
vendor: Intel Corporation
physical id: 1c.2
bus info: pci@0000:00:1c.2
version: f1
width: 32 bits
clock: 33MHz
capabilities: pci pciexpress msi pm normal_decode bus_master cap_list
configuration: driver=pcieport
resources: irq:123 memory:ef000000-ef0fffff
*-network
description: Wireless interface
product: Wireless 8265 / 8275
vendor: Intel Corporation
physical id: 0
bus info: pci@0000:02:00.0
logical name: wlp2s0
version: 78
serial: c0:b6:f9:2a:a7:60
width: 64 bits
clock: 33MHz
capabilities: pm msi pciexpress bus_master cap_list ethernet physical wireless
configuration: broadcast=yes driver=iwlwifi driverversion=5.15.0-75-generic firmware=36.ca7b901d.0 8265-36.ucode ip=138.110.155.89 latency=0 link=yes multicast=yes wireless=IEEE 802.11
resources: irq:130 memory:ef000000-ef001fff
*-isa
description: ISA bridge
product: Sunrise Point LPC Controller/eSPI Controller
vendor: Intel Corporation
physical id: 1f
bus info: pci@0000:00:1f.0
version: 21
width: 32 bits
clock: 33MHz
capabilities: isa bus_master
configuration: latency=0
*-pnp00:00
product: PnP device PNP0c02
physical id: 0
capabilities: pnp
configuration: driver=system
*-pnp00:01
product: PnP device PNP0b00
physical id: 1
capabilities: pnp
configuration: driver=rtc_cmos
*-pnp00:02
product: PnP device INT3f0d
vendor: Interphase Corporation
physical id: 2
capabilities: pnp
configuration: driver=system
*-pnp00:03
product: PnP device PNP0303
physical id: 3
capabilities: pnp
configuration: driver=i8042 kbd
*-pnp00:04
product: PnP device PNP0c02
physical id: 4
capabilities: pnp
configuration: driver=system
*-pnp00:05
product: PnP device PNP0c02
physical id: 5
capabilities: pnp
configuration: driver=system
*-pnp00:06
product: PnP device PNP0c02
physical id: 6
capabilities: pnp
configuration: driver=system
*-pnp00:07
product: PnP device PNP0c02
physical id: 7
capabilities: pnp
configuration: driver=system
*-memory UNCLAIMED
description: Memory controller
product: Sunrise Point-LP PMC
vendor: Intel Corporation
physical id: 1f.2
bus info: pci@0000:00:1f.2
version: 21
width: 32 bits
clock: 33MHz (30.3ns)
capabilities: bus_master
configuration: latency=0
resources: memory:ef24c000-ef24ffff
*-multimedia
description: Audio device
product: Sunrise Point-LP HD Audio
vendor: Intel Corporation
physical id: 1f.3
bus info: pci@0000:00:1f.3
logical name: card0
logical name: /dev/snd/controlC0
logical name: /dev/snd/hwC0D0
logical name: /dev/snd/hwC0D2
logical name: /dev/snd/pcmC0D0c
logical name: /dev/snd/pcmC0D0p
logical name: /dev/snd/pcmC0D10p
logical name: /dev/snd/pcmC0D3p
logical name: /dev/snd/pcmC0D7p
logical name: /dev/snd/pcmC0D8p
logical name: /dev/snd/pcmC0D9p
version: 21
width: 64 bits
clock: 33MHz
capabilities: pm msi bus_master cap_list
configuration: driver=snd_hda_intel latency=32
resources: irq:131 memory:ef248000-ef24bfff memory:ef220000-ef22ffff
*-input:0
product: HDA Intel PCH Headphone Mic
physical id: 0
logical name: input16
logical name: /dev/input/event13
*-input:1
product: HDA Intel PCH HDMI/DP,pcm=3
physical id: 1
logical name: input17
logical name: /dev/input/event14
*-input:2
product: HDA Intel PCH HDMI/DP,pcm=7
physical id: 2
logical name: input18
logical name: /dev/input/event15
*-input:3
product: HDA Intel PCH HDMI/DP,pcm=8
physical id: 3
logical name: input19
logical name: /dev/input/event16
*-input:4
product: HDA Intel PCH HDMI/DP,pcm=9
physical id: 4
logical name: input20
logical name: /dev/input/event17
*-input:5
product: HDA Intel PCH HDMI/DP,pcm=10
physical id: 5
logical name: input21
logical name: /dev/input/event18
*-serial
description: SMBus
product: Sunrise Point-LP SMBus
vendor: Intel Corporation
physical id: 1f.4
bus info: pci@0000:00:1f.4
version: 21
width: 64 bits
clock: 33MHz
configuration: driver=i801_smbus latency=0
resources: irq:16 memory:ef252000-ef2520ff ioport:f040(size=32)
*-network
description: Ethernet interface
product: Ethernet Connection (4) I219-LM
vendor: Intel Corporation
physical id: 1f.6
bus info: pci@0000:00:1f.6
logical name: enp0s31f6
version: 21
serial: 10:65:30:76:2e:8c
capacity: 1Gbit/s
width: 32 bits
clock: 33MHz
capabilities: pm msi bus_master cap_list ethernet physical tp 10bt 10bt-fd 100bt 100bt-fd 1000bt-fd autonegotiation
configuration: autonegotiation=on broadcast=yes driver=e1000e driverversion=5.15.0-75-generic firmware=0.1-4 latency=0 link=no multicast=yes port=twisted pair
resources: irq:124 memory:ef200000-ef21ffff
*-battery
product: DELL MT31P84
vendor: Samsung SDI
physical id: 1
version: 04/03/2018
serial: 810A
slot: Sys. Battery Bay
capacity: 67990mWh
configuration: voltage=7.6V
*-input:0
product: Lid Switch
physical id: 2
logical name: input0
logical name: /dev/input/event0
capabilities: platform
*-input:1
product: Power Button
physical id: 3
logical name: input1
logical name: /dev/input/event1
capabilities: platform
*-input:2
product: Intel HID 5 button array
physical id: 4
logical name: input10
logical name: /dev/input/event10
capabilities: platform
*-input:3
product: Dell WMI hotkeys
physical id: 5
logical name: input11
logical name: /dev/input/event5
capabilities: platform
*-input:4
product: DELL0816:00 044E:121F Mouse
physical id: 6
logical name: input12
logical name: /dev/input/event6
logical name: /dev/input/mouse0
capabilities: i2c
*-input:5
product: DELL0816:00 044E:121F Touchpad
physical id: 7
logical name: input13
logical name: /dev/input/event7
logical name: /dev/input/mouse1
capabilities: i2c
*-input:6
product: DELL0816:00 044E:121F UNKNOWN
physical id: 8
logical name: input14
logical name: /dev/input/event11
capabilities: i2c
*-input:7
product: Sleep Button
physical id: 9
logical name: input2
logical name: /dev/input/event2
capabilities: platform
*-input:8
product: Power Button
physical id: a
logical name: input3
logical name: /dev/input/event3
capabilities: platform
*-input:9
product: AT Translated Set 2 keyboard
physical id: b
logical name: input4
logical name: /dev/input/event4
logical name: input4::capslock
logical name: input4::numlock
logical name: input4::scrolllock
capabilities: i8042
*-input:10
product: Video Bus
physical id: c
logical name: input8
logical name: /dev/input/event8
capabilities: platform
*-input:11
product: Intel HID events
physical id: d
logical name: input9
logical name: /dev/input/event9
capabilities: platform
```

# Software
```
nayeon@CLAPP-222-PC17:~/Desktop/c-vs-python-concurrency/docs$ lsb_release -a
No LSB modules are available.
Distributor ID: Ubuntu
Description: Ubuntu-Server 22.04.2 CS_100 (Cubic 2023-05-30 09:42)
Release: 22.04
Codename: jammy
nayeon@CLAPP-222-PC17:~/Desktop/c-vs-python-concurrency/docs$ python3 --version
Python 3.10.6
```

