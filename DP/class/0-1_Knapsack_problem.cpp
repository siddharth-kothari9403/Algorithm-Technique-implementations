#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> knapsack(vector<int> weights, int maxWeight){
    //OPT[i,w] -> optimal with max weight w and only consisiting of elements from 1 to i
    //hence answer is OPT[n, W]

    //OPT[i,w] = max(OPT[i-1, w], OPT[i-1, w-wi] + wi, where wi is weight of i
    //i may or may not be included in the answer, if not included the answer is directly equal to OPT[i-1, w]
    //if included , we take wi and add it to w-wi, as the max weight without it can only be wi

    //best contains the indices to jump to, used for backtracking

    //initialisations

    int n = weights.size();
    vector<vector<int>> OPT;
    vector<vector<pair<int, int>>> best;

    vector<int> temp; 
    temp.resize(maxWeight+1, 0);
    OPT.resize(n+1, temp);

    pair<int, int> temp1 = {-1,-1};
    vector<pair<int, int>> temp2;
    temp2.resize(maxWeight+1, temp1);
    best.resize(n+1, temp2);

    for (int w=0; w<=maxWeight; w++){
        OPT[0][w] = 0;
    }

    for (int i=0; i<=n; i++){
        OPT[i][0] = 0;
    }

    for (int i=1; i<=n; i++){
        for (int w=1; w<=maxWeight; w++){

            if (w-weights[i-1] < 0){
                OPT[i][w] = OPT[i-1][w];
                best[i][w].first = i-1; best[i][w].second = w;
            }else{
                if (OPT[i-1][w] > OPT[i-1][w-weights[i-1]] + weights[i-1]){
                    OPT[i][w] = OPT[i-1][w];
                    best[i][w].first = i-1; best[i][w].second = w;
                }else{
                    OPT[i][w] = OPT[i-1][w-weights[i-1]] + weights[i-1];
                    best[i][w].first = i-1; best[i][w].second = w-weights[i-1];
                }
            }
        }
    }

    cout<<"Max weight: "<<OPT[n][maxWeight]<<endl;
    cout<<"Elements in sack: "<<endl;

    vector<int> solution;
    int i=n; int w=maxWeight;
    while (i>0){
        if (best[i][w].second == w-weights[i-1]){

            solution.push_back(weights[i-1]);
        } 
//everywhere i-1 as the size of best and OPT is 1 more than weight
        w = best[i][w].second;
        i--;
    }
    
    // solution.push_back(weights[i]);

    reverse(solution.begin(), solution.end());
    return solution;
}

int main(){
    int n; cin>>n;

    int max; cin>>max;//everywhere i-1 as the size of best and OPT is 1 more than weight

    vector<int> weights;
    for (int i=0; i<n; i++){
        int k; cin>>k;
        weights.push_back(k);
    }

    printVector(knapsack(weights, max));
    return 0;

}