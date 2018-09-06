#ifndef _FDTD_MACRO_TMZ_H
#define _FDTD_MACRO_TMZ_H

#include "fdtd-grid1.h"
#include <complex.h>

/* macros that permit the "Grid" to be specified */
/* one -dimensional grid */
#define Hy1G(G, M)	G->hy[M]
#define Chyh1G(G, M)	G->chyh[M]
#define Chye1G(G, M)	G->chye[M]

#define Ez1G(G, M)	G->ez[M]
#define Ceze1G(G, M)	G->ceze[M]
#define Cezh1G(G, M)	G->cezh[M]

#define Dz1G(G, M)      G->dz[M]

/* TMz grid */
#define HxG(G, M, N)	G->hx[(M) * (SizeYG(G)) + (N)]
#define ChxhG(G, M, N)	G->chxh[(M) * (SizeYG(G)) + (N)]
#define ChxeG(G, M, N)	G->chxe[(M) * (SizeYG(G)) + (N)]
#define CurlEHxG(G, M, N)  G->curlEHx[(M) * (SizeYG(G)) + (N)]

#define HyG(G, M, N) G->hy[(M) * SizeYG(G) + (N)]
#define ChyhG(G, M, N) G->chyh[(M) * SizeYG(G) + (N)]
#define ChyeG(G, M, N) G->chye[(M) * SizeYG(G) + (N)]
#define CurlEHyG(G, M, N) G->curlEHy[(M) * SizeYG(G) + (N)]
#define EpsRG(G, M, N) G->epsR[(M) * SizeYG(G) + (N)]

#define CurlHG(G, M, N) g->curlH[(M) * SizeYG(G) + (N)]

#define EzG(G, M, N) G->ez[(M) * SizeYG(G) + (N)]
#define CezeG(G, M, N) G->ceze[(M) * SizeYG(G) + (N)]
#define CezhG(G, M, N) G->cezh[(M) * SizeYG(G) + (N)]

#define DzG(G, M, N) G->dz[(M) * SizeYG(G) + (N)]
#define IzG(G, M, N) G->iz[(M) * SizeYG(G) + (N)]
#define CezdG(G, M, N) G->cezd[(M) * SizeYG(G) + (N)]

#define SizeXG(G) G->sizeX
#define SizeYG(G) G->sizeY
#define SizeZG(G) G->sizeZ
#define TimeG(G) G->time
#define MaxTimeG(G) G->maxTime
#define CdtdsG(G) G->cdtds
#define TypeG(G) G->type
#define PhixG(G) G->phix
#define PhiyG(G) G->phiy
//#define KxG(G) G->kx
//#define KyG(G) G->ky
/* macros that assume the "Grid" is "g" */
/* one-dimensional grid */
#define Hy1(M) Hy1G(g, M)
#define Chyh1(M) Chyh1G(g, M)
#define Chye1(M) Chye1G(g, M)

#define Ez1(M) Ez1G(g, M)
#define Ceze1(M) Ceze1G(g, M)
#define Cezh1(M) Cezh1G(g, M)

#define Dz1(M) Dz1G(g, M)

/* TMz grid */
#define Hx(M, N) HxG(g, M, N)
#define Chxh(M, N) ChxhG(g, M, N)
#define Chxe(M, N) ChxeG(g, M, N)

#define Hy(M, N) HyG(g, M, N)
#define Chyh(M, N) ChyhG(g, M, N)
#define Chye(M, N) ChyeG(g, M, N)

#define CurlH(M, N) CurlHG(g, M, N)
#define CurlEHy(M, N) CurlEHyG(g, M, N)
#define CurlEHx(M, N) CurlEHxG(g, M, N)
#define EpsR(M, N) EpsRG(g, M, N)

#define Ez(M, N) EzG(g, M, N)
#define Ceze(M, N) CezeG(g, M, N)
#define Cezh(M, N) CezhG(g, M, N)

#define Dz(M, N) DzG(g, M, N)
#define Iz(M, N) IzG(g, M, N)
#define Cezd(M, N) CezdG(g, M, N)

#define SizeX SizeXG(g)
#define SizeY SizeYG(g)
#define SizeZ SizeZG(g)
#define Time TimeG(g)
#define MaxTime MaxTimeG(g)
#define Cdtds CdtdsG(g)
#define Type TypeG(g)
#define Phix PhixG(g)
#define Phiy PhiyG(g)
//#define Kx KxG(g)
//#define Ky KyG(g)
#endif /* matches #ifndef _FDTD_MACRO_TMZ_H */
