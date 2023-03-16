#include <bits/stdc++.h>
using namespace std;

bool checkPartitioning(string s) {
    int n = s.length();
    vector<vector<bool>> palindrome;
    vector<bool> temp;
    temp.resize(n, 0);
    palindrome.resize(n, temp);

    //cut1 -> possible to make of size 1
    vector<bool> cut1;
    cut1.resize(n, 0);

    //cut2-> possible to make of size 2
    vector<bool> cut2;
    cut2.resize(n, 0);

    //cut3-> possible to make of size 3
    vector<bool> cut3;
    cut3.resize(n, 0);

    //cut3(n-1) would be the answer 
    for (int i=0; i<n; i++){
        palindrome[i][i] = true;
    } 

    for (int i=0; i<n; i++){
        for (int j=i; j>-1; j--){
            if ((s[j] == s[i]) && (i-j < 2 || palindrome[j+1][i-1])){
                palindrome[j][i] = true;
                if (j==0) cut1[i] = true;
                else{
                    if (cut1[j-1] == true){
                        cut2[i]=true;
                    }

                    if (cut2[j-1] == true){
                        cut3[i]=true;
                    } 

                    //we only need cut1 and cut2 for checking, we don't concern ourselves with more
                }
                
            }
        }
    }

    return cut3[n-1];
}

int main(){
    string s;
    cin>>s;
    if (checkPartitioning(s)){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}