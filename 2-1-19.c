#include<stdio.h>
#include<stdlib.h>
// 
// Gray Code
//

int b2g(int n){
    return n^(n>>1);
}

void grayCode(int n){
    if(n==0) return;

    int i;
    int s = 1<<n;
    for(i=0;i<s;i++)
        printf("%d\n",b2g(i));
}

int main(){
    grayCode(3);
    return 0;
}
