
from pylab import * # Note: "import pylab" does not make rand() function work!!!
import myCwrapper

myCwrapper.callHello(3)

temp = myCwrapper.Greeting()
temp.callGreeting(2)

a = rand(5);
print "My calculation of prod is", myCwrapper.callDprod(a)
print "Python's calculation is  ", a.prod()

