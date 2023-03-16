#include <bits/stdc++.h>
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

int wordBreak(string s, vector<string>& wordDict) {
    //input -> s[1...n]

    int n= s.size();
    vector<int> res;
    res.resize(n+1, 0);
    
    //n+1 due to one based indexing, 
    //res[0] = min of res[j] + 1, if S[j+1, i] is a valid string, and res[j] != 0 which tells there exists atleast 1 way to partition the substring

    res[0]=0;
    for (int i=1; i<=n; i++){
        int i1 = i-1;
        int j = i1;

        int min = INT_MAX;
        while (j>=0){
            //extracting substring and checking condition
            string st= s.substr(j, i1-j+1);
            if (res[j] !=0 && isValidWord(st, wordDict)){
                if (res[j] + 1 < min) min = res[j] + 1;
            }
            j--;
        }

        //takes care of the case when s[1...i] itself is a valid word
        if (isValidWord(s.substr(0, i), wordDict)){
            min = 1;
        }

        res[i] = min;
    }

    return res[n];
}

int main(){
    vector<string> dictionary = {"art", "is", "artist", "oil", "toil"};
    string s = "artistoil";
    cout<<wordBreak(s, dictionary)<<endl;
}