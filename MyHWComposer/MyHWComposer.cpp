
#define LOG_TAG "Antony"

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

#include <log/log_main.h>

// using namespace android;

int main(int argc, char** argv) {

    int result = 0;

    hw_module_t const* module;

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    result = hw_get_module(HWC_HARDWARE_MODULE_ID, &module);

    ALOGD("result is: %d\n", result);

    hw_device_t* device = nullptr;

    result = module->methods->open(module, HWC_HARDWARE_COMPOSER, &device);
    ALOGD("open result is: %d\n", result);

    // device should point to struct hwc_context_t, defined in hardware/libhardware/modules/hwcomposer/hwcomposer.cpp
    struct hwc_composer_device_1* hwc_device = (struct hwc_composer_device_1*)device;

    uint32_t configs[128];
    size_t numConfigs;

    result = hwc_device->getDisplayConfigs(hwc_device, 0, configs, &numConfigs);

    ALOGD("getDisplayConfigs result is: %d\n", result);
    // ALOGD("configs is: %u\n", configs);
    // ALOGD("numConfigs is: %zd\n", numConfigs);

    ALOGD("numConfigs is: %zd\n", numConfigs);

    int index = 0;
    for(index = 0; index < 128; index++) {
        ALOGD("configs[%d] is: %u\n", index, configs[index]);
    }

    return 0;
}