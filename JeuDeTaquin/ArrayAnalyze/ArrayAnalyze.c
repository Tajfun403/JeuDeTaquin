#include <stdio.h>
#include <stdlib.h>
#include "ArrayAnalyze.h"

int traverse(char *path,int n,int m){

    // Open a file in read mode
    FILE *fptr = fopen(path, "r");

    if(fptr == NULL){
       // printf("Not able to open the file.");
        return -1;
    }
    //for small n,m only
    double arr[n][m];
    char line[m];

    //read from file and input into array
    int r=0;
    while ( fgets( line, m, fptr ) != NULL  ){

      ///  printf("The line is: %s\n", line);
        //...
      ///  printf("and the values are: ");
        for(int i=0,j=0,k=0;line[i]!=0;++i){
            if(line[i]==';'){
                line[i]=0;
                arr[r][j]=atof(line+k);
             ///   printf("%lf ", arr[r][j]);
                k=i+1;
                j++;
            }
        }
       /// printf("\n\n");
        r++;
    }

    int i=r-1,j=0,res;
    while(1){
        //end of arr
        if(arr[i-1][j]==0&&arr[i][j+1]==0){
            res=i+j;
            break;
        }
        //up
        else if(arr[i-1][j]>arr[i][j+1]){
            i--;
        }
        //right
        else j++;
        //if arr[i-1][j]==0 but arr[i][j+1]!=0 then arr[i][j+1]>arr[i-1][j] and vice versa
    }
    // Close the file
    fclose(fptr);

    return res;
}
