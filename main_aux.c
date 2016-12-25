#include <stdio.h>
#include <stdlib.h>
#include "main_aux.h"

SPPoint *mainAuxScanPoint(int dim, int index) {
    double data[dim];
    for(int i = 0; i < dim; i++) {
        scanf("%lf", data + i);
    }
    SPPoint *point = spPointCreate(data, dim, index);
    return point;
}

SPPoint **mainAuxScanPoints(int dim, int n) {
    SPPoint **points = malloc(n * sizeof(SPPoint *));
    for(int i = 0; i < n; i++) {
        points[i] = mainAuxScanPoint(dim, i + 1);
        if(points[i] == NULL) return NULL;
    }
    return points;
}
