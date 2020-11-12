#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <omp.h>

#define _GNU_SOURCE

#include <sched.h>

#define BUFFER_SIZE 1000

int indexOf(FILE *fptr, const char *word, int *line, int *col);
int main(){
#pragma omp parallel

{

#pragma omp sections nowait

{

#pragma omp section

{

FILE *fptr;

char

path[]="/home/sruti/Desktop/last.txt";

fptr = fopen(path, "r");

char word1[]="food";

int line1, col1;

indexOf(fptr, word1, &line1, &col1);

if (line1 != -1)

printf("'%s' FOUND AT LINE : %d, col: %d\n",

word1, line1 + 1, col1 + 1);

else

printf("'%s' DOES NOT EXIST.", word1);

}

#pragma omp section

{

FILE *fptr;

char

path[]="/home/sruti/Desktop/last.txt";

fptr = fopen(path, "r");

char word[]="ANU";

int line, col;

indexOf(fptr, word, &line, &col);

if (line != -1)

printf("'%s' FOUND AT  LINE: %d, col: %d\n",

word, line + 1, col + 1);

else

printf("'%s' DOES NOT EXIST.", word);

}

#pragma omp section

{

FILE *fptr;

char

path[]="/home/sruti/Desktop/last.txt";

fptr = fopen(path, "r");

char word[]="love";

int line, col;

indexOf(fptr, word, &line, &col);

if (line != -1)

printf("'%s' FOUND AT LINE: %d, col: %d\n",

word, line + 1, col + 1);

else

printf("'%s' DOES NOT EXIST.", word);

}

#pragma omp section

{

FILE *fptr;

char

path[]="/home/sruti/Desktop/last.txt";

fptr = fopen(path, "r");

char word[]="name";

int line, col;

indexOf(fptr, word, &line, &col);

if (line != -1)

printf("'%s' FOUND AT LINE: %d, col: %d\n",

word, line + 1, col + 1);

else

printf("'%s' DOES NOT EXIST.", word);

}

}

}

return 0;

}

int indexOf(FILE *fptr, const char *word, int *line, int *col){

char str[BUFFER_SIZE];

char *pos;

*line = -1;

*col = -1;

while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)

{

*line += 1;

pos = strstr(str, word);

if (pos != NULL)

{

*col = (pos - str);

break;

}

}

}

