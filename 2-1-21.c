#include<stdio.h>
//
// Gas Station
//

int canComplete(int gas[], int cost[], int size){
    int i, j = -1;
    int total = 0;
    int sum   = 0;
    for(i=0;i<size;i++){
        sum   += gas[i]-cost[i];
        total += gas[i]-cost[i];
        if(sum<0){
            j  =i;
            sum=0;
        }
    }
    return (total>=0)?(j+1):-1;
}

int main(){
    int g[]={4,3,2,1};
    int c[]={2,2,1,1};
    int size=sizeof(g)/sizeof(g[0]);
    printf("%d\n",canComplete(g,c,size));
    return 0;
}
