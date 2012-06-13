#include <iostream>
#include <fstream>
#include <string>

#include "Resource.h"

using namespace std;

int main( int argc, char **argv )
{
	try
	{
		if( Resource::getString( "Makefile" ).compare( 
			Resource::getString( ":Makefile" ) ) )
			throw "Makefile corrupted !";

		Resource r( ":cpprc" );

		if( !r.good() )
			throw "can't open resource !";

		ifstream fin( "cpprc", ios::binary );

		if( !fin )
			throw "can't open test file !";

		istream &rin = *r.stream();

		for( ; !rin.eof() && !fin.eof(); )
			if( rin.get() != fin.get() )
				throw "resource corrupted !";

		if( !rin.eof() || !fin.eof() )
			throw "resource length doesn't match !";

		cout << "resources are valid !" << endl;
	}
	catch( const char *e )
	{
		cerr << e << endl;

		return -1;
	}

	return 0;
}
