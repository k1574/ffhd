#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arg.h"
#include "config.h"
#include "ffhd.h"

char *argv0;

void
usage(void)
{
	fprintf(stderr, "Usage: %s [-w width] [-h height]\n", argv0);
	exit(1);
}

void
main(int argc, char *argv[])
{
	FarbfeldHeader ffhd;
	b4 w, h;
	argv0 = argv[0] ;
	w = STD_WIDTH ;
	h = STD_HEIGHT ;
	ARGBEGIN {
	case 'w' :
		w = atoi(EARGF(usage())) ;
	break;
	case 'h' :
		h = atoi(EARGF(usage())) ;
	break;
	default:
		usage();
	} ARGEND ;
	memcpy(ffhd.mval, FarbfeldMagicValue, sizeof(ffhd.mval));
	ffhd.w = w ;
	ffhd.h = h ;
	fwrite(&ffhd, sizeof(ffhd), 1, stdout);
	exit(0);
}
