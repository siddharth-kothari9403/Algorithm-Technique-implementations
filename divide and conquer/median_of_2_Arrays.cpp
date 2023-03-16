#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

float unionOfTwo(vector<float> arr1, vector<float> arr2){
    if (arr1.size() == 1 && arr2.size() == 1){
        return arr1[0]+(arr2[0]-arr1[0])/2;
    }
    else if (arr1.size() == 2 && arr2.size() == 2){
        return max(arr1[0], arr2[0]) + (min(arr1[1], arr2[1]) - max(arr1[0], arr2[0]))/2;
    }
    
    int n = arr1.size(); //also equal to arr2.size()

    float m1, m2;
    if (n%2 == 0){
        m1 = arr1[n/2 - 1]+(arr1[n/2]-arr1[n/2 - 1])/2;
        m2 = arr2[n/2 - 1]+(arr2[n/2]-arr2[n/2 - 1])/2;
    }else{
        m1 = arr1[n/2];
        m2 = arr2[n/2];
    }

    if (m1 == m2){
        
        return m1;

    }else if (m1 > m2){
        vector<float> left; vector<float> right;
        
        int half_ndx1 = (n-1)/2;
        int half_ndx2 = n/2; //for n = 6, it will be 2, so we will take 0,1,2 index
        //for n = 5, it will be 2, so we take same indexex, this ensures that it is correct

        //if m1 is greater then the greater elems of arr1 cannot be the medians, hence we take the lower elements of them
        for (int i=0; i<= half_ndx1; i++){
            left.push_back(arr1[i]);
        }

        for (int i= half_ndx2; i<n; i++){
            right.push_back(arr2[i]);
        }

        //larger elements of arr2 are taken
        return unionOfTwo(left, right);
    }else{
        vector<float> left; vector<float> right;
        
        int half_ndx1 = (n-1)/2;
        int half_ndx2 = n/2; //for n = 6, it will be 2, so we will take 0,1,2 index
        //for n = 5, it will be 2, so we take same indexex, this ensures that it is correct

        //if m2 is greater then the greater elems of arr2 cannot be the medians, hence we take the lower elements of them
        for (int i=0; i<= half_ndx1; i++){
            left.push_back(arr2[i]);
        }

        for (int i= half_ndx2; i<n; i++){
            right.push_back(arr1[i]);
        }

        //larger elements of arr1 are taken
        return unionOfTwo(left, right);
    }
    
}

int main(){
    int n; cin>>n;

    vector<float> arr1, arr2;

    for (int i=0; i<n; i++){
        int k; cin>>k;
        arr1.push_back(k);
    }

    for (int j=0; j<n; j++){
        int k; cin>>k;
        arr2.push_back(k);
    }

    cout<<unionOfTwo(arr1, arr2)<<endl;
}