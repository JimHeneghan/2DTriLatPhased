#Lbraries *******************************************************************
from numpy import *
from scipy import *
from pylab import *
import math
#opening a file that will store all the values for our PBG diagram
f = open("pbg3.txt", "w")
val = 0
for i in range (1, 64):
    E1 = "EmptyLat%d" %i
    E2 = "HI.txt"
    E = E1 + E2
    finder = E1 + ".txt"
    omega = loadtxt(E, usecols=(0,), skiprows= 1, unpack =True)
    E0 = loadtxt(E, usecols=(1,), skiprows= 1, unpack =True)

    M = len(E0)
    print M

    print E
    print "\n"
#finding out how many points are in our range
# finding the maximum point in our window
    for j in range (0, M):
	Max = omega[j]
	if (Max > 7e14):
		break


#finding peaks for every point in our range
    for i in range (1, j):
#	if(E0[i] > 4):
    		if ((E0[i-1] < E0[i])and( E0[i] > E0[i+1])):
			thang1 = str(val)
                        thang2 = str(omega[i])
#recording every peak for each file along with the bloch vector for that file
                        f.write(thang1)
                        f.write("\t")
                        f.write(thang2)
                        f.write("\n")
    val = val + 1


f.close()
