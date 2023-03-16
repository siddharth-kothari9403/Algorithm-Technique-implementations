#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> optimumSchedule(vector<int> low, vector<int> high){
    int n=low.size();

    vector<int> OPT;
    vector<int> best;
    //OPT[0] = 0, OPT[1] = min(l1, h1) -> trivially true
    //OPT[i] = min(OPT[i-1] + li, OPT[i-2] + hi) -> recurrence equation
    //for each week i, we choose either li or hi, depending on which is better. If we choose hi, then we should not have anything in week i-1, hence OPT[i-2]
    //best serves the same purpose -> backtracking

    OPT.resize(n+1, 0);
    best.resize(n+1, 0);
    OPT[0] = 0;
    if (low[0] < high[0]){
        OPT[1] = high[0];
        best[1] = 1;
    }else{
        OPT[1] = low[0];
        best[1] = 0;
    }

    for (int i=2; i<=n; i++){
        //i-1 die to 0 based indexing
        if (OPT[i-1] + low[i-1] < OPT[i-2] + high[i-1]){
            OPT[i] = OPT[i-2] + high[i-1];
            best[i] = 1;
        }else{
            OPT[i] = OPT[i-1] + low[i-1];
            best[i] = 0;
        }
    }

    // printVector(OPT);

    cout<<"Max points: "<<OPT[n]<<endl;
    int i = n;

    vector<int> solution;
    while (i>0){
        //i-1 die to 0 based indexing
        if (best[i] == 0){
            solution.push_back(low[i-1]);
            i--;
        }else{
            solution.push_back(high[i-1]);
            i=i-2;
        }
    }
    reverse(solution.begin(), solution.end());
    return solution;
}

int main(){
    int n; cin>>n; 
    vector<int> low; vector<int> high;

    for (int i=0; i<n; i++){
        int k; cin>>k; 
        low.push_back(k);
    }

    for (int i=0; i<n; i++){
        int k; cin>>k;
        high.push_back(k);
    }

    printVector(optimumSchedule(low, high));
    return 0;
}