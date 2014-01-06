#include "ip2ensign.h"
#include "iptable.inl"
#include "flaglist.inl"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

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

	for ( i=0; i<NUMFLAGS-1; ++i )
		if ( !strcmp( flagcc[ i ], cc ) )
			break;
	int x = i%16;
	int y = i/16;
	*u = ( 0.5f + x ) / 16.0f;
	*v = ( 0.5f + y ) / 16.0f;

	return cc;
}

