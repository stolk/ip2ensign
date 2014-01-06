#include "ip2ensign.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <assert.h>


int main( int argc, char* argv[] )
{
	const char* tests[5]=
	{
		"www.stolk.org",
		"www.rogers.ca",
		"www.ferrari.it",
		"www.shell.com",
		"www.bbc.co.uk",
	};

	int i;
	for ( i=0; i<5; ++i )
	{
		const char* host = tests[ i ];
		struct hostent *he = gethostbyname( host );
	        if ( !he ) perror( "gethostbyname" );
		assert( he );
		struct in_addr ip_addr = *(struct in_addr *)(he->h_addr);

		unsigned long a = ntohl( ip_addr.s_addr );
		float u,v;
		const char* cc = ip2ensign( a, &u, &v );
		printf( "%s is in %s and has UV=%f,%f\n", host, cc, u, v );
	}
	return 0;
}

