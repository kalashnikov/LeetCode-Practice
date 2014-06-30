#include<stdio.h>
//
// Trapping Rain Water
//
// Description: 
//     Given n non-negative integers representing an elevation map 
//     where the width of each bar is 1, 
//     compute how much water it is able to trap after raining.
//

int trap_rain_water(int a[], int size){
    int i;
    int max = 0;
    int peak,water = 0;

    // Use max-height pillar to divide into left and right
    for(i=0;i<size;i++) 
        if(a[max]<a[i]) 
            max = i;

    for(i=0,peak=0;i<max;i++)
        if(a[i]>peak)
            peak = a[i];
        else
            water+=peak-a[i];

    for(i=size-1,peak=0;i>max;i--)
        if(a[i]>peak)
            peak = a[i];
        else
            water+=peak-a[i];

    return water;
}

int main(){
    int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int size=sizeof(a)/sizeof(a[0]);
    printf("%d\n",trap_rain_water(a,size));
    return 0;
}
