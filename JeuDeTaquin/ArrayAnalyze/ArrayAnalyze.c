#include <stdio.h>
#include <stdlib.h>
#include "ArrayAnalyze.h"

int traverse(char *path,int n,int m){

    // n number of rows, m max number of columns
    // Open a file in read mode
    FILE *fptr = fopen(path, "r");

    if(fptr == NULL){
       //printf("Not able to open the file.");
        return -1;
    }
    /*
    //for small n,m only
    double arr[n][m];
    char line[m];
    */
    double **arr = (double **)malloc((n) * sizeof(double *));

    char *line=malloc(18*m);//sizeof(char) is always 1, and... m is the number of doubles and every double has many digits.. so assuming constant number of digits per double we need to multiply by some constant

    int *endarr=malloc(n*sizeof(int));

    //read from file and input into array

    int r=n;//rows
    endarr[n]=-1;
    while ( fgets( line, 18*m, fptr ) != NULL  ){

        printf("The line is: %s\n", line);
        //...
        printf("and the values are: ");
        r--;
        int j=0,numb=0;
        while(line[j]!=0){
            if(line[j]==';')numb++;
            j++;
        }
        arr[r] = (double *)malloc((numb) * sizeof(double));
        endarr[r]=numb-1;//remember where every row ends
        j=0;
        for(int i=0,k=0;line[i]!=0;++i){
            if(line[i]==';'){
                line[i]=0;
                arr[r][j]=atof(line+k);
                printf("%lf ", arr[r][j]);
                k=i+1;
                j++;
            }
        }
        printf("\n\n");
    }

    int i=0,j=0,res;
    while(1){
         printf("%lf ", arr[i][j]);
        //end of arr
        if(endarr[i+1]<j&&j==endarr[i]){
            res=i+j;
            break;
        }
        //up if arr[i+1] exists and we can't go right or up is greater than right
        else if((endarr[i+1]>=j)&&(j==endarr[i]||arr[i+1][j]>arr[i][j+1])){
            i++;
        }
        //right
        else j++;
    }
    // Close the file
    fclose(fptr);
    // Deallocate memory when done

    for (int i=0;i<n+1;++i){

        free(arr[i]);
    }

    free(arr);

    return res;
}
