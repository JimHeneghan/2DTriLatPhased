#include "fdtd-macro-tmz.h"
#include "fdtd-alloc1.h"
#include <math.h>
#include <complex.h>

void gridInit(Grid *g, float kx, float ky) {
  double imp0 = 377.0;
//  double Sigma = 0;
  double dx = 1e-8;
  double dt = dx/(3e8*sqrt(2));
  double Epsz = 8.85418782e-12;
  int mm, nn;

  Type = tmZGrid;                          
  SizeX = 100;             // x size of domain
  SizeY = 173;              // y size of domain
  //MaxTime = 300;           // duration of simulation
  Cdtds = 1.0 / sqrt(2.0); // Courant number
  float Kx = kx;
  float Ky = ky;
  double XCenter, YCenter, r2, XLocC, YLocC, rad, XLoc1, XLoc2, YLoc1, YLoc2;
 
  printf("Kx is %f, Ky is %f \n", Kx, Ky);  


  /*setting the bloch boundary coeficcients*/
  Phix = cexp(-1*I*Kx*SizeX*dx);
  Phiy = cexp(-1*I*Ky*SizeY*dx);
 
  printf("Phix is %f + i%f \n", creal(Phix), cimag(Phiy));

  ALLOC_2D(g->hx,   SizeX, SizeY, complex double); 
  ALLOC_2D(g->chxh, SizeX, SizeY, complex double);
  ALLOC_2D(g->chxe, SizeX, SizeY, complex double);
  ALLOC_2D(g->hy,   SizeX, SizeY, complex double);
  ALLOC_2D(g->chyh, SizeX, SizeY, complex double);
  ALLOC_2D(g->chye, SizeX, SizeY, complex double);
  ALLOC_2D(g->ez,   SizeX, SizeY, complex double);
  ALLOC_2D(g->ceze, SizeX, SizeY, complex double);
  ALLOC_2D(g->cezh, SizeX, SizeY, complex double);    
  ALLOC_2D(g->curlH, SizeX, SizeY , complex double);
  ALLOC_2D(g->curlEHx, SizeX, SizeY , complex double);
  ALLOC_2D(g->curlEHy, SizeX, SizeY , complex double);
  ALLOC_2D(g->dz,   SizeX, SizeY, complex double);
  ALLOC_2D(g->iz,   SizeX, SizeY, complex double);
  ALLOC_2D(g->cezd,   SizeX, SizeY, complex double);
  ALLOC_2D(g->epsR,   SizeX, SizeY, double);
  /* set electric-field update coefficients */
  /*  Setting the media*/
  rad = 0.15*100;
  XCenter = SizeX/2;
  YCenter = SizeY/2;
  r2 = rad*rad;

  for (mm = 0; mm < SizeX; mm++){
	XLoc1 = mm - 0;
        XLoc2 = SizeX - mm;
        XLocC = mm - XCenter;
      for (nn = 0; nn < SizeY; nn++){ 
        YLoc1 = nn - 0;
        YLoc2 = SizeY - nn;
        YLocC = nn - YCenter;
	if(XLocC*XLocC + YLocC*YLocC < r2)
		EpsR(mm, nn) = 8.41;
	else if(XLoc1*XLoc1 + YLoc1*YLoc1 < r2 )
		EpsR(mm, nn) = 8.41;
	else if(XLoc1*XLoc1 + YLoc2*YLoc2 < r2)
                EpsR(mm, nn) = 8.41;
	else if(XLoc2*XLoc2 + YLoc2*YLoc2 < r2)
                EpsR(mm, nn) = 8.41;
	else if(XLoc2*XLoc2 + YLoc1*YLoc1 < r2 )
                EpsR(mm, nn) = 8.41;
	else
		EpsR(mm, nn) = 1.0;

    }
  }
  //  for (mm = 0; mm < SizeX; mm++)
//    for (nn = 0; nn < SizeY; nn++) {
//	Cezd(mm, nn) = 1.0/(EpsR(mm, nn) + (Sigma*dt/Epsz)) ;
//       Ceze(mm, nn) = Sigma*dt/Epsz;
//    }


  /* set magnetic-field update coefficients */
  for (mm = 0; mm < SizeX; mm++)
    for (nn = 0; nn < SizeY; nn++) {
      Chxh(mm, nn) = 1.0;
      Chxe(mm, nn) = Cdtds / imp0;
    }

  for (mm = 0; mm < SizeX; mm++)
    for (nn = 0; nn < SizeY; nn++) {
      Chyh(mm, nn) = 1.0;
      Chye(mm, nn) = Cdtds / imp0;
    }

  float temp;
  char filename[100];
  FILE *out;
  sprintf(filename,"Media/Square.dat");
  out = fopen(filename,"w");

  for (nn=SizeY-1; nn>=0; nn--)
    for (mm=0; mm<SizeX; mm++) {
      temp = (float)EpsR(mm,nn); // store data as a float
      fprintf(out, "%f \n", temp);
    }

  fclose(out);
  
  return;
}
