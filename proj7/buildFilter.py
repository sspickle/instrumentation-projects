#
# NodeBox script to build gradient transmission filter for rotary feedback
#

import sys
from math import sin, cos

sw,sh = 500,500

x0=sw/2.0
y0=sw/2.0

size(sw,sh)

pi=3.1415927
R=sw/2

N=360
thetaMin=0.0
thetaMax=pi
dTheta=2*thetaMax/N

theta = thetaMin

while theta < 2*thetaMax:
    fill(abs(thetaMax - theta)/thetaMax)
    x1=R*cos(theta)
    y1=R*sin(theta)
    theta += dTheta
    x2=R*cos(theta)
    y2=R*sin(theta)
    beginpath(x0,y0)
    lineto(x1+x0,y1+y0)
    lineto(x2+x0,y2+y0)
    lineto(x0,y0)
    endpath()
