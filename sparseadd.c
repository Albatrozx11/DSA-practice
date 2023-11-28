#include <stdio.h>

int create_tuple(int arr[],int r,int c){
    int r,c,i,j,k;
    int tuple[r][c];
    tuple[0][0]=r;
    tuple[0][1]=c;
    k=1;
    for(i=0;i<r;i++){
        for(j=0;j<3;j++){
            if(arr[i][j]!=0){
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=arr[i][j];
                k++;
            }
        }
    }
    tuple[0][2]=k-1;
    return tuple;


}


void main(){
    int r1,c1,r2,c2 ,i,j,atuple,btuple;
    printf("Enter n.o of rows of A:");
    scanf("%d",&r1);
    printf("Enter n.o of columns of A:");
    scanf("%d",&c1);
    printf("Enter n.o of rows of B:");
    scanf("%d",&r2);
    printf("Enter n.o of columns of B:");
    scanf("%d",&c2);
    int A[r1][c1],B[r2][c2];
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("Enter element A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("Enter element B[%d][%d]: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    atuple=create_tuple(A,r1,c1);
    btuple=create_tuple(B,r2,c2);
}