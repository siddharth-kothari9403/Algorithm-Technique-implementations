#include <bits/stdc++.h>
using namespace std;

void printGroups(vector<vector<int>> groups){
    for (int i=0; i<groups.size(); i++){
        cout<<"Number of children: "<<groups[i].size()<<endl;
        for (int j=0; j<groups[i].size(); j++){
            cout<<groups[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int children; cin>>children;
    vector<int> ages;

    for (int i=0; i<children; i++){
        int k; cin>>k;
        ages.push_back(k);
    }

    sort(ages.begin(), ages.end());

    int child_no = 0;
    vector<vector<int>> groups;

    while (child_no < children){
        int curr_age = ages[child_no];
        int curr_child = child_no;

        vector<int> group;
        while (child_no < children){
            if (ages[child_no] - ages[curr_child] <= 2){
                group.push_back(ages[child_no]);
                child_no++;
            }else{
                break;
            }
        }

        groups.push_back(group);
    }

    cout<<endl;
    cout<<groups.size()<<endl;
    printGroups(groups);
}