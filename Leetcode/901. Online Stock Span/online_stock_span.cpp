// Leetcode 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/
// time complexity: O(n)
// space complexity: O(n)

typedef struct Data
{
    int price;
    int span;
};

class StockSpanner 
{
    stack<Data> st;
public:
    StockSpanner() { }
    
    int next(int price) 
    {
        int current_span = 1;
        if (st.empty())
        {
            Data d = {price, current_span};
            st.push(d);
        }
        else
        {
            while (!st.empty())
            {
                Data last = st.top();
                if (last.price <= price)
                {
                    current_span += last.span;
                    st.pop();
                }
                else
                {
                    Data current = {price, current_span};
                    st.push(current);
                    break;
                }
            }
            
            if (st.empty())
            {
                Data current = {price, current_span};
                st.push(current);
            }
        }
        
        return current_span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
