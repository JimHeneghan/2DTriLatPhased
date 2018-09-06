#hi from the outside
from numpy import *
from scipy import *
from pylab import *
import math
bloch = loadtxt("pbg3.txt", usecols=(0,),  unpack =True)
freq = loadtxt("pbg3.txt", usecols=(1,),  unpack =True)
symm = [ 'X', r'$\Gamma$', 'J',  'X']
coord = [0, 9, 19, 25]
a = 0.5
c = 3e8
const = a/c
ylabel('fa/c')
ylim(0,1)
#xlim(0,42)
axvline(x =9, color = 'black')
axvline(x =19, color = 'black')
xticks(coord, symm)
title('Phased source 10x resolution')
plot(bloch, freq*const, '.', color = 'black')
show()

