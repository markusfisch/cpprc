cpprc
=====

cpprc generates a C++ source file (along with the corresponding header
file) that embeds any given data file and provides a Resource class which
gives access to this data. The Resource class can be created in two flavours:
one using STL streams, the other is using WxWidgets streams.

If you know "qtrc" of the famous QT toolkit, then you know what this tool
is doing too.

Makefile Integration
--------------------

If you are using Makefiles and (at least) a nix-like environment and have
your resources in a subdirectory called say "data", you can do something
like this in your Makefile:

	all:	resources $(PROGRAM)

	resources:
		if ! [ -f Resources.cpp ] || \
			[ "`find data/ -newer Resources.cpp`" ]; then \
			cpprc -f wxWidgets -o Resources `find data/ -type f`; \
		fi
