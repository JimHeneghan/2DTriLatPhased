#include "ezinc.h"
#include <stdio.h>
#include <complex.h>
#include <math.h>

static double cdtds, ppw = 0;

/* initialize source-function variables */
void ezIncInit(Grid *g){

  //printf("Enter the points per wavelength for Ricker source: ");
  //scanf(" %lf", &ppw);
  ppw = 30;
  cdtds = Cdtds;   /*@ \label{ezinc2DA} @*/
  return;
}

/* calculate source function at given time and location */
void ezInc(Grid *g, double time, double LocX, double LocY, double Kx, double Ky) {
  double arg, dx, je, omega, dt, delta, deltat, arg2;
  double delx, dely;
  double LocX2, LocY2 ;
  delx = 86;
  dely = 50.0;
  double dTime = (double) time;
  LocX2 = LocX + delx;
  LocY2 = LocY + dely;

  dx = 1e-8;
  je = 50.0;
  dt = dx/(3e8*sqrt(2.0));
  omega  = 2.0*3e8*M_PI/(je*dx);


  arg = (dTime*dt - dt*1000.0)/50.0/dt;
  arg2 = arg * arg;
  delta =  (delx*Kx + dely*Ky)*dx;

  Dz((int)LocX, (int)LocY) = Dz((int)LocX, (int)LocY) - exp(-0.5*arg2)*sin(omega*(dTime*dt - 1000*dt));
  Dz((int)LocX2, (int)LocY2) = Dz((int)LocX2, (int)LocY2) - exp(-0.5*arg2)*sin(omega*(dTime*dt - 1000*dt))*cexp(I*delta);
}
