//
// Remove duplicated item in Sorted Array
// Allow twice
// 2014.6.21
//
#include<stdio.h>

// @author hex108 (https://github.com/hex108)
// 
// Comment: Very interesting!!! 
//          Check 'occur' location
//          Need start in 'occur' to take care the last element
// 
int removeDuplicates(int A[], int n, int occur) {
    if (n <= occur) return n;
    int index = occur;
    for (int i = occur; i < n; i++){
        if (A[i] != A[index - occur])
            A[index++] = A[i];
    }
    return index;
}
int main(){

    int i,j;
    //int a[]={0,0,1,1,1,2,2,2,3,3,3,4,4,4,4,4,5,5,6,7,7,8,9,10,10,10};
    //int a[]={0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,4,4,5,5,6,7,7,8,9,10,10,10};
    int a[]={0,0,0,0,1,1,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,6,7,7,8,9,10};
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",size);
    int n_size=removeDuplicates(a,size,3);
    printf("%d\n",n_size);
    for(i=0;i<n_size;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
