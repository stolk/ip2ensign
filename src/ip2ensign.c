#include "ip2ensign.h"
#include "iptable.inl"
#include "flaglist.inl"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


// Convert a 2 character country code to an entry in the flag texture atlas.
// Returns non zero if cc was not found, and jolly rogers flag is used as placeholder.
int cc2ensign( const char* cc, float* u, float* v )
{
	int i;
	for ( i=0; i<NUMFLAGS-1; ++i )
		if ( !strcmp( flagcc[ i ], cc ) )
			break;
	int x = i%16;
	int y = i/16;
	*u =     x  / 16.0f + 0.5f/512;
	*v = (15-y) / 16.0f + 0.5f/512;
	return i==(NUMFLAGS-1);
}


// Convert arbitrary IP nr to an entry in the flag texture atlas.
// Returns the two character country code for the IP nr.
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
	const int substituted = cc2ensign( cc, u, v );
	(void) substituted;
	return cc;
}


// Converts a hostname to an entry in the flag texture atlas.
// Returns the two character country code for the host.
const char* host2ensign( const char* host, float* u, float* v )
{
	struct hostent *he = gethostbyname( host );
	if ( !he ) perror( "gethostbyname" );
	assert( he );
	struct in_addr ip_addr = *(struct in_addr *)(he->h_addr_list[0]);
	unsigned long a = ntohl( ip_addr.s_addr );
	return ip2ensign( a, u, v );
}

