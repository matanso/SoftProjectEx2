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
    SPPoint *q = mainAuxScanPoint(d, -1);
    SPBPQueue *queue = spBPQueueCreate(k);
    for(int i = 0; i < n; i++) spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q));
    BPQueueElement element;
    bool isEmpty = spBPQueueIsEmpty(queue);
    while(!isEmpty) {
        spBPQueuePeek(queue, &element); // todo look at message
        printf("%d", element.index);
        spBPQueueDequeue(queue);
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