// Leetcode 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i/

// brute force solution
class MyCalendar 
{
    vector<pair<int,int>> dates;
public:
    MyCalendar() {  }
    
    bool book(int start, int end) 
    {
        if (dates.empty())
        {
            dates.push_back(make_pair(start, end));
            return true;
        }
        
        sort(dates.begin(), dates.end(), [](auto x, auto y){
           return x.second < y.first; 
        });
        
        bool valid = true;
        for (int i = 0; i < dates.size(); i++)
        {
            int l = dates[i].first;
            int r = dates[i].second;
            
            if ((end <= l) || (start >= r))
            {
                continue;
            }
            else
            {
                valid = false;
                break;
            }
        }
        
        if (valid)
        {
            dates.push_back(make_pair(start, end));
        }
        
        return valid;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
