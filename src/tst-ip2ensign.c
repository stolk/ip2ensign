#include "ip2ensign.h"

#include <stdio.h>


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
		float u=0, v=0;
		const char* cc = host2ensign( host, &u, &v );
		printf( "%s is in %s and has UV=%f,%f\n", host, cc, u, v );
	}
	return 0;
}

