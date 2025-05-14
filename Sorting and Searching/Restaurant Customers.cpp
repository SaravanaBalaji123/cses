#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    vector<pair<int, int>> timings(n);
    for(int i = 0; i < n; i++){
        cin >> timings[i].first >> timings[i].second; 
    }
    vector<pair<int, bool>> events;
    for(int i = 0; i < n; i++){
        events.push_back({timings[i].first, true});// Arrival
        events.push_back({timings[i].second, false});// Departure
    }
    sort(events.begin(), events.end(),
        [](const pair<int, bool> &a, const pair<int, bool> &b){
           if(a.first == b.first){
            return a.second < b.second ; // If timing are same prefer departure over arrival time
           }
           return a.first < b.first;
        });
    int curr_customers = 0, max_customers = 0;    
    for(auto event : events){
        if(event.second){
            curr_customers++;
        }
        else{
            curr_customers--;
        }
        max_customers = max(max_customers, curr_customers);
    }
    cout << max_customers << endl;
    return 0;
}