#include <stdio.h>
#include "ArrayAnalyze.h"

int main(){
   // FILE *fptr;// = fopen("filename.txt", "r");
    char* path="filename.txt";
    int n=3,m=4;
    printf("%d",traverse(path,n,m));

    return 0;
}
