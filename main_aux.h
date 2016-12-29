#include "SPPoint.h"
#include "SPBPriorityQueue.h"

#ifndef EX_2_MAIN_AUX_H
#define EX_2_MAIN_AUX_H

SPPoint *mainAuxScanPoint(int dim, int index);

SPPoint **mainAuxScanPoints(int dim, int n);

void mainAuxPrintKPoints(SPBPQueue *queue);

#endif