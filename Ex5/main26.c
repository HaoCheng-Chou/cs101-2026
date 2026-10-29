#include <stdio.h>
int multi(int i, int j){
    if(j==1){
        printf("%d*%d=%d\t",i,j,i*j);
        return 0;
    } else{
        multi(i,j-1);
        printf("%d*%d=%d\t",i,j,i*j);
    }
}
int multiPlus(int i, int j){
    multi(i,j);
    printf("\n");
    if(i!=j) multiPlus(i + 1, j);
}
int main(){
    multiPlus(1,9);
    return 0;
}
