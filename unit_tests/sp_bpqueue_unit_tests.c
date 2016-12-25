#include "../SPBPriorityQueue.h"
#include "unit_test_util.h"

//Checks if copy Works
bool queueBasicCopyTest() {
    double data[12] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0, 10, 3.5};
    SPBPQueue *q, *p;
    BPQueueElement elementP, elementQ;

    q = spBPQueueCreate(5);
    for(double *val = data; val < data + 12; ++val) ASSERT_TRUE(spBPQueueEnqueue(q, 0, *val) == SP_BPQUEUE_SUCCESS);

    p = spBPQueueCopy(q);
    while(!spBPQueueIsEmpty(p) && !spBPQueueIsEmpty(p)) {
        ASSERT_TRUE(spBPQueuePeek(p, &elementP) == SP_BPQUEUE_SUCCESS);
        ASSERT_TRUE(spBPQueuePeek(q, &elementQ) == SP_BPQUEUE_SUCCESS);
        ASSERT_TRUE(elementP.value == elementQ.value);
        ASSERT_TRUE(spBPQueueDequeue(p) == SP_BPQUEUE_SUCCESS);
        ASSERT_TRUE(spBPQueueDequeue(q) == SP_BPQUEUE_SUCCESS);
    }
    ASSERT_TRUE(spBPQueueIsEmpty(p) && spBPQueueIsEmpty(q));
    spBPQueueDestroy(q);
    spBPQueueDestroy(p);
    return true;
}
bool queueBasicTest() {
    int maxSize = 10;
    double data[12] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0, 10, 3.5};
    SPBPQueue *queue = spBPQueueCreate(maxSize);
    for(double *val = data; val < data + 12; ++val) ASSERT_TRUE(spBPQueueEnqueue(queue, 0, *val) == SP_BPQUEUE_SUCCESS);
    int a = spBPQueueGetMaxSize(queue);
    ASSERT_TRUE(a == maxSize);
    ASSERT_TRUE(spBPQueueSize(queue) == maxSize);
    ASSERT_TRUE(spBPQueueIsFull(queue));
    ASSERT_TRUE(!spBPQueueIsEmpty(queue));
    ASSERT_TRUE(spBPQueueMaxValue(queue) == 8);
    ASSERT_TRUE(spBPQueueMinValue(queue) == 0);
    ASSERT_TRUE(spBPQueueDequeue(queue) == SP_BPQUEUE_SUCCESS);
    ASSERT_TRUE(spBPQueueSize(queue) == maxSize - 1);
    ASSERT_TRUE(!spBPQueueIsFull(queue));
    ASSERT_TRUE(!spBPQueueIsEmpty(queue));
    ASSERT_TRUE(spBPQueueMinValue(queue) == 1);
    spBPQueueClear(queue);
    ASSERT_TRUE(spBPQueueIsEmpty(queue));
    spBPQueueDestroy(queue);
    return true;
}
int main() {
    RUN_TEST(queueBasicCopyTest);
    RUN_TEST(queueBasicTest);
    return 0;
}
