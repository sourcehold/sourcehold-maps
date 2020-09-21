# cython: language_level=3

cimport cpklib


def explode(unsigned char[:] input, unsigned char[:] output):
	cdef:
		int inlen
		int amount
		int outlen
		
	inlen = input.size
	
	outlen = output.size

	amount = cpklib.explode_nocb(<unsigned char *> &output[0], &outlen, <unsigned char *> &input[0], inlen)
	
	return outlen
	
	
	
def implode(unsigned char [:] input, unsigned char [:] output, int level):
	cdef:
		int inlen
		int outlen
		int compression_level
		
	compression_level = level - 3
	inlen = input.size
	outlen = output.size
	
	cpklib.implode_nocb(<unsigned char *> &output[0], &outlen, <unsigned char *> &input[0], inlen, 0, compression_level)

	return outlen