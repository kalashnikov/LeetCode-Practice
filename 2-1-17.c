#include <stdio.h>
#include <stdlib.h>
// 
// Plus one
//

// Change the address, need return new address 
int *plusOne(int *a,int* size){

    int i,carry;

    for(i=0;i<*size;i++)
        printf("%d",*(a+i));
    printf("\n");

    for(i=*size-1,carry=1;i!=0;i--){
        if(*(a+i)==9 && carry==1)
            *(a+i)=0;
        else { 
            *(a+i)+=1;
            carry=0;
            break;
        }
    }

    if(carry==1){
        free(a);
        a = malloc(sizeof(int)*(++*size));
        *(a+i)=1;
        for(i=1;i<*size;i++) *(a+i)=0;
    }

    for(i=0;i<*size;i++)
        printf("%d",*(a+i));
    printf("\n");
    return a;
}

int main(){
    int i;
    int size=4;
    int *a = malloc(size*sizeof(int)); 
    for(i=0;i<size;i++) *(a+i)=9;
    a = plusOne(a,&size);
    a = plusOne(a,&size);
    a = plusOne(a,&size);
    a = plusOne(a,&size);
    return 0;
}
