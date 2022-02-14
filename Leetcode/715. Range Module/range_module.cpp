// Leetcode 715. Range Module
// https://leetcode.com/problems/range-module/

class RangeModule
{
    map<int, int> range;
    
public:
    RangeModule()
    {
        
    }
    
    void addRange(int left, int right)
    {
        auto left_ub = range.upper_bound(left);
        auto right_ub = range.upper_bound(right);
       
        if (right_ub != range.begin())
        {
            right_ub--;
            
            int newLeft = left;
            int newRight = right;
            if (left_ub != range.begin())
            {
                left_ub--;
                if (left_ub->first <= left && left_ub->second >= left)
                {
                    newLeft = min(left_ub->first, left);
                }
                else
                {
                    left_ub++;
                }
            }
            
            if (right_ub->second >= right && right_ub->first <= right)
            {
                newRight = max(right, right_ub->second);
            }
            
            if (right_ub->second < left)
            {
                range.insert(make_pair(left, right));
                return;
            }
            
            right_ub++;
            range.erase(left_ub, right_ub);
            
            range.insert(make_pair(newLeft, newRight));
        }
        else
        {
            range.insert(make_pair(left, right));
        }
    }
    
    bool queryRange(int left, int right)
    {
        if (range.empty())
        {
            return false;
        }
        
        auto left_ub = range.upper_bound(left);
        if (left_ub != range.begin())
        {
            left_ub--;
            return left_ub->second >= right;
        }
        else
        {
            return left_ub->first <= left && left_ub->second >= right;
        }
        
        return false;
    }
    
    void removeRange(int left, int right)
    {
        auto left_ub = range.upper_bound(left);
        auto right_ub = range.upper_bound(right);
        
        if (right_ub != range.begin())
        {
            right_ub--;
            
            int newleft = -1;
            if (left_ub != range.begin())
            {
                left_ub--;
                if (left_ub->first <= left && left_ub->second >= left)
                {
                    newleft = left_ub->first;
                }
                else
                {
                    left_ub++;
                }
            }
            
            int newright = -1;
            if (right_ub->second >= right && right_ub->first <= right)
            {
                newright = right_ub->second;
            }
            
            right_ub++;
            
            range.erase(left_ub, right_ub);
            
            if (newleft != -1)
            {
                range.insert(make_pair(newleft, left));
            }
            if (newright != -1)
            {
                range.insert(make_pair(right, newright));
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
