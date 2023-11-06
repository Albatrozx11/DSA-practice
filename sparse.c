#include <stdio.h>
void main(){
    int r,c,i,j;
    
    //INPUT N.O OF ROWS AND COLUMNS
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&r,&c);
    int a[r][c];
    //INPUT MATRIX
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter element A[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
    	}
    }
    
    
    //PRINT INPUT MATRIX
    printf("MAIN MATRIX:\n");
    for(i=0;i<r;i++){
    	for(j=0;j<c;j++){
        	printf("%d\t",a[i][j]);
    	}
    	printf("\n");
    }
    
    
    //SPARSE MATRIX
    int k=1;
    int tuple[100][3];
    tuple[0][0]=r;
    tuple[0][1]=c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]!=0){
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=a[i][j];
                k++;
            }
        }
		
    }
    tuple[0][2]=k-1;
    

	//PRINT SPARSE MATRIX
	printf("SPARSE MATRIX:\n");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",tuple[i][j]);
        }
        printf("\n");
    }
}