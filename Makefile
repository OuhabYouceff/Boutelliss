minimap:main.o minimap.o
	gcc minimap.o main.o -o prog -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c 
minimap.o:minimap.c
	gcc -c minimap.c 
