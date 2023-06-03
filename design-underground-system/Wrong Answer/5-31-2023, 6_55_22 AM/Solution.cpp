// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
    unordered_map<string, vector<pair<int,int>>> in, out;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[stationName].push_back({id, t});
    }
    
    void checkOut(int id, string stationName, int t) {
        out[stationName].push_back({id, t});
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0.0;
        double count = 0.0;
        for(int i=0, j=0; i < out[endStation].size() && j < in[startStation].size(); i++, j++) {
            if(out[endStation][i].first == in[startStation][j].first) {
                sum += out[endStation][i].second - in[startStation][j].second;
                count++;
            }
        }

        return sum / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */