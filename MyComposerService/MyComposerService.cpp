
#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "Antony"

#include <binder/IBinder.h>

#include <gui/IDisplayEventConnection.h>
#include <gui/ISurfaceComposer.h>
#include <gui/ISurfaceComposerClient.h>

#include <log/log_main.h>

#include <private/gui/BitTube.h>
#include <private/gui/ComposerService.h>

#include <ui/DisplayStatInfo.h>

using namespace android;

int main(int argc, char** argv) {

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    sp<ISurfaceComposer> composer = ComposerService::getComposerService();

    sp<ISurfaceComposerClient> client = composer.get()->createConnection();

    ALOGD("client.get() is: %p\n", client.get());

    sp<IBinder> main_display = composer.get()->getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
    ALOGD("main_display is: %p\n", main_display.get());

    sp<IBinder> hdmi_display = composer.get()->getBuiltInDisplay(ISurfaceComposer::eDisplayIdHdmi);
    ALOGD("hdmi_display is: %p\n", hdmi_display.get());

    {
        sp<IDisplayEventConnection> connection = composer.get()->createDisplayEventConnection(
            ISurfaceComposer::eVsyncSourceSurfaceFlinger
            );

        ALOGD("connection.get() is: %p\n", connection.get());

        gui::BitTube bt;

        if(nullptr != connection.get()) {
            connection.get()->stealReceiveChannel(&bt);

            ALOGD("BitTube, getFd is: %d\n", bt.getFd());
            ALOGD("BitTube, getSendFd is: %d\n", bt.getSendFd());

        }
    }

    {
        status_t result = 0;

        DisplayStatInfo stats;

        result = composer.get()->getDisplayStats(main_display, &stats);

        ALOGD("stats.vsyncTime is: %lld\n", (long long int)(stats.vsyncTime));
        ALOGD("stats.vsyncPeriod is: %lld\n", (long long int)(stats.vsyncPeriod));
    }

    

    return 0;
}