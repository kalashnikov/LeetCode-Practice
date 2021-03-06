#include<iostream>
#include<unordered_map>
using namespace std;

// 
// Long Sequence in unsorted array
// Use HashTable to search item in O(1) 
//

int longSequence(int a[],int size){

    int max = 1;
    unordered_map<int,int> map;

    // init, O(N)
    for(int i=0;i<size;i++)
        map[a[i]]=1;

    // find, O(N)*O(1)
    for(int i=0;i<size;i++){
        int cnt = 1;
        int nd,ng;
        nd = ng = a[i];
        while(map.find(++ng)!=map.end()) cnt++;
        while(map.find(--nd)!=map.end()) cnt++;
        map[a[i]] = cnt;
        if ( cnt > max ) max = cnt;
    }
    return max;
}

int main(){
    int a[]={100,4,200,1,3,2};
    int size=sizeof(a)/sizeof(a[0]);
    cout << longSequence(a,size) << endl;
    return 0;
}
