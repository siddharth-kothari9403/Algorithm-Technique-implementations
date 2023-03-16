#include<bits/stdc++.h>
using namespace std;

//helper function to check validity of the string
bool isValidWord(string s, vector<string> & WordDict){
    for (int i=0; i<WordDict.size(); i++){
        if (s == WordDict[i]){
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    //input -> s[1...n]

    int n= s.size();
    vector<bool> res;
    res.resize(n+1, 0);
    
    //n+1 due to one based indexing, 
    //res[0] = 1; for any i, res[i] = 1 if there exists 0<=j<i such that res[j] = 1 and S[j+1, i] is a valid string

    res[0]=true;
    for (int i=1; i<=n; i++){
        int i1 = i-1;
        int j = i1;
        while (j>=0){
            //extracting substring and checking condition
            string st= s.substr(j, i1-j+1);
            if (res[j] == true && isValidWord(st, wordDict)){
                res[i] = true;
                break;
            }
            j--;
        }
    }

    //answer in the end is res[n]
    return res[n];
}

int main(){
    vector<string> dictionary = {"cats", "cat", "sand", "and", "dog"};
    string s = "catsanddog";
    if (wordBreak(s, dictionary)){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Not possible"<<endl;
    }
}
