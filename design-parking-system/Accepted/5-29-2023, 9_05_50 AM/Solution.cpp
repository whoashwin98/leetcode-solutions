// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
    int bs, ms, ss;
    vector<int> big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        bs = big;
        ms = medium;
        ss = small;
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1: if(big.size() == bs) return false;
                    else {
                        big.push_back(-1);
                        return true;
                    }
            case 2: if(medium.size() == ms) return false;
                    else {
                        medium.push_back(-1);
                        return true;
                    }
            case 3: if(small.size() == ss) return false;
                    else {
                        small.push_back(-1);
                        return true;
                    }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */