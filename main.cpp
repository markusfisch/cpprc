/*
 *   O         ,-
 *  ° o    . -´  '     ,-
 *   °  .´        ` . ´,´
 *     ( °   ))     . (
 *      `-;_    . -´ `.`.
 *          `._'       ´
 *
 * Copyright (c) 2006 Markus Fisch <mf@markusfisch.de>
 *
 * Licensed under the MIT license:
 * http://www.opensource.org/licenses/mit-license.php
 */
#include "Compiler.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char **argv )
{
	cpprc::Compiler c;

	try
	{
		for( const char *binary = *argv; --argc; )
			if( **(++argv) != '-' )
				c.add( *argv );
			else
				switch( *(*argv+1) )
				{
					default:
						cerr << "unknown option '"
							<< *(*argv+1)
							<< "'"
							<< endl;
						break;
					case 'h':
					case '?':
						cout << "usage: " << binary << " [hviof] FILE..."
							<< endl
							<< "  -h         "
							<< "print this help and exit"
							<< endl
							<< "  -v         "
							<< "print version and exit"
							<< endl
							<< "  -i FILE    "
							<< "read input files from this file"
							<< endl
							<< "  -o FILE    "
							<< "use this filename for output (.cpp/.h)"
								<< ", default is \"Resources\""
							<< endl
							<< "  -f FORMAT  "
							<< "set output format: STL (default) or wxWidgets"
							<< endl;
						return 0;
					case 'v':
						cout << "C++ Resource Compiler 0.4.2 "
							<< "(c) 2007 Markus Fisch <mf@markusfisch.de>"
							<< endl;
						return 0;
					case 'i':
						if( !--argc )
							throw "missing argument for -i option !";
						else
						{
							ifstream in( *++argv );

							if( !in ||
								!in.good() )
								throw "can't open input file !";

							for( string s; getline( in, s ); )
							{
								// don't use lines that start by #
								string::size_type p =
									s.find_first_not_of( " \t" );

								if( p == string::npos ||
									s[p] == '#' )
									continue;

								c.add( s.c_str() );
							}

							in.close();
						}
						break;
					case 'o':
						if( !--argc )
							throw "missing argument for -o option !";
						c.setFileName( *++argv );
						break;
					case 'f':
						if( !--argc )
							throw "missing argument for -f option !";
						else
						{
							string f( *++argv );

							if( !f.compare( "wxWidgets" ) )
								c.setFormat( cpprc::Compiler::wxWidgets );
							else if( !f.compare( "STL" ) )
								c.setFormat( cpprc::Compiler::STL );
							else
								throw "unknown output format !";
						}
						break;
				}
	}
	catch( const char *e )
	{
		cerr << "error: " << e << endl;
	}

	return 0;
}
