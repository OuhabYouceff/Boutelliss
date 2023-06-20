prog:image.o start.o coop.o main.o settings.o credit.o player.o player2.o play.o vie_score.o special.o
	gcc image.o start.o coop.o main.o settings.o credit.o player.o player2.o play.o vie_score.o special.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer 
main.o:main.c 
	gcc -c main.c 
image.o:image.c 
	gcc -c image.c
settings.o:settings.c
	gcc -c settings.c
start.o:start.c
	gcc -c start.c
coop.o:coop.c
	gcc -c coop.c
credit.o:credit.c
	gcc -c credit.c
player.o:player.c
	gcc -c player.c
player2.o:player2.c
	gcc -c player2.c
play.o:play.c
	gcc -c play.c
vie_score.o:vie_score.c
	gcc -c vie_score.c
special.o:special.c
	gcc -c special.c
