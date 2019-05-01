
#define LOG_TAG "Antony"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include <log/log_main.h>

#include <sys/types.h>

#include <utils/StrongPointer.h>
#include <utils/Thread.h>

using namespace android;

class MyThread : public Thread {
public:
    MyThread(bool isMain) : mIsMain(isMain) {
        ALOGD("MyThread constructor is called!\n");    
    }

protected:
    virtual bool threadLoop() {

        // sleep(1000);

        // printf("i am testing from printf\n");
        // ALOGD("I am testing Android Thread ...\n");

        printf("new thread, messages from printf\n");
        ALOGD("new thread, messages from ALOGD\n");

        return false;
    }

    const bool mIsMain;    
};

int main(int argc, char** argv) 
{
    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    ALOGD("i am in main function...\n");

    sp<MyThread> t = new MyThread(false);

    t->run("mythread");

    t->join();

    // delete thread;

    // while(thread->isRunning()) {
    //     sleep(1);  // second
    // }

    // delete thread;

    return 0;
}