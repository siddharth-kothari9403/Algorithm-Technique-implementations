//program to sort k given sorted arrays
//using divide and conquer approach in O(nklogk) time

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//function to merge 2 sorted arrays
vector<int> merge2(vector<int> a1, vector<int> a2){
    int i=0; int j=0;
    vector<int> res;
    while (i< a1.size() && j<a2.size()){
        if(a1[i] > a2[j]){
            res.push_back(a2[j]);
            j++;
        }else{
            res.push_back(a1[i]);
            i++;
        }
    }

    while (i< a1.size()){
        res.push_back(a1[i]);
        i++;
    }

    while (j< a2.size()){
        res.push_back(a2[j]);
        j++;
    }

    return res;
}

//general function for k arrays
vector<int> merge(vector<vector<int>> arr){
    if (arr.size() == 1){
        return arr[0];
    }

    int m=arr.size()/2;
    vector<vector<int>> left(&arr[0], &arr[m]);
    // cout<<left.size()<<endl;
    vector<vector<int>> right(&arr[m], &arr[arr.size()]);
    // cout<<right.size()<<endl;
    
    vector<int> a1 = merge(left);
    // printVector(a1);
    vector<int> a2 = merge(right);
    // printVector(a2);

    return merge2(a1, a2);
}

int main(){
    vector<vector<int>> temp = {{1,5,7,10,15},{3,7,11,24,30},{4,19,21,22,50}};
    printVector(merge(temp));
    return 0;
}