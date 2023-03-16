//to find a scheduling such that the weight is maximised, and no 2 intervals overlap
#include <bits/stdc++.h>
using namespace std;

class Interval{
    private:
    int start, end, weight;

    public:
    Interval(int s, int e, int w){
        start = s;
        end = e;
        weight = w;
    }

    int getStart(){
        return this->start;
    }

    int getEnd(){
        return this->end;
    }

    int getWeight(){
        return this->weight;
    }

};

class IntervalFinishCompare{
    public:
    bool operator () (Interval &a, Interval &b){
        if (a.getEnd() != b.getEnd()){
            return a.getEnd() < b.getEnd();
        }else{
            return a.getStart() < b.getStart();
        }
    }
};

void printVector(vector<Interval> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i].getStart()<<" "<<arr[i].getEnd()<<" "<<arr[i].getWeight()<<endl;
    }
}

void printInt(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binarySearchFinish(vector<Interval> intervals, int k){
    int l=0; int r=intervals.size()-1;

    if (intervals[0].getEnd() > k){
        return -1;
    }

    while (r-l > 1){
        int m = l+(r-l)/2;

        if (intervals[m].getEnd() <= k && intervals[m+1].getEnd() > k) return m; 
        else if (intervals[m].getEnd() > k) r = m-1;
        else if (intervals[m+1].getEnd() <= k) l = m+1;
    }

    if (intervals[r].getEnd() <= k) return r;
    else if (intervals[l].getEnd() > k) return -1;
    else return l;
}



vector<Interval> getSchedule(vector<Interval> intervals){
    sort(intervals.begin(), intervals.end(), IntervalFinishCompare());

    vector<Interval> solution;
    //OPT here contains the optimum weight till now
    //if interval j is part of answer, we add weight of interval j to OPT[lastEnding[j]]
    //lastEnding[j] keeps track of the last interval which ends before interval j starts
    //we compute and store at the start
    //if not part of answer, it is equal to OPT[j-1]

    int n = intervals.size();
    //OPT[n-1] is the answer
    vector<int> OPT;
    OPT.resize(n, 0);
    OPT[0] = intervals[0].getWeight();

    vector<int> lastEnding;
    lastEnding.resize(n, -1);

    //curr_p is the last interval which ended, p will be just after it 
    
    for (int j=0; j<n; j++){
        //brute force
        int curr_p = -1;
        int p = 0;
        while (p<j){

            if (intervals[p].getEnd() <= intervals[j].getStart()){
                
                //if interval found, move curr_p and p
                curr_p++; p++;
            }else{
                //else assign the lastEnding as curr_p and break, coz this is the first interval for which end > start of our interval
                break;
            }
        }
        lastEnding[j] = curr_p;

        //binary search approach uses 

        //lastEnding[j] = binarySearchFinish(intervals, intervals[j].getStart());

    }
    //lastEnding constructed


    //present vector tells us whether the interval is present or not, used in backtracking
    vector<int> present;
    present.resize(n, 0);

    for (int i=1; i<n; i++){
        if (lastEnding[i] != -1){
            if (OPT[i-1] > intervals[i].getWeight() + OPT[lastEnding[i]]){
                OPT[i] = OPT[i-1];
                present[i] = 0;
            }else{
                OPT[i] = OPT[lastEnding[i]] + intervals[i].getWeight();
                present[i] = 1;
            } 
        }else{
            if (OPT[i-1] > intervals[i].getWeight()){
                OPT[i] = OPT[i-1];
                present[i] = 0;
            }else{
                OPT[i] = intervals[i].getWeight();
                present[i] = 1;
            } 
        }
    }

    cout<<"Max Weight: "<<OPT[n-1]<<endl;
    cout<<"Array: "<<endl;

    int s = n;
    while (s>0){
        if (present[s] == 1){
            solution.push_back(intervals[s]);
            s = lastEnding[s];
        }else{
            s = s-1;
        }
    }

    return solution;
}

int main(){
    int n; cin>>n;
    cout<<"Enter start, finish time and weight of all intervals: "<<endl;

    vector<Interval> intervals;
    for (int i=0; i<n; i++){
        int s, e, w;
        cin>>s>>e>>w;
        intervals.push_back(Interval(s,e,w));
    }

    printVector(getSchedule(intervals));
    return 0;
}