# cython: language_level=3

cdef extern from "pklib.h":
	int explode_nocb(unsigned char * , int * , unsigned char * , int )
	void implode_nocb(unsigned char * , int *, unsigned char * , int , int , int )
	