#include <bits/stdc++.h>
using namespace std;

int minPartition(string s){

    //initialisations
    int n = s.length();
    vector<vector<bool>> palindrome;
    vector<bool> temp;
    temp.resize(n, 0);
    palindrome.resize(n, temp);

    //palindrome[j][i] tells if S[j...i] is palindrome or not

    vector<int> cut;
    cut.resize(n, 0);
    //cut is the minimum cuts required to make substrings from S[0...i] such that all are palindromes
    //cut[n-1] + 1 will therefore be the value of k

    for (int i=0; i<n; i++){
        //single length substrings are palindromes by default
        palindrome[i][i] = true;
    } 

    for (int i=0; i<n; i++){
        //min can be atmost i, when each letter is separate
        int min = i;
        for (int j=i; j>-1; j--){

            if ((s[j] == s[i]) && (i-j < 2 || palindrome[j+1][i-1])){

                //if palindrome, then set new min and palindrome[j][i] to be true
                palindrome[j][i] = true;
                if (j==0) min = 0;
                else if (min > cut[j-1] + 1){
                    min = cut[j-1] + 1;
                } 
            }
        }

        //assign min value
        cut[i] = min;
    }

    //return k
    return cut[n-1] + 1;
}

int main(){
    string s;
    cin>>s;
    cout<<minPartition(s)<<endl;
}