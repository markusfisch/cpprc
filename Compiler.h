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
#ifndef cpprc_Compiler_h
#define cpprc_Compiler_h

#include <string>
#include <sstream>

namespace cpprc
{
	/**
	 * C++ resource compiler
	 *
	 * @author mf@markusfisch.de
	 */
	class Compiler
	{
		public:
			enum Format
			{
				STL,
				wxWidgets
			};

			Compiler() :
				offset( 0 ),
				fileName( "Resource" ),
				format( STL ) {}
			virtual ~Compiler();
			inline void setFileName( const char *f ) { fileName = f; flush(); }
			inline const std::string &getFileName() const { return fileName; }
			inline void setFormat( Format f ) { format = f; }
			inline const Format &getFormat() const { return format; }
			virtual void add( const char * );

		protected:
			std::ostringstream data;
			std::ostringstream index;
			int offset;

			virtual int hash( const char * ) const;
			virtual void flush();

		private:
			enum
			{
				HashMax = 600011
			};

			std::string fileName;
			Format format;
	};
}

#endif
