#include<bits/stdc++.h>
using namespace std;

int maxSubstring(string s){
    int n = s.size();

    vector<vector<int>> opt;
    vector<int> temp;
    temp.resize(n, 0);
    opt.resize(n, temp);

    //opt[i,j] = opt[i+1, j-1] if a[i] = a[j] else 0
    //opt[i,j] indicates the length of the largest string starting at i and whose reverse ends at j
    //therefore max OPT[i,j] would be the answer

    for (int len = 2; len<=n; len++){
        for (int i=0; i+len-1<n; i++){
            //j=i+len-1
            if (s[i] == s[i+len-1] ){
                opt[i][i+len-1] = 1 + opt[i+1][i+len-2]; 
            }
        }
    }

    int max = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (max < opt[i][j]){
                max = opt[i][j];
            }
        }
    }

    return max;

}

int main(){
    string s;
    cin>>s;

    cout<<maxSubstring(s)<<endl;
}