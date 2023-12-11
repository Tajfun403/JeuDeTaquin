#include <stdio.h>
#include <stdlib.h>

double arr[100][100];

//...
/*
int f(){
    for(int i=)

}
*/

int main()
{
    //double arr[100][100];
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen("filename.txt", "r");

    if(fptr == NULL){
        printf("Not able to open the file.");
        return 0;
    }
    //read from file and input into array
    char line[100];
    int r=0;
    while ( fgets( line, 100, fptr ) != NULL  ){

        printf("The line is: %s\n", line);
        //...
        printf("and the values are: ");
        for(int i=0,j=0,k=0;line[i]!=0;++i){
            if(line[i]==';'){
                line[i]=0;
                arr[r][j]=atof(line+k);
                printf("%lf ", arr[r][j]);
                k=i+1;
                j++;
            }
        }
        printf("\n\n");
        r++;
    }


   // printf("%d",f());

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
    printf("\nThe result is: %d and the value in the array is: %lf",res,arr[i][j]);
    // Close the file
    fclose(fptr);

    return 0;
}
