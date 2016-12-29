#include "SPPoint.h"
#include "SPBPriorityQueue.h"

#ifndef EX_2_MAIN_AUX_H
#define EX_2_MAIN_AUX_H

/**
 * @param dim - the dimension of the point
 * @param index - the index of the point
 * @return new created point P from user with
 * P.dimension = dim and P.index index
 */
SPPoint *mainAuxScanPoint(int dim, int index);

/**
 *
 * @param dim - the dimension of the point
 * @param n - number of point read from user
 * @return n Points from user
 */
SPPoint **mainAuxScanPoints(int dim, int n);

/**
 * Prints K points
 * @param queue - The queue which stores the
 * K nearest point to the query point
 */
void mainAuxPrintKPoints(SPBPQueue *queue);

#endif