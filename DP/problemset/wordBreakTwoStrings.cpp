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

bool wordBreak(string s1, string s2, vector<string>& wordDict) {
    //input -> s[1...n]

    if (s1.size() != s2.size()){
        return false;
    }

    int n= s1.size();
    vector<bool> res;
    res.resize(n+1, 0);
    
    //n+1 due to one based indexing, 
    //res[0] = 1; for any i, res[i] = 1 if there exists 0<=j<i such that res[j] = 1 and S1[j+1, i] and S2[j+1,i] is a valid string

    res[0]=true;
    for (int i=1; i<=n; i++){
        int i1 = i-1;
        int j = i1;
        while (j>=0){
            //extracting substring and checking condition
            string st1= s1.substr(j, i1-j+1);
            string st2= s2.substr(j, i1-j+1);

            if (res[j] == true && isValidWord(st1, wordDict) && isValidWord(st2, wordDict)){
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
    vector<string> dictionary = {"heart", "and", "body", "start", "one", "week"};
    string s1 = "heartandbody";
    string s2 = "startoneweek";
    if (wordBreak(s1, s2, dictionary)){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Not possible"<<endl;
    }
}