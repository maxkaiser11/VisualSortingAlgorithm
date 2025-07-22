all:
	 g++ -std=c++20 \
	     -Isrc/include \
	     sort.cpp \
	     -Lsrc/lib \
	     -lmingw32 -lSDL2main -lSDL2 \
	     -mwindows \
	     -o main.exe
