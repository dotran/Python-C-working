
import numpy
import ctypes # from ctypes import *

_libmyCfuncs = numpy.ctypeslib.load_library('libmyCfuncs', '.')

_libmyCfuncs.myHello.argtypes = [ctypes.c_int]
_libmyCfuncs.myHello.restype  = ctypes.c_void_p

_libmyCfuncs.myDprod.argtypes = [numpy.ctypeslib.ndpointer(dtype=numpy.float), ctypes.c_int]
_libmyCfuncs.myDprod.restype  = ctypes.c_double

_libmyCfuncs.myDcumsum.argtypes = [numpy.ctypeslib.ndpointer(dtype=numpy.float),
                                   numpy.ctypeslib.ndpointer(dtype=numpy.float),
                                   ctypes.c_int]
_libmyCfuncs.myDcumsum.restype  = ctypes.c_void_p


def callHello(n):
    return _libmyCfuncs.myHello(int(n))

def callDprod(x, n=None):
    if n is None:
        n = len(x)
    x = numpy.asarray(x, dtype=numpy.float) # declare array x, but not explicitly allocate memory???
    return _libmyCfuncs.myDprod(x, int(n)) # send the pointer to x to the called function

def callDcumsum(a, n):
    a = numpy.asarray(a, dtype=numpy.float)
    b = numpy.empty(len(a), dtype=numpy.float) # what is this? Allocate memory for array b???
    _libmyCfuncs.myDcumsum(b, a, int(n))
    return b


class Greeting(object):
    def __init__(self):
        self.obj = _libmyCfuncs.myClassObj()
        #self._as_parameter_ = n
    
    def callGreeting(self, n):
        _libmyCfuncs.myGreeting(self.obj, n)


