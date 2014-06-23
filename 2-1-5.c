#include<stdio.h>
//
// Median of Two Sorted Arrays
//
// Further Reading: 
// 1. http://www.ardendertat.com/2011/10/27/programming-interview-questions-10-kth-largest-element-in-array/
// 2. http://stackoverflow.com/questions/251781/how-to-find-the-kth-largest-element-in-an-unsorted-array-of-length-n-in-on
//

#define min(a,b) ((a)<(b)?(a):(b))

int find_k(int a[], int m, int b[], int n, int k);

int medianOfTwoArray(int a[], int m, int b[], int n){

    int total = m+n;
    if (total<2)
        return find_k(a,m,b,n,(total)/2+1);
    else 
        return find_k(a,m,b,n,total/2);
//        return (find_k(a,m,b,n,total/2)
//                + find_k(a,m,b,n,total/2+1))/2.0;
}

int find_k(int a[], int m, int b[], int n, int k){

    if ( m>n ) return find_k(b,n,a,m,k);
    if ( m==0 ) return b[k-1];
    if ( k==1 ) return min(a[0],b[0]); 

    int ia = min(k/2,m), ib = k-ia;
    if ( a[ia-1]<b[ib-1] )
        return find_k(a+ia, m-ia, b, n, k-ia);
    else if ( a[ia-1] > b[ib-1] )
        return find_k(a, m, b+ib, n-ib, k-ib);
    else 
        return a[ia-1];
}

int main(){

    int a[]={1,3,6,8,45,93,975,9352};
    int sa =sizeof(a)/sizeof(a[0]);
    int b[]={12,54,473,853,868,4737,30000};
    int sb =sizeof(b)/sizeof(b[0]);

    printf("%d\n",medianOfTwoArray(a,sa,b,sb));
    
    return 0;
}
