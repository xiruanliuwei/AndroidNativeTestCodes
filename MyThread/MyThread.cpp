
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
    MyThread(bool isMain) : mIsMain(isMain) {  // } : Thread(isMain) {  // }: mIsMain(isMain) {
        // mIsMain = isMain;
    }

protected:
    virtual bool threadLoop() {

        printf("i am testing from printf\n");
        ALOGD("I am testing Android Thread ...\n");

        
        pid_t pid = getpid();
        ALOGD("Linux, pid is: %d\n", (int)pid);

        pid_t tid = gettid();
        ALOGD("Linux, tid is: %d\n", (int)tid);

        pthread_t pthread_id = pthread_self();
        ALOGD("Pthread, pthread_id is: %d\n", (int)pthread_id);

        pid_t thread_tid = this->getTid();
        ALOGD("Android Thread getTid, thread_tid is: %d\n", (int)thread_tid);
        

        return false;
    }

    const bool mIsMain;    
};

int main(int argc, char** argv) 
{
    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    ALOGD("i am in main function...\n");

    pid_t main_pid = getpid();
    ALOGD("main process, pid is: %d\n", (int)main_pid);

    pid_t main_tid = gettid();
    ALOGD("main process thread, tid is: %d\n", (int)main_tid);

    MyThread* thread = new MyThread(false);

    thread->run("mythread");

    thread->join();

    // delete thread;

    // while(thread->isRunning()) {
    //     sleep(1);  // second
    // }

    // delete thread;

    return 0;
}