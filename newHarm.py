#Lbraries *******************************************************************
import numpy as np
from scipy import *
from pylab import *
from cmath import *
from numpy import ctypeslib
from ctypes import *
import harminv
import numpy.testing as nt


for z in range (21,68):
    E1 = "EmptyLat%d" %z
    E = E1 + '.txt'
    print E
    P = np.zeros((5,50000), dtype=np.complex64)
    i = 1
    while(i < 11):
        E0R = loadtxt(E, usecols=(i,), skiprows= 1, unpack =True)
        i = i + 1
        E0I = loadtxt(E, usecols=(i,), skiprows= 1, unpack =True)
        E0  = np.zeros(len(E0R), dtype=np.complex64)
        l = i/2 - 1
        for m in range (0, len(E0R)):
            E0[m] = E0R[m] + 1j*E0I[m]
        P[l] = E0
        i = i + 1
        M = len(E0)
    supSumL = np.zeros((5,1000), dtype=np.double)
    finalSum = np.zeros(1000)
    for l in range (0, 5):
        E0chop = P[l][1500: M]
        E0_inv = harminv.Harminv(E0chop, fmin = 0, fmax = 0.015, nf = 300, dt = 1.66667e-12)

        L = np.zeros(1000)
        sumL = np.zeros(len(L))
        domega = 3e6
        for i in range (0, E0_inv.freq.size):
            for k in range (0, 1000):
                L[k] = (1/(2*math.pi))*((1/(2*math.pi*E0_inv.decay[i]))/((domega*k - E0_inv.freq[i]) + (1/(4*math.pi*E0_inv.decay[i]))**2))
                sumL[k] = sumL[k] + L[k]
        supSumL[l] = abs(sumL)

    for j in range (0,1000):
        for i in range (0, 5):
            finalSum[j] = finalSum[j] + supSumL[i][j] 
    #plot(finalSum)
    #show()

    newFinalSum = np.zeros(len(finalSum))
    for n in range (0, len(finalSum)):
        if (finalSum[n] < 0e-12):
            newFinalSum[n] = 0
        else:
            newFinalSum[n] = finalSum[n]
    #plot(newFinalSum)
    #show()
    ff = open(E1 + "HI.txt", 'w')
    for k in range (0, len(newFinalSum)):
        thang1 = str(domega*k)
        thang2 = str(newFinalSum[k])
        ff.write(thang1)
        ff.write("\t")
        ff.write(thang2)
        ff.write("\n")
    ff.close()


