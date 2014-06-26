#include<stdio.h>
// 
// Find K-th Permutation
//  

void kthPermutation(int n, int k){

    int i;
    int a[n];
    int f[n];

    // Generate Factorial Array
    f[0]=1; // 0!
    while(++i<n)
        f[i]=f[i-1]*i; // i!

    for(i=0;i<n;i++){
        a[i] = k / f[n-1-i];
        k = k % f[n-1-i];
        
        //
        // Debug Print
        // Ref: http://stackoverflow.com/questions/7918806/finding-n-th-permutation-without-computing-others
        //
        //printf("%d | %d / %d => %d\n",i, k, f[n-1-i], a[i]);
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(int argc, char** argv){
    kthPermutation(10, 3628799);
    return 0;
}
