#include <stdio.h>
#include <assert.h>
#include "SPBPriorityQueue.h"
#include "SPPoint.h"
#include "main_aux.h"

int main() {
    int n, d, k;
    scanf("%d %d %d", &n, &d, &k);
    assert(1 <= k && k <= n);
    SPPoint **points = mainAuxScanPoints(d, n);
    assert(points != NULL);
    SPPoint *q = mainAuxScanPoint(d, -1);
    assert(q != NULL);
    SPBPQueue *queue = spBPQueueCreate(k);
    assert(queue != NULL);
    for(int i = 0; i < n; i++) assert(spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q)) == SP_BPQUEUE_SUCCESS);
    BPQueueElement element;
    bool isEmpty = spBPQueueIsEmpty(queue);
    while(!isEmpty) {
        assert(spBPQueuePeek(queue, &element) == SP_BPQUEUE_SUCCESS);
        printf("%d", element.index);
        assert(spBPQueueDequeue(queue) == SP_BPQUEUE_SUCCESS);
        isEmpty = spBPQueueIsEmpty(queue);
        if(!isEmpty) printf(", ");
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        spPointDestroy(points[i]);
    }
    spPointDestroy(q);
    spBPQueueDestroy(queue);
    return 0;
}