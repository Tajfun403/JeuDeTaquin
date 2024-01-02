#include <stdio.h>
#include "ArrayAnalyze.h"

int main(){
   // FILE *fptr;// = fopen("filename.txt", "r");
    char* path="filename.txt";
    int n=100,m=100;
    printf("%d",traverse(path,n,m));

    return 0;
}
