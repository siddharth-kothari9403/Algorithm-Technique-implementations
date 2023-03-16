//to find the length of the longest increasing subsequence of the array
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> longestIncreasingSubsequence(vector<int> nums){
    int n = nums.size();
    //OPT[i] array contains the most optimal solution that necessarily contains A[i]
    //Hence the answer is max of those values.

    //OPT[i] will be max OPT[j] +1, where j<i and A[j] < A[i], this ensures that we add A[i] to the most beneficial solution to which it can be added
    //best array contains the 'j' value for each i, once we find max OPT value, we can then backtrack to get the elements to add to solution

    vector<int> OPT;
    vector<int> best;
    OPT.resize(n, 1); //each optimum increasing subsequence will atleast have 1 element- itself, hence 1
    best.resize(n, -1); //when we reach -1, we will break the loop in backtracking

    for (int i=0; i<n; i++){
        for (int j=i-1; j>-1; j--){
            if (OPT[j] + 1 > OPT[i] && nums[j] < nums[i]){
                OPT[i] = OPT[j] + 1;
                best[i] = j;
            }
        }
    }

    int max = -1;
    int maxindex = -1;
    for (int i=0; i<n; i++){
        if (max < OPT[i]){
            max = OPT[i];
            maxindex = i;
        }
    }

    cout<<"The max increasing subsequence is of length: "<<max<<endl;
    cout<<"The subsequence is: ";

    vector<int> solution;

    while (maxindex > 0){
        solution.push_back(nums[maxindex]);
        maxindex = best[maxindex];
    }

    reverse(solution.begin(), solution.end());
    return solution;
}

int main(){
    int n; cin>>n;
    vector<int> nums;
    for (int i=0; i<n; i++){
        int k; cin>>k;
        nums.push_back(k);
    }

    printVector(longestIncreasingSubsequence(nums));
    return 0;
}