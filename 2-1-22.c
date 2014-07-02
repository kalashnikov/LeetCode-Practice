#include<stdio.h>
#define max(X,Y) ((X) > (Y) ? (X) : (Y))

int candy(int a[], int s){
    if(s==0) return 0;
    if(s==1) return 1;
    
    int i,j,p;
    int inc;
    int total = s;
    int b[s]; 
    for(i=0;i<s;i++) b[i]=0;
    
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    printf("\n");
        
    for(i=1,inc=1;i<s;i++){
       if(a[i]>a[i-1])
            b[i] = max(inc++,b[i]);
       else          
            inc=1;
    }
    
    for(i=s-2,inc=1;i>=0;i--){
       if(a[i]>a[i+1]) 
            b[i] = max(inc++,b[i]);
       else          
            inc=1;
    }

    for(i=0;i<s;i++){
        printf("%d ",b[i]);
        total+=b[i];
    }
    printf("\n");

    return total;
}

int main(){
    //int a[]={2,3,5,4,1,8,4};
    int a[]={9,5,4,2,1,7,6};
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",candy(a,size));
    return 0;
}
