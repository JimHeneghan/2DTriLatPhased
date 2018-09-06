#ifndef _FDTD_PROTO2_H
#define _FDTD_PROTO2_H

#include "fdtd-grid1.h"
#include <complex.h>
/* Function prototypes */
void abcInit (Grid *g);
void abc(Grid *g);

void gridInit1d(Grid *g);
void gridInit(Grid *g, float kx, float ky);

void snapshotInit2d(Grid *g);
void snapshot2d(Grid *g);

//void tfsfInit(Grid *g);
//void tfsfUpdate(Grid *g);

void updateE2d(Grid *g);
void updateH2d(Grid *g);
void updateD2d(Grid *g);
void sensorInit(Grid *g, double Kx, double Ky, int j);
void Transmission(Grid *g, int j, double time);
//void Reflectivity(Grid *g, double time);
#endif
