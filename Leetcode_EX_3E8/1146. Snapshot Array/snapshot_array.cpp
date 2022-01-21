// Leetcode 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/

class SnapshotArray
{
    vector<int> data;
    int sid = 0;
    
    // <index, <snapshot_id, value>>
    unordered_map< int, vector<pair<int, int>> > table;
    
public:
    SnapshotArray(int length)
    {
        data.assign(length, 0);
    }
    
    void set(int index, int val)
    {
        data[index] = val;
        if (table.count(index) && table[index].back().first == sid)
        {
            table[index].back().second = val;
            return;
        }
        
        table[index].push_back(make_pair(sid, val));
    }
    
    int snap()
    {
        int prev_sid = sid;
        sid++;
        return prev_sid;
    }
    
    int get(int index, int snap_id)
    {
        int result = 0;
        if (table.count(index) == 0)
        {
            return 0;
        }
        
        vector<pair<int,int>>& record = table[index];
        int beg = 0;
        int end = record.size() - 1;

        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (record[mid].first < snap_id)
            {
                beg = mid + 1;
            }
            else if (record[mid].first > snap_id)
            {
                end = mid - 1;
            }
            else
            {
                return record[mid].second;
            }
        }

        // data were added after snapshot with snap_id
        if (end < 0)
        {
            result = 0;
        }
        else if (beg >= record.size())
        {
            // the last data update happened before the snapshot with snap_id
            result = record.back().second;
        }
        else
        {
            result = record[end].second;
        }
        
        return result;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
