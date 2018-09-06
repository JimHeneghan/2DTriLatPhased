/* Header file to accompany ezinc3.c. */

#ifndef _EZINC_H   /*@ \label{ezincHA} @*/
#define _EZINC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdtd-macro-tmz.h"
#include <complex.h>

void ezIncInit(Grid *g);
void ezInc(Grid *g,double time, double locX, double locY, double Kx, double Ky);

#endif  /* matches #ifndef _EZINC3_H */
