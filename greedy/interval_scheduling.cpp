#include <bits/stdc++.h>
using namespace std;

class Interval{
    private: 
    int start, end;

    public:
    Interval(int s, int e){
        this->start = s;
        this->end = e;
    }

    int getStart(){
        return this->start;
    }

    int getEnd(){
        return this->end;
    }
};

class IntervalFinishCompare{
    public:
    bool operator() (Interval &a, Interval &b){
        return a.getEnd() < b.getEnd();
    }
};

int main(){
    int n; cin>>n;
    vector<Interval> intervals;
    for (int i=0; i<n; i++){
        int s, e; cin>>s>>e;
        Interval in = Interval(s, e);
        intervals.push_back(in);
    }

    sort(intervals.begin(), intervals.end(), IntervalFinishCompare());

    vector<Interval> chosen;
    int i=0;
    while (i<n){
        Interval current = intervals[i];
        chosen.push_back(current);
        int index = i;
        i++;
        while (true){
            if (intervals[i].getStart() < intervals[index].getEnd()){
                i++;
            }else{
                break;
            }
        }
    }

    cout<<chosen.size()<<endl;
    cout<<"Chosen intervals: "<<endl;
    for (int i=0; i<chosen.size(); i++){
        cout<<chosen[i].getStart()<<" "<<chosen[i].getEnd()<<endl;
    }
    return 0;
}