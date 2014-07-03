#include<stdio.h>
// 
// Single Num II
// Every number appears three times, except one. 
//

// 
// Solution & Explantation
// Ref: http://stackoverflow.com/questions/21297067/single-number-ii-from-leetcode 
//
// There are three status: 0, 1, 2
// So cannot use single bit, have to use high/low bit to present them as: 00, 01, 10
//
// Here's the logic:
//
// high/low 00 01 10
// x=0      00 01 10
// x=1      01 10 00
//
// high is a function of both high and low.
// If low == 1 then high = x, else high = high & ~x
//
// We have : high = low & x | high & ~x
// This equals to your: "int two_ = A[i] & one | ~A[i] & two;"
//
// Similarly we have low as the function of both high and low:
// If high == 1 then low = ~x, else low = low XOR x
//
int singleNum(int a[], int s){
    int i;
    int one=0,two=0,three=0;
    for(i=0;i<s;i++){
        int one_ = (one ^ a[i]) & ~two;
        int two_ = (a[i] & one) | (~a[i] & two);
        one = one_;
        two = two_;
    }
    return one;
}

int main(){
    //int a[]={1,2,2,2,8,1,7,7,1,7};
    int a[]={1, 1, 20, 3, 3, 20, 20, 15, 4, 1, 4, 3, 4};
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",singleNum(a,size));
    return 0;
}
