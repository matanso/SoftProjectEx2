#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBPriorityQueue.h"
#include "SPPoint.h"
#include "main_aux.h"

int main() {
    // Variable initialization
    int n, d, k;

    // Input
    scanf("%d %d %d", &n, &d, &k);
    assert(1 <= k && k <= n);

    SPPoint **points = mainAuxScanPoints(d, n); // Reading n point from user
    SPPoint *q = mainAuxScanPoint(d, -1); // Reading query point

    // Creating min-queue of size k, so only the k nearest point will remain
    SPPoint **points = mainAuxScanPoints(d, n);
    assert(points != NULL);
    SPPoint *q = mainAuxScanPoint(d, -1);
    assert(q != NULL);
    SPBPQueue *queue = spBPQueueCreate(k);

    // Inserting n point to queue according to L2SquaredDistance from query point
    for (int i = 0; i < n; i++)
        spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q));

    // Output

    assert(queue != NULL);
    for(int i = 0; i < n; i++) assert(spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q)) == SP_BPQUEUE_SUCCESS);
    BPQueueElement element;
    bool isEmpty = spBPQueueIsEmpty(queue);
    while (!isEmpty) { // Printing k nearest points
        assert(spBPQueuePeek(queue, &element) == SP_BPQUEUE_SUCCESS);
        spBPQueuePeek(queue, &element); // todo look at message
        printf("%d", element.index);
        assert(spBPQueueDequeue(queue) == SP_BPQUEUE_SUCCESS);
        isEmpty = spBPQueueIsEmpty(queue);
        if (!isEmpty) printf(", ");
    }
    printf("\n");


    // Freeing Memory

    // Destroy points
    for (int i = 0; i < n; i++) {
        spPointDestroy(points[i]);
    }

    free(points); // Free point array
    spPointDestroy(q); // Destroy points input queue
    spBPQueueDestroy(queue); // Destroy k-neighbors queue
    return 0;
}