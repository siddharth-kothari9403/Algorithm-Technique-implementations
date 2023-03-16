//given an array, find the subsequence which has no 2 consecutive elements such that the sum is maximised
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> maxSequence(vector<int> input){
    if (input.size() == 1){
        return input;
    }

    else if (input.size() == 2){
        int elem = max(input[0], input[1]);
        vector<int> temp; temp.push_back(elem);
        return temp;
    }

    vector<int> solution;

    vector<int> OPT;
    OPT.resize(input.size(), -1);
    OPT[0] = input[0]; OPT[1] = max(input[0], input[1]); //initial conditions

    vector<int> sequence;
    sequence.resize(input.size(), -1);

    //for each j, either input[j] is in solution or not in solution
    //if it is in solution, then j-1 can't be. Hence the solution would be OPT[j-2] + input[j]
    //else it is input[j-1]

    //OPT -> vector to store max sum till that point
    //sequence -> vector to store whether input[j] was there in solution or not, used for backtracking
    //solution is the actual answer

    for (int i=2; i<input.size(); i++){
        if (OPT[i-2] + input[i] > OPT[i-1]){
            OPT[i] = OPT[i-2] + input[i];
            sequence[i] = 1;
        }else{
            sequence[i] = 0;
            OPT[i] = OPT[i-1];
        }
    }

    cout<<"Max sum- "<<OPT[input.size()-1]<<endl;
    cout<<"Array- ";

    int curr = input.size()-1;
    while (curr>=2){
        if (sequence[curr] == 1){
            solution.push_back(input[curr]);
            curr = curr-2;
            continue;
        }
        curr = curr-1;
    }

    solution.push_back(input[curr]);
    reverse(solution.begin(), solution.end());
    return solution;

}

int main(){
    int n; cin>>n;
    vector<int> input;
    for (int i=0; i<n; i++){
        int k; cin>>k;
        input.push_back(k);
    }

    printVector(maxSequence(input));
    return 0;
}