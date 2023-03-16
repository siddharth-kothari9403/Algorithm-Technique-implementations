#include <bits/stdc++.h>
using namespace std;

class hall_period{
    private :
        int start, end;
        int hallno;

    public:
        hall_period(int s, int e){
            this->start = s;
            this->end = e;
            this->hallno = 0;
        }

        int getstart(){
            return this->start;
        }
        int getfinish(){
            return this->end;
        }
        int gethall(){
            return this->hallno;
        }
        void sethall(int hall){
            this->hallno = hall;
        }
};

class IntervalFinishCompare{
    public:
    bool operator() (hall_period &a, hall_period &b){
        return a.getfinish() > b.getfinish();  
    };
};

struct IntervalStartCompare {
    bool operator() (hall_period &a, hall_period &b){
        return a.getstart() < b.getstart();  
    };
};

int main(){
    int n; cin>>n;

    vector<hall_period> intervals;

    for (int i=0; i<n; i++){
        int s, e;
        cin>>s>>e;
        hall_period * hall = new hall_period(s,e); 
        intervals.push_back(*hall);
    }

    sort(intervals.begin(), intervals.end(), IntervalStartCompare());
    priority_queue<hall_period, vector<hall_period>, IntervalFinishCompare> pq;

    priority_queue<int, vector<int>, greater<int>> available;
    
    int maxhallno = 2;
    for (int i=0; i<n; i++){
        if (pq.empty()){
            intervals[i].sethall(1);
            pq.push(intervals[i]);

            available.push(2);
            continue;
        }

        hall_period hp = pq.top();
        
        if (hp.getfinish() <= intervals[i].getstart()){
            int hallno = hp.gethall();
            intervals[i].sethall(hallno);
            pq.pop();

            pq.push(intervals[i]);
            available.push(hallno);
        }else{
            int hallno = available.top();
            
            intervals[i].sethall(hallno);
            pq.push(intervals[i]);
            available.pop();

            if (hallno == maxhallno){
                maxhallno++;
                available.push(maxhallno);
            }
        }
    }

    for (int i=0; i<n; i++){
        cout<<intervals[i].getstart()<<" "<<intervals[i].getfinish()<<" "<<intervals[i].gethall()<<endl;
    }

    cout<<maxhallno-1<<endl;

    return 0;
}