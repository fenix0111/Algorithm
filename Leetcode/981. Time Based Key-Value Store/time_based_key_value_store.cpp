// Leetcode 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/
// time complexity: O(NlogN)
// space complexity: O(N)

class TimeMap
{
    // { key, pair<timestamp, value> }
    unordered_map< string, vector<pair<int, string>> > data;
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp)
    {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp)
    {
        if (data.count(key) == 0)
        {
            return "";
        }
        
        const vector<pair<int, string>>& v = data[key];
        int l = 0;
        int r = v.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (v[m].first > timestamp)
            {
                r = m - 1;
            }
            else if (v[m].first < timestamp)
            {
                l = m + 1;
            }
            else
            {
                return v[m].second;
            }
        }
        
        // no valid value when left index is 0
        if (l > 0)
        {
            return v[l - 1].second;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
