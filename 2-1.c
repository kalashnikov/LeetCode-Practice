//
// Remove duplicated item in Sorted Array
// 2014.6.21
//
#include<stdio.h>
int main(){

    int i,j;
    int a[]={0,1,1,1,2,2,2,3,3,3,4,4,4,4,4,5,5,6,7,7,8,9,10,10,10};
    int size=sizeof(a)/sizeof(a[0]);

    // printf("%d\n",size);
    for(i=0,j=1;j<size;){
        //printf("%d %d\n",i,j);
        int b=0;
        while(a[j]==a[i] && j<size) {
            j++;b=1;
        }
        if (b==1) {
            a[++i]=a[j];
        } else {
            ++i;++j;
        }
    }
    printf("%d\n",i);
    //for(j=0;j<i;j++)
    //    printf("%d ",a[j]);
    //printf("\n");
    return 0;
}
