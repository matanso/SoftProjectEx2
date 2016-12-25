#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBPriorityQueue.h"
#include "SPPoint.h"
#include "main_aux.h"

int main() {
    // Variable declaration
    int n, d, k;

    // Input
    scanf("%d %d %d", &n, &d, &k);
    assert(1 <= k && k <= n);


    SPPoint **points = mainAuxScanPoints(d, n); // Reading n point from user
    assert(points != NULL);
    SPPoint *q = mainAuxScanPoint(d, -1); // Reading query point
    assert(q != NULL);

    // Creating min-queue of size k, so only the k nearest point will remain
    SPBPQueue *queue = spBPQueueCreate(k);

    // Inserting n points to queue according to L2SquaredDistance from query point
    for (int i = 0; i < n; i++)
        spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q));

    // Output
    assert(queue != NULL);
    for(int i = 0; i < n; i++) assert(spBPQueueEnqueue(queue, spPointGetIndex(points[i]), spPointL2SquaredDistance(points[i], q)) == SP_BPQUEUE_SUCCESS);
    BPQueueElement element;
    bool isEmpty = spBPQueueIsEmpty(queue);
    while (!isEmpty) { // Printing k nearest points
        assert(spBPQueuePeek(queue, &element) == SP_BPQUEUE_SUCCESS);
        printf("%d", element.index);
        assert(spBPQueueDequeue(queue) == SP_BPQUEUE_SUCCESS);
        isEmpty = spBPQueueIsEmpty(queue);
        if (!isEmpty) printf(", ");
    }
    printf("\n");


    // Destroy points
    for (int i = 0; i < n; i++) {
        spPointDestroy(points[i]);
    }

    // Freeing Memory
    free(points); // Free point array
    spPointDestroy(q); // Destroy points input queue
    spBPQueueDestroy(queue); // Destroy k-neighbors queue
    return 0;
}