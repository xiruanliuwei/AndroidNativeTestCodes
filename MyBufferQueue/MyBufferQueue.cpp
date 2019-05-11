
#undef LOG_TAG

#define LOG_TAG "Antony"

#include <gui/BufferQueue.h>
#include <gui/IGraphicBufferConsumer.h>
#include <gui/IGraphicBufferProducer.h>

#include <log/log.h>

using namespace android;

int main(int argc, char** argv) {

    ALOGD("argc is: %d\n", argc);
    ALOGD("argv is: %p\n", argv);

    sp<IGraphicBufferProducer> producer;  // BufferQueueProducer
    sp<IGraphicBufferConsumer> consumer;  // BufferQueueConsumer

    BufferQueue::createBufferQueue(&producer, &consumer, true);  // true: consumed by SurfaceFlinger

    ALOGD("producer.get() is: %p\n", producer.get());
    ALOGD("consumer.get() is: %p\n", consumer.get());



    return 0;
}

