#include <stdio.h>
int hanoi(int n, char A, char B,char C){
    if(n==1){
        printf("%c->%c\n",A,C);
        return 0;
    }
    hanoi(n-1,A,C,B);
    printf("%c->%c\n",A,C);
    hanoi(n-1,B,A,C);
}
int main(){
    int n=3;
    if(n>0)hanoi(n,'A','B','C');
    return 0;
}
