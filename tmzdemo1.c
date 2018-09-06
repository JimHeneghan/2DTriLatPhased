/* TMz simulation with Ricker source at center of grid. */

#include "fdtd-alloc1.h"
#include "fdtd-macro-tmz.h"
#include "fdtd-proto1.h"
#include "ezinc.h"
#include <stdio.h>
#include <complex.h>
#include <math.h>
void runsim(float k_x, float k_y, float t_seed, float i)
{
//  printf("Hi 0");
  Grid *g;
//  Number = num;
  ALLOC_1D(g, 1, Grid); // allocate memory for Grid
  MaxTime = t_seed;

  float Kx = k_x;
  float Ky = k_y;
  int j = (int) i;
  sensorInit(g, Kx, Ky, j);
  gridInit(g, Kx, Ky);        // initialize the grid
//  abcInit(g);     // initialize ABC
  ezIncInit(g);
  printf("Hi 0");
//  snapshotInit2d(g);  // initialize snapshots
/* do time stepping */
  for (Time = 0; Time < MaxTime; Time++) {
//    printf("Hi 1");
    updateD2d(g);     // update magnetic field

//    if (Time < 500)
    ezInc(g, Time, 18.0, 25.0, Kx, Ky);
    //Dz(106, 75) += cexp(I*(Kx*50 +Ky*87))*ezInc(Time, 68.0, 112.0, Kx, Ky);
    /* Dz( 5, 13)  += ezInc(Time, 5.0, 13.0, Kx, Ky); */
    /* Dz(92, 63)  += ezInc(Time, 92.0, 63.0, Kx, Ky); */
    /* Dz(10, 10)  += ezInc(Time, 10.0, 10.0, Kx, Ky); */
    /* Dz(97, 60)  += ezInc(Time, 97.0, 60.0, Kx, Ky); */
    /* Dz(18, 30)  += ezInc(Time, 18.0, 30.0, Kx, Ky); */
    /* Dz(105, 80) += ezInc(Time, 105.0, 80.0, Kx, Ky); */
    //    abc(g);                 //apply ABC
    Transmission(g, j, Time);
   updateE2d(g);     // update electric field
   updateH2d(g);
//    snapshot2d(g);    // take a snapshot (if appropriate)
  } // end of time-stepping

}
/*cexp(-I*(Kx*87.0 + Ky*50.0)*180/M_PI)*/
