#include "fdtd-macro-tmz.h"
#include <stdio.h>
#include <math.h>
#include <complex.h>
static double  imp0 = 377.0;
static double  epsz = 8.85418782e-12;
/* update magnetic field */
void updateH2d(Grid *g) {
  int mm, nn;

  if (Type == oneDGrid) {  /*@ \label{updatetmzA} @*/
    for (mm = 0; mm < SizeX - 1; mm++)
      Hy1(mm) =  Hy1(mm) + (Ez1(mm + 1) - Ez1(mm));
  } else {

/*writing the curl for the X hi side */
   for(nn = 0; nn < SizeY; nn++)
	CurlEHy(SizeX - 1, nn) = Phix*Ez(0, nn) - Ez(SizeX - 1, nn);

   for (mm = 0; mm < SizeX - 1; mm++)
      for (nn = 0; nn < SizeY; nn++)
	CurlEHy(mm, nn) = Ez(mm + 1, nn) - Ez(mm, nn);

   for (mm = 0; mm < SizeX; mm++)
      for (nn = 0; nn < SizeY; nn++)
        Hy(mm, nn) = Hy(mm, nn) + (CurlEHy(mm, nn))/(sqrt(2));
/*writing the curl for the Y hi side */
   for(mm = 0; mm < SizeX; mm++)
	CurlEHx(mm, SizeY - 1) = Phiy*Ez(mm, 0) - Ez(mm, SizeY -1);

   for (mm = 0; mm < SizeX; mm++)
      for (nn = 0; nn < SizeY -1; nn++)
	CurlEHx(mm,nn) = Ez(mm, nn + 1) - Ez(mm, nn);

   for (mm = 0; mm < SizeX; mm++)
      for (nn = 0; nn < SizeY ; nn++)
	Hx(mm, nn) =  Hx(mm, nn) - (CurlEHx(mm,nn))/(sqrt(2));

  }

  return;
}
void updateE2d(Grid *g) {
  int mm, nn;
  if (Type == oneDGrid) {
    for (mm = 1; mm < SizeX - 1; mm++)
	Ez1(mm) = Dz1(mm);
  } else {

    for (mm = 0; mm < SizeX; mm++)
      for (nn = 0; nn < SizeY; nn++){
	//	printf("EpsR is %f \n", EpsR(mm,nn));
	Ez(mm, nn) = Dz(mm, nn)/EpsR(mm, nn);//Cezd(mm,nn)*(Dz(mm, nn) - Iz(mm, nn));
//        Iz(mm, nn) = Iz(mm, nn) + Ceze(mm, nn)*Ez(mm, nn);
       }
  }

   return;
}


/* update electric field */
void updateD2d(Grid *g) {
  int mm, nn;
  if (Type == oneDGrid) {  /*@ \label{updatetmzC} @*/
    for (mm = 1; mm < SizeX - 1; mm++)
      Dz1(mm) = Dz1(mm)	+ (Hy1(mm) - Hy1(mm - 1));
  } else {

   /* Curl equations for the E field at the boundaries*/
    CurlH(0,0) = ((Hy(0,0) - conj(Phix)*Hy(SizeX -1, 0)) - (Hx(0,0) - conj(Phiy)*Hx(0, SizeY -1)));

    for(nn = 1; nn < SizeY; nn++){
        CurlH(0, nn) = ((Hy(0,nn) - conj(Phix)*Hy(SizeX -1, nn)) - (Hx(0,nn) - Hx(0, nn -1)));
 //       CurlH(SizeX -1, nn) = ((Hy(0,nn) - Hy(SizeX -2, nn)) - (Hx(0,nn) - Hx(0, nn -1)));
    }
 //   CurlH(0, SizeY - 1) = ((Hy(0,0) - Hy(SizeX -2, 0)) - (Hx(0,0) - Hx(0, SizeY-2)));

 //   CurlH(SizeX-1, 0) = ((Hy(0,0) - Hy(SizeX -2, 0)) - (Hx(0,0) - Hx(0, SizeY -2)));

    for (mm = 1; mm < SizeX; mm++){
        CurlH(mm, 0) = ((Hy(mm,0) - Hy(mm -1, 0)) - (Hx(mm,0) - conj(Phiy)*Hx(mm, SizeY -1)));
 //       CurlH(mm, SizeY -1) = ((Hy(mm,0) - Hy(mm, 0)) - (Hx(mm,0) - Hx(mm, SizeY-2)));
    }

 //   CurlH(SizeX-1, SizeY-1) = ((Hy(0,0) - Hy(SizeX -2, SizeY-2)) - (Hx(0,0) - Hx(SizeX-2, SizeY -2)));


    for (mm = 1; mm < SizeX; mm++)
      for (nn = 1; nn < SizeY; nn++){
         CurlH(mm,nn)=  ((Hy(mm, nn) - Hy(mm - 1, nn)) -
                       (Hx(mm, nn) - Hx(mm, nn - 1)));
        }

//	printf("CurlH is %f \n", CurlH(mm, nn));

    for (mm = 0; mm < SizeX; mm++)
      for (nn = 0; nn < SizeY; nn++)
//	temp  = CurlH(mm, nn);
//	printf("CurlH is %f \n",temp);
	Dz(mm, nn) = Dz(mm, nn) + (CurlH(mm,nn))/sqrt(2);
    }

  return;
}
