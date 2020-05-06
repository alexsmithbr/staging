/*
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (C) 2017-2019, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

#include "property_service.h"
#include "vendor_init.h"

using android::init::property_set;

#define BASEBAND "androidboot.baseband"
#define BOOTDEVICE "androidboot.bootdevice"
#define HWVER "android.letv.hardware_version"
#define PANEL "mdss_mdp.panel"
#define PRODUCT "android.letv.product"
#define SERIALNO "androidboot.serialno"

static void import_cmdline(char *name, int for_emulator)
{
    char *value = strchr(name, '=');
    int name_len = strlen(name);

    if (value == 0) return;
    *value++ = 0;
    if (name_len == 0) return;

    if (!strcmp(name, BASEBAND)) {
        property_set("ro.boot.baseband", value);
        property_set("ro.baseband", value);
    } else if (!strcmp(name, BOOTDEVICE))
        property_set("ro.boot.bootdevice", value);
    else if (!strcmp(name, HWVER))
        property_set("ro.config.hardware_version", value);
    else if (!strcmp(name, PANEL))
        return; /* not sure what to do here */
    else if (!strcmp(name, PRODUCT)) {
        property_set("ro.config.product", value);
        property_set("ro.product.model", value);
        property_set("ro.product.device", value);
    } else if (!strcmp(name, SERIALNO)) {
        property_set("ro.boot.serialno", value);
        property_set("ro.serialno", value);
    }
}

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties() {

    import_kernel_cmdline(0, import_cmdline);

    /* America */
    /* TODO: Parse these from kernel command line */
    property_set("ro.board.platform", "msm8994");
    property_set("ro.hardware", "qcom");
    property_set("ro.boot.hardware", "qcom");
    property_set("ro.bootloader", "unknown");
    property_set("ro.bootmode", "unknown");
    property_set("ro.rf_version", "TDD_FDD_Am"); //Sure, why not
    property_set("ro.sf.lcd_density", "480");
    property_set("ro.boot.console", "ttyHSL0");
    property_set("ro.product.board", "MSM8994");

    property_override("ro.build.product", "Max1");
    property_override_dual("ro.product.device", "ro.product.vendor.device", "Max1");

    /* Dalvik props */
    sysinfo(&sys);
    if (sys.totalram > 3072ull * 1024 * 1024) {
        /* Values for 4GB RAM vatiants */
        property_set("dalvik.vm.heapgrowthlimit", "288m");
        property_set("dalvik.vm.heapsize", "768m");
    } else {
        /* Values for 3GB RAM vatiants */
        property_set("dalvik.vm.heapgrowthlimit", "192m");
        property_set("dalvik.vm.heapsize", "512m");
    }
}
