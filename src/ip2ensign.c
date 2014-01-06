#include "ip2ensign.h"
#include "iptable.inl"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

const char* ip2ensign( unsigned int addr, float* u, float* v )
{
	int i=0;
	for ( ; i<IPTABLESZ; ++i )
		if ( iptable[i] > addr )
			break;
	int nr=i-1;
	static char cc[3];
	cc[0] = cctable[nr*2+0];
	cc[1] = cctable[nr*2+1];
	cc[2] = 0;
	return cc;
}

