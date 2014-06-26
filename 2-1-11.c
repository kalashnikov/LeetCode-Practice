#include<stdio.h>
// 
// Remove Element in the Array
// Return Length, no preserve order.
//

int removeEle(int a[],int size, int elm){
    int i,index=0;
    for(i=0;i<size;i++)
        if(a[i]!=elm)
            a[index++]=a[i];
    return index;
}

int main(){
    int i;
    int a[]={1,1,2,3,5,6,7,5,8,9,5,5,5};
    int size=sizeof(a)/sizeof(a[0]);
    size=removeEle(a,size,5);
    printf("%d\n",size);
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
