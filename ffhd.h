#ifndef __FFHD_H
#define __FFHD_H

#include <inttypes.h>

typedef uint32_t b4;
typedef uint16_t b2;

char FarbfeldMagicValue[8] = {
	'f', 'a', 'r', 'b', 'f', 'e', 'l', 'd',
} ;

typedef struct {
	/* It contains "farbfeld". No end zero character in the end. */
	char mval[8];
	b4 w; /* Width. */
	b4 h; /* Height. */
	/* Data after it is in format RGBA. (FFPixel data[width*height]) */
} FarbfeldHeader ;

typedef struct {
	b2 r; /* Red value. */
	b2 g; /* Green value. */
	b2 b; /* Blue value. */
	b2 a; /* Alpha channel value. */
} FFPixel ;

#endif
