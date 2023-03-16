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

    Interval(){
        this->start = INT_MIN;
        this->end = INT_MIN;
    }

    int getStart(){
        return this->start;
    }

    int getEnd(){
        return this->end;
    }

    void update(int s, int e){
        this->start = s;
        this->end = e;
    }
};

class IntervalStartCompare{
    public:
    bool operator() (Interval &a, Interval &b){
        return a.getStart() < b.getStart();
    }
};

int main(){
    int n; cin>>n;
    vector<Interval> intervals;
    for (int i=0; i<n; i++){
        int s,e; cin>>s>>e;
        Interval in = Interval(s,e);
        intervals.push_back(in);
    }

    int people; cin>>people;
    vector<int> posns;
    for (int i=0; i<people; i++){
        int k; cin>>k;
        posns.push_back(k);
    }

    sort(posns.begin(), posns.end());
    sort(intervals.begin(), intervals.end(), IntervalStartCompare());

    int people_index=0;
    int covered_index = -1;

    vector<Interval> solution;

    while (people_index<people){
        int currpos = posns[people_index];

        int intervals_index = covered_index + 1;
        vector<Interval> overlaps;
        while (intervals_index < n){
            if (intervals[intervals_index].getStart() <= currpos){
                if (intervals[intervals_index].getEnd() >= currpos){
                    overlaps.push_back(intervals[intervals_index]);
                }
                intervals_index++;
            }else{
                break;
            }
        }

        Interval max_right;
        for (int i=0; i<overlaps.size(); i++){
            if (max_right.getEnd() < overlaps[i].getEnd()){
                max_right.update(overlaps[i].getStart(), overlaps[i].getEnd());
            }
        }

        solution.push_back(max_right);

        while (covered_index + 1 < n){
            if (intervals[covered_index + 1].getEnd() <= max_right.getEnd()){
                covered_index++;
            }else{
                break;
            }
        }

        while (people_index < people){
            if (posns[people_index] <= max_right.getEnd()){
                people_index++;
            }else{
                break;
            }
        }
    }
    cout<<endl;
    cout<<solution.size()<<endl;
    cout<<"Solution: "<<endl;
    for (int i=0; i<solution.size(); i++){
        cout<<solution[i].getStart()<<" "<<solution[i].getEnd()<<endl;
    }

    return 0;
}