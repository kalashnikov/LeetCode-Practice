#include<stdio.h>
// 
// Sum of Three are Zero
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

    int bidx = 0;
    int b[size][3];

    // Reset triplet table
    for(idxa=0;idxa<size;idxa++){
        b[idxa][0]=0;
        b[idxa][1]=0;
        b[idxa][2]=0;
    }

    // O(nlogn)
    qsort(a,0,size-1);

    // O(n^2)
    for(idxa=0;idxa<size-1;idxa++){
        idxb=idxa+1;
        idxc=size-1;
        while(idxb<idxc){
            if(a[idxa]+a[idxb]+a[idxc]<target){
                idxb++;
            } else if(a[idxa]+a[idxb]+a[idxc]>target){
                idxc--;
            } else {
                int j=0;
                int dup=0;
                for(j=0;j<size;j++){
                    if(a[idxa]==b[j][0] && 
                            a[idxb]==b[j][1] && 
                            a[idxc]==b[j][2] ){
                        dup=1;
                        break;
                    } 
                }
                if (dup==0){
                    b[bidx][0]=a[idxa];
                    b[bidx][1]=a[idxb];
                    b[bidx][2]=a[idxc];
                    printf("%d %d %d\n",a[idxa],a[idxb],a[idxc]);
                    bidx++;
                }
                idxb++;idxc--;
            }
        }
    }
}

int main(){
    int a[]={-1,0,1,2,5,-1,-4};
    int size=sizeof(a)/sizeof(a[0]);
    threeSum(a,size,0);
    return 0;
}
