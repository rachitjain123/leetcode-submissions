class UndergroundSystem {
public:
 
    map<int,pair<int,string> > userCheckInMap;
    map<pair<string,string>, pair<int,int> > stationPair;
    
    UndergroundSystem() {
        
    }
    

    
    void checkIn(int id, string stationName, int t) {
        // if(userCheckInMap.find(id) != userCheckInMap.end())
        userCheckInMap[id]={t,stationName};
    }
    
    void checkOut(int id, string stationCheckOut, int timeCheckOut) {
        // if(userCheckInMap.find(id)==userCheckInMap.end())
        int timeCheckIn = userCheckInMap[id].first;
        string stationCheckIn = userCheckInMap[id].second;
        
        userCheckInMap.erase(id);
        // if(timeCheckOut < timeCheckIn) ..
        int diffTimeDuration = timeCheckOut - timeCheckIn;
        
        
        if(stationPair.find({stationCheckIn, stationCheckOut}) != stationPair.end())
        {
            stationPair[{stationCheckIn, stationCheckOut}].first += 1; 
            stationPair[{stationCheckIn, stationCheckOut}].second += diffTimeDuration;
        }
        else
        {
            stationPair[{stationCheckIn, stationCheckOut}].first = 1; 
            stationPair[{stationCheckIn, stationCheckOut}].second = diffTimeDuration;
        }
        
    }
    
    double getAverageTime(string stationCheckIn, string stationCheckOut) {
        // if(stationPair.find({stationCheckIn, stationCheckOut}) == stationPair.end())
        
        int totalNumTravels = stationPair[{stationCheckIn, stationCheckOut}].first;
        int totalDiffDuration = stationPair[{stationCheckIn, stationCheckOut}].second;
        
        double avgTime = (double)(totalDiffDuration/(double) totalNumTravels);
        
        return avgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */