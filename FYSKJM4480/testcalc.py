from numpy import *
g = 1/2.

c1 = 1
c2 = -g/4.
c3 = -g/8.
c4 = -g/8.
c5 = -g/16.

c = array([c1,c2,c3,c4,c5])

print c/sqrt(sum(c**2))

print sum((c/sqrt(sum(c**2)))**2)

