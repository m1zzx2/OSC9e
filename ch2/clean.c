
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct birthday {
       int day;
       int month;
       int year;
       char name[]; 
};

int main(int argc, char **argv){

    struct birthday* birthday = malloc(sizeof(birthday));
    char s[] = "123";
    strcpy(birthday->name,s);
    printf("%s \n",birthday->name);
    // birthday->name = "123";

    return 0;
}