
#undef LOG_TAG

#define LOG_TAG "Antony"

#include <log/log_main.h>

#include <utils/Timers.h>

// using namespace android;

int main(int argc, char** argv) {

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    nsecs_t now = systemTime(); // by default, it is SYSTEM_TIME_MONOTONIC

    ALOGD("now is: %lld\n", (long long int)now);

    return 0;
}
