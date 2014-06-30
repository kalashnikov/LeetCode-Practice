#include<stdio.h>
#include<math.h>

// 
// Climbing Stair 
//

long climbStair1(int n){
    int i; 
    long tmp; 
    long pre = 0;
    long cur = 1;
    for(i=1;i<=n;i++){
        tmp = cur;
        cur+= pre;
        pre = tmp;
    }
    return cur; 
}

long climbStair2(int n){
    const double s = sqrt(5.0); // Precision is very important for this formula
    return floor((pow((1+s)/2,n+1)-pow((1-s)/2,n+1))/s+0.5);
}

int main(){
    int i;
    for(i=0;i<100;i++){
        if(climbStair1(i)!=climbStair2(i)){
            printf("====%d====\n",i);
            printf("%ld\n",climbStair1(i));
            printf("%ld\n",climbStair2(i));
            break;
        }
    }
    return 0;
}
