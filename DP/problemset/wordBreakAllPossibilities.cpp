#include<bits/stdc++.h>
using namespace std;

//helper function to check whether a word is valid
bool isValidWord(string s, vector<string> & WordDict){
    for (int i=0; i<WordDict.size(); i++){
        if (s == WordDict[i]){
            return true;
        }
    }

    return false;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {

    //OPT contains all the possibilities for each index
    int n = s.size();
    vector<vector<vector<string>>> OPT;
    vector<vector<string>> temp = {};
    OPT.resize(n, temp);

    //by default, empty vectors, OPT follows zero based indexing
    for (int i=0; i<n; i++){
        int j= i;
        while (j>0){

            //if OPT[j-1].size() != 0 then there exists atleast 1 way to break S[0...j-1], and if S[j...i] is valid,
            // then we have found ways to break S[0...i]
            string st = s.substr(j, i-j+1);
            if (OPT[j-1].size() != 0 && isValidWord(st, wordDict)){
                
                for (int k=0; k<OPT[j-1].size(); k++){

                    //the ways for S[0...i] will be the ways to break S[0...j-1] + the new valid word that we found
                    vector<string> temp = OPT[j-1][k];
                    temp.push_back(st);
                    OPT[i].push_back(temp);
                }
            }
            j--;
        }

        //one case not considered, when the entire substring S[0...i] is valid, in which case we add it separataley
        string st = s.substr(0, i+1);
        if (isValidWord(st, wordDict)){
            vector<string> temp;
            temp.push_back(st);
            OPT[i].push_back(temp);
        }
    }

    //giving the answer in specified format
    vector<string> soln;
    for (int i=0; i<OPT[n-1].size(); i++){
        string temp;
        for (int j=0; j<OPT[n-1][i].size(); j++){
            temp+=OPT[n-1][i][j];
            temp+=" ";
        }
        soln.push_back(temp.substr(0, temp.size()-1));
    }

    return soln;
}

void printVector(vector<string> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    vector<string> dictionary = {"cats", "cat", "sand", "and", "dog"};
    string s = "catsanddog";
    printVector(wordBreak(s, dictionary));
}