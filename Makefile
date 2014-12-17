aprox_tryg: main.o splines.o points.o aproksymator_trygonometryczny.o
	$(CC) -o aprox_tryg  main.o splines.o points.o aproksymator_trygonometryczny.o -lm

aproksymator_trygonometryczny.o: makespl.h points.h
	$(CC) -c aproksymator_trygonometryczny.c

.PHONY: clean

clean:
	-rm *.o aprox_tryg
