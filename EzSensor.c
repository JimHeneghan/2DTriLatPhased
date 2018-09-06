#include <stdio.h>
#include <stdlib.h>
#include "fdtd-macro-tmz.h"
#include <complex.h>
/*code to record a sensor of the data*/
void sensorInit(Grid *g, double Kx, double Ky, int j){
	char filename[100];
	FILE *out;
	sprintf(filename, "PBGData/SquareLat%d.txt",j);
        out = fopen(filename, "a");	
	fprintf(out, "%g \t %g \n", Kx, Ky);
	fclose(out);
	
return;
}



void Transmission(Grid *g, int j,  double time){
        char filename[100];
        double Time1;
        FILE *out;
        sprintf(filename, "PBGData/SquareLat%d.txt", j);
        out = fopen(filename, "a");
        Time1 = time*5.4683e-13;
		
        /* print the time stamp and the Ex field right before the QWS*/
        fprintf(out, "%g \t %g \t %g \t %g \t %g \t %g \t %g \t %g \t %g \t %g \t %g\n", Time1, creal(Ez(3, 70)), cimag(Ez(3, 70)), creal(Ez(33, 33)), cimag(Ez(33, 33)), creal(Ez(50, 18)), cimag(Ez(50, 18)), creal(Ez(5, 72)), cimag(Ez(5, 72)), creal(Ez(13, 10)), cimag(Ez(13, 10)));
        fclose(out);
}
