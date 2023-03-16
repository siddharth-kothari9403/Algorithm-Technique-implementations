#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    //OPT[i] -> min number of coins to make the sum i, hence answer is OPT[amount] 
    vector<int> OPT;

    //INT_MAX Indicates we can't get that particular number from any combination of the coins
    //OPT[0] = 0 as obiously if we choose 0 coins, the sum is 0
    OPT.resize(amount + 1, INT_MAX);
    OPT[0] = 0;

    //for a given sum, the sum can be formed from OPT[sum - coins[j]], by adding 1 coin of value coins[j] to it, take the minimum over all j
    //that is the recurrence relation
    //OPT[sum] = min over all j (OPT[sum - coins[j]] + 1)
    for (int sum=1; sum<= amount; sum++){
        int min = INT_MAX;
        for (int j=0; j<coins.size(); j++){
            if (sum - coins[j] >= 0 && OPT[sum - coins[j]] < INT_MAX){
                if (OPT[sum - coins[j]] + 1 < min ){
                    min = OPT[sum - coins[j]] + 1;
                }
            }
        }

        OPT[sum] = min;
    }

    //if we can't get the value, the answer is -1, return it
    if (OPT[amount] == INT_MAX){
        return -1;
    }
    //else return the coins needed
    return OPT[amount];
}

int main(){
    int n; cin>>n;
    int amt; cin>>amt;
    vector<int> coins; 

    for (int i=0; i<coins.size(); i++){
        int k; cin>>k;
        coins.push_back(k);
    }

    cout<<coinChange(coins, amt)<<endl;
    return 0;
}