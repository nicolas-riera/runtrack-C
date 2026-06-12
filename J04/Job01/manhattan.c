#include "manhattan.h"

int manhattan(Point a, Point b) {
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}