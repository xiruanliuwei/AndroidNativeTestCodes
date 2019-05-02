
#ifdef TAG_LOG
#undef TAG_LOG
#endif

#define TAG_LOG "Antony"

#include <gui/ISurfaceComposer.h>

#include <log/log_main.h>

#include <private/gui/ComposerService.h>

using namespace std;

int main(int argc, char** argv) {

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    return 0;
}