// Leetcode 1396. Design Underground System
// https://leetcode.com/problems/design-underground-system/
// 
// 

class UndergroundSystem 
{
    // userId => <stationId, checkInTime>
    unordered_map<int, pair<int, int>> checkState;
    
    // station inverval in integer, startStation(higher 16 bits) endStation(lower 16 bits) => <total time, counts>
    // assume there are less than 65535 stations
    unordered_map<int, pair<double, int>> avg;
    
    // stationName => stationId
    unordered_map<string, int> stationTable;
    
    int stationId;
    
public:
    UndergroundSystem() 
    {
        stationId = 0;
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        int sid = stationId;
        if (stationTable.count(stationName) == 0)
        {
            stationTable[stationName] = stationId;
            stationId++;
        }
        else
        {
            sid = stationTable[stationName];
        }
        
        auto state = make_pair(sid, t);
        checkState[id] = state;
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto state = checkState[id];
        int sid = stationId;
        if (stationTable.count(stationName) == 0)
        {
            stationTable[stationName] = stationId;
            stationId++;
        }
        else
        {
            sid = stationTable[stationName];
        }
        
        int start_station_id = state.first;
        int end_station_id = sid;
        start_station_id <<= 16;
        start_station_id |= end_station_id;
        avg[start_station_id].first += (double)(t - state.second);
        avg[start_station_id].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        int start_station_id = stationTable[startStation];
        int end_station_id = stationTable[endStation];
        start_station_id <<= 16;
        start_station_id |= end_station_id;
        auto avgTime = avg[start_station_id];
        return avgTime.first / (double)avgTime.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
