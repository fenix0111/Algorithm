// using priority_heap

class Solution
{
    struct comp
    {
        bool operator() (const vector<int>& x, const vector<int>& y)
        {
            if (x[2] > y[2])
            {
                return true;
            }
            
            if (x[2] == y[2])
            {
                return x[1] > y[1];
            }
            else
            {
                return false;
            }
        }
    };
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int currentPassengers = 0;
        sort(trips.begin(), trips.end(), [&](auto x, auto y) {
            if (x[1] < y[1])
            {
                return true;
            }
            else
            {
                if (x[1] == y[1])
                {
                    return x[2] < y[2];
                }
                else
                {
                    return false;
                }
            }
        });
        
        priority_queue<vector<int>, vector<vector<int>>, comp> q;
        int loc = 1;
        int i = 0;
        
        while (loc <= 1000 && i < trips.size())
        {            
            vector<int>& trip = trips[i];
            
            while (!q.empty() && q.top()[2] <= loc)
            {
                currentPassengers -= q.top()[0];
                q.pop();
            }
            
            if (trip[1] > loc)
            {
                loc++;
            }
            else
            {
                q.push(trip);
            
                currentPassengers += trip[0];
                if (currentPassengers > capacity)
                {                    
                    return false;
                }
                
                i++;
            }
        }
                
        return true;
    }
};
