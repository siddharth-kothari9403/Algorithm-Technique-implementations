#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int l, int r){
    if (l==r) return arr[l];

    int m = (r-l)/2 + l;
    if (arr[m] > arr[m+1]){
        return search(arr, l, m);
    }else{
        return search(arr, m+1, r);
    }
}

int main(){
    vector<int> temp = {3,5,7,9,10,24,15,13,11,7,3};
    cout<<search(temp, 0, temp.size()-1)<<endl;
    return 0;
}