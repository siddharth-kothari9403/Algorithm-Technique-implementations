#include<bits/stdc++.h>
using namespace std;

void printVector(vector<vector<string>> arr){
    for (int i=0; i<arr.size(); i++){
        for (int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<bool>> palindrome;

    vector<vector<vector<string>>> OPT;
    vector<vector<string>> temp = {};
    OPT.resize(n, temp);
    
    //nxn matrix
    vector<bool> temp1;
    temp1.resize(n, 0);
    palindrome.resize(n, temp1);

    for (int i=0; i<n; i++){
        // cout<<"Here"<<endl;
        for (int j=i; j>-1; j--){
            
            if (s[j] == s[i] && ((i-j < 2) || palindrome[j+1][i-1])){
                // cout<<j<<" "<<i<<endl;
                palindrome[j][i] = true;
                
                if (j==0){
                    vector<string> temp2 = {s.substr(0, i+1)};
                    OPT[i].push_back(temp2);
                }else{
                    
                    vector<vector<string>> temp2 = OPT[j-1];

                    for (int k=0; k<temp2.size(); k++){
                        temp2[k].push_back(s.substr(j, i-j+1));
                        OPT[i].push_back(temp2[k]);
                    }
                }
                
            }
        }
    }

    return OPT[n-1];
}

int main(){
    string s;
    cin>>s;
    printVector(partition(s));
    return 0;
}