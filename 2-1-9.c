#include<stdio.h>
// 
// Sum of Three Cloest to Target 
// 1.) non-descending order of answer
// 2.) no duplicate triplets
//  

int partition(int a[],int lo,int hi){
    int t;
    int pivot = a[(lo+hi)/2];
    while(lo<=hi){
        while(a[lo]<pivot) lo++;
        while(pivot<a[hi]) hi--;
        if(lo<=hi){
            t=a[lo];
            a[lo]=a[hi];
            a[hi]=t;
            lo++;hi--;
        }
    }
    return lo;
}

void qsort(int a[],int lo, int hi){
    int index=partition(a,lo,hi);
    if(lo<index-1)
        qsort(a,lo,index-1);
    if(index<hi)
        qsort(a,index,hi);
}

void threeSum(int a[],int size, int target){
    int idxa = 0;
    int idxb = 0;
    int idxc = 0;

    // O(nlogn)
    qsort(a,0,size-1);

    int sum = 0;
    int dbs = 3*target;
    int b[3];
    b[0]=b[1]=b[2]=0;

    // O(n^2)
    for(idxa=0;idxa<size-1;idxa++){
        idxb=idxa+1;
        idxc=size-1;
        while(idxb<idxc){
            if(a[idxa]+a[idxb]+a[idxc]<target){
                if(target-a[idxa]-a[idxb]-a[idxc]<dbs){
                    b[0]=a[idxa];
                    b[1]=a[idxb];
                    b[2]=a[idxc];
                    dbs = target-a[idxa]-a[idxb]-a[idxc];
                    sum = a[idxa]+a[idxb]+a[idxc];
                }
                idxb++;
            } else if(a[idxa]+a[idxb]+a[idxc]>target){
                if(a[idxa]+a[idxb]+a[idxc]-target<dbs){
                    b[0]=a[idxa];
                    b[1]=a[idxb];
                    b[2]=a[idxc];
                    dbs = a[idxa]+a[idxb]+a[idxc]-target;
                    sum = a[idxa]+a[idxb]+a[idxc];
                }
                idxc--;
            } else {
                printf("0 | %d %d %d\n",a[idxa],a[idxb],a[idxc]);
                break;
            }
        }
    }

    printf("%d | %d %d %d\n",sum,b[0],b[1],b[2]);
}

int main(){
    int a[]={-1,1,2,-4};
    int size=sizeof(a)/sizeof(a[0]);
    threeSum(a,size,1);
    return 0;
}
