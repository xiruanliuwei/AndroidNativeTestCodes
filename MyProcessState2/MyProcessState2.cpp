
#define LOG_TAG "Antony"

#include <binder/IBinder.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IInterface.h>

#include <log/log_main.h>

#include <utils/String16.h>
#include <utils/String8.h>
#include <utils/StrongPointer.h>

using namespace android;

static const char* convertString16ToChar(const String16& text) {
    const char16_t* c16_text = text.string();
    const String8 s8_text(c16_text);
    const char* c8_text = s8_text.string();

    ALOGD("&text is: %p\n", &text);
    ALOGD("c16_text is: %p\n", c16_text);
    ALOGD("&s8_text is: %p\n", &s8_text);
    ALOGD("c8_text is: %p\n", c8_text);

    return c8_text;
    // return "succeed";
}

int main(int argc, char** argv) {

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    sp<ProcessState> ps(ProcessState::self());

    bool result = ps.get()->isContextManager();

    if(true == result) {
        ALOGD("result is true, %d\n", (int)result);
    } else {
        ALOGD("result is false, %d\n", (int)result);
    }

    const sp<IBinder> ib = ps.get()->getStrongProxyForHandle(0);

    ALOGD("ib IBinder is: %p\n", ib.get());

    sp<IServiceManager> ism = interface_cast<IServiceManager>(ib);


    const String16 if_descriptor = ism.get()->getInterfaceDescriptor();

    size_t size = if_descriptor.size();
    ALOGD("size is: %zd\n", size);

    // const char16_t* c16_descriptor = if_descriptor.string();
    // String8 s8_descriptor(c16_descriptor);
    // const char* c_descriptor = s8_descriptor.string();

    const char* c8_descriptor = convertString16ToChar(if_descriptor);

    ALOGD("interface descriptor is: %p, %s\n", c8_descriptor, c8_descriptor);

    // sp<IPCThreadState> its(IPCThreadState::self());

    // pid_t pid = its.get()->getCallingPid();

    pid_t pid = IPCThreadState::self()->getCallingPid();
    ALOGD("pid is: %d\n", (int)pid);

    // uid_t uid = its.get()->getCallingUid();

    uid_t uid = IPCThreadState::self()->getCallingUid();
    ALOGD("uid is: %d\n", (int)uid);



    return 0;
}
