CC = g++

CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
	   -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual        \
	   -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op                 \
         -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192         \
         -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all : standart_compilation.exe

standart_compilation.exe : main.o io.o sort.o
	$(CC) $(CFLAGS) main.o io.o sort.o -o standart_compilation.exe

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp

io.o : io.cpp
	$(CC) $(CFLAGS) -c io.cpp

sort.o : sort.cpp
	$(CC) $(CFLAGS) -c sort.cpp

clean:
	rm *.o standart_compilation.exe
