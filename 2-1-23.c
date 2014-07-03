#include<stdio.h>

// 
// Single Num
// Every number appears twice, except one. 
// Use XOR to eliminate number appears twice. 
//

int singleNum(int a[], int s){
    int i,x=0;
    for(i=0;i<s;i++)
        x^=a[i];
    return x;
}

int main(){
    int a[]={1,2,2,3,5,3,1,7,7,5,9};
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",singleNum(a,size));
    return 0;
}
