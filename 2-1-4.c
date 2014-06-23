#include<stdio.h>

// 
// Based on 2-1-3, not big change
//
int search(int A[], int n, int target) {
    int first = 0, last = n; // Choose last to n
    while (first != last) {
        const int mid = (first + last) / 2;
        if (A[mid] == target)
            return mid;

        // Corner case are
        // first=3,mid=first,last=first
        // 1) a[first]=4, a[last]=6, target=6
        // 2) a[first]=7, a[last]=1, target=1
        //
        if (A[first] < A[mid]) {
            if (A[first] <= target && target < A[mid])
                last = mid;
            else
                first = mid + 1; //Case1
        } else if (A[first] > A[mid]){
            if (A[mid] < target && target <= A[last-1])
                first = mid + 1; //Case2
            else
                last = mid;
        } else // Increment for duplicate but not target element
            first++;
    }
    return -1;
}

int main(){
    //int a[]={7,9,1,1,2,2,3,4,5,6};
    int a[]={4,4,5,5,5,6,7,9,1,2,3};
    int size=sizeof(a)/sizeof(a[0]);
    
    int i;
    for(i=0;i<15;i++)
        printf("%d => %d\n",i, search(a,size,i));

    return 0;
}
