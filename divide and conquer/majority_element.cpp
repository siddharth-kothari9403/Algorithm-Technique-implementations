//finding majority element using divide and conquer approach
//O(nlogn) algorithm

#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int elem, int l, int r){
    int count = 0;
    for (int i=l; i<=r; i++){
        if (arr[i] == elem){
            count++;
        }
    }

    return count;
}

int majority(vector<int> arr, int l, int r){
    // cout<<l<<" "<<r<<endl;
    if (l==r){
        // cout<<arr[l]<<endl;
        return arr[l];
    } 

    int m= (r-l)/2 + l;
    int leftmaj = majority(arr, l, m);
    int rightmaj = majority(arr, m+1, r);

    if (leftmaj == rightmaj) return leftmaj;
    else{
        int lcount = count(arr, leftmaj, l, r);
        int rcount = count(arr, rightmaj, l, r);

        if (lcount > (r-l+1)/2){
            return leftmaj;
        }

        if (rcount > (r-l+1)/2){
            return rightmaj;
        }

        return -1;
    }
}

int main(){
    vector<int> arr1 = {3,3,3,5,6};
    vector<int> arr2 = {2,4,5,6,2};
    vector<int> arr3 = {2,2,1,3,5};
    cout<<majority(arr1, 0, 4)<<" "<<majority(arr2, 0, 4)<<" "<<majority(arr3, 0, 4)<<endl; 
    return 0;
}