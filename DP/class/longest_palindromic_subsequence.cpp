#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string arg){
    int n = arg.size();
    //array 1 indexed in explanation, but actually zero indexed
    //OPT[i,j] = longest susbsequence between i and j, both inclusive, hence answer is OPT[1,n]
    
    //if A[i] = A[j], then OPT[i,j] = OPT[i+1, j-1] + 2, else it is max of OPT[i,j-1], OPT[i+1,j], as atleast 1 has to be excluded, either A[i] or A[j]
    //best array does the same work as previously seen, it defines where to jump to.
    
    //base cases-> OPT[i][i] = 1, OPT[i][j] = 0, when i>j
    //best[i][j] = (-1,-1) when i>=j, they specify the ending of backtracking 

    //initialisations
    vector<vector<int>> OPT;
    vector<int> temp; 
    temp.resize(n, 0);
    OPT.resize(n, temp);

    for (int i=0; i<n; i++){
        OPT[i][i] = 1;
    }

    vector<vector<pair<int, int>>> best;
    vector<pair<int, int>> temp1;
    pair<int, int> temp2;
    temp2.first = -1; temp2.second = -1;
    temp1.resize(n, temp2);
    best.resize(n, temp1);

    //the actual algo starts now
    //first we do dp on the strings of length 1, then 2, ..., n

    //setting OPT and best according to conditions
    for (int len=1; len<=n; len++){
        for (int i=0; i<n-len; i++){
            //j = i+len
            if (arg[i] == arg[i+len]){
                OPT[i][i+len] = OPT[i+1][i+len-1] + 2;
                best[i][i+len].first = i+1; 
                best[i][i+len].second = i+len-1;
            }else{
                if (OPT[i+1][i+len] > OPT[i][i+len-1]){
                    OPT[i][i+len] = OPT[i+1][i+len];
                    best[i][i+len].first = i+1; 
                    best[i][i+len].second = i+len;
                }else{
                    OPT[i][i+len] = OPT[i][i+len-1];
                    best[i][i+len].first = i; 
                    best[i][i+len].second = i+len-1;
                }
            }
        }
    }

    cout<<"Sequence of length: "<<OPT[0][n-1]<<endl;
    cout<<"Sequence: "<<endl;

    //backtrack to get elements of palindrome
    string solution;

    int i = 0; int j = n-1;
    while (i<j){
        if (best[i][j].first == i+1 && best[i][j].second == j-1){
            //the letter was added
            solution+=arg[i];
        }
        pair<int,int> temp = best[i][j];
        i = temp.first; j = temp.second;
    }

    //when loop breaks, either i = j, where we need to add last element once, or i>j, where we directly terminate
    //making palindrome
    if (i==j){
        solution+=arg[i];
        int k = solution.size();
        for (int i=k-2; i>-1; i--){
            solution+=solution[i];
        }
    }else{
        int k = solution.size();
        for (int i=k-1; i>-1; i--){
            solution+=solution[i];
        }
    }

    return solution;

}

int main(){
    string s; cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}