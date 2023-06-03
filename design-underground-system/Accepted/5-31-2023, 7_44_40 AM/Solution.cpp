// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
    unordered_map<int, pair<string, int>> cust; 
    unordered_map<string, vector<int>> total;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int checkInTime = cust[id].second;
        string str = cust[id].first + "_"  + stationName;
        total[str].push_back(t - checkInTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str = startStation + "_"  + endStation;
        double sum = 0.0;
        double size = total[str].size();
        for(int i=0; i<size; i++) sum += total[str][i];
        return sum / size;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */