#include<iostream>
#include<unordered_map>
using namespace std;

void twoSum(int a[], int size, int target){

    unordered_map<int,int> um;
    
    // O(n)
    for(int i=0;i<size;i++)
        um[a[i]]=i;

    // O(n)
    for(int i=0;i<size;i++)
        if(um.find(target-a[i])!=um.end()){
            cout << i << " " << um[target-a[i]] << endl;
            return;
        }
}

int main(){

    int a[]={11,7,15,2,15};
    int size=sizeof(a)/sizeof(a[0]);
    twoSum(a,size,9);
    return 0;
}
