#ifndef _FDTD_GRID1_H
#define _FDTD_GRID1_H
#include <complex.h>
enum GRIDTYPE{oneDGrid, teZGrid, tmZGrid, threeDGrid};

struct Grid{
	complex double *hx, *chxh, *chxe, *curlH;
	complex double *hy, *chyh, *chye;
	complex double *hz, *chzh, *chze;
	complex double *ex, *cexe, *cexh;
	complex double *ey, *ceye, *ceyh;
	complex double *ez, *ceze, *cezh;
	complex double *dz, *iz, *cezd;
        complex double *curlEHy, *curlEHx;
	complex double *kx, *ky;
	complex double phix, phiy;
        double *epsR;
        int sizeX, sizeY, sizeZ;
	int time, maxTime;
	int type;
	complex double cdtds;
};

typedef struct Grid Grid;

#endif
