#include<stdio.h>

void nextPermut(int a[],int size){
    if(size<2) return;
    int i,idx1,idx2;

    // Find Partition Num
    for(i=size-1;i!=0;i--)
        if(a[i-1]<a[i]){
            idx1=i-1;
            break;
        }

    if(i==0){
        idx1=0;
        idx2=size-1;
        while(idx1<=idx2){
            i=a[idx1];
            a[idx1]=a[idx2];
            a[idx2]=i;
            idx1++;idx2--;
        }
    } else {

        // Find Swap Num
        for(i=size-1;i!=0;i--)
            if(a[i]>a[idx1]){
                idx2=i;
                break;
            }

        // swap
        i=a[idx1];a[idx1]=a[idx2];a[idx2]=i;

        // Sort in Reversed Order
        idx1+=1;
        idx2=size-1;
        while(idx1<=idx2){
            i=a[idx1];
            a[idx1]=a[idx2];
            a[idx2]=i;
            idx1++;idx2--;
        }
    }
}

int main(){
    int i;
    int a[]={6,8,7,4,3,2};
    //int a[]={8,7,4,3,2}; //=> Reverse Order only
    int size=sizeof(a)/sizeof(a[0]);
    nextPermut(a,size);
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
