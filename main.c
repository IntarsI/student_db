#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"

#define MAX_STUDENTS	10

void data_input(int count, struct student *s);
void data_output(int count, struct student *s);
int data_save(int count, struct student *s, const char *file);
struct student * data_read(const char *file, int *count);

int main() {
    int c = 0;
    int yn = 0;
    char *file = "data.bin";
    struct student *s;
    struct student *data;
    int  err = 0;

    printf("Vai jus velaties redzet esoso studentu datubazi(1/0)?\n");
    scanf("%d", &yn);
    if(yn==1){
	printf("Lasa  %s\n", file);
        data = data_read(file, &c);
	    if(!data)
		printf("Kluda lasot datubazi: %m\n");
	    else
		data_output(c ,data);
	return 0;
    }

    printf("Ievadiet studentu skaitu:\n");
    scanf("%d",&c);

    s = (struct student *)malloc(sizeof(struct student)*c);

    data_input(c,s);
    data_output(c,s);

    printf("Vai Jus velaties saglabat datus(1/0)?\n");
     err = scanf(" %d",&yn);
    if (yn==1){
	printf("Dati tiek saglabati %s...\n", file);
	data_save(c,s,file);
    }
    free(s);
    return 0;
}



