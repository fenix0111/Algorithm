// Leetcode 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// Runtime: 8ms

// using stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].compare("+") == 0) {
                int right = stoi(st.top());
                st.pop();
                
                int left = stoi(st.top());
                st.pop();
                
                st.push(to_string(left + right));
                
            } else if (tokens[i].compare("-") == 0) {
                int right = stoi(st.top());
                st.pop();
                
                int left = stoi(st.top());
                st.pop();
                
                st.push(to_string(left - right));
                
            } else if (tokens[i].compare("*") == 0) {
                int right = stoi(st.top());
                st.pop();
                
                int left = stoi(st.top());
                st.pop();
                
                st.push(to_string(left * right));
                
            } else if (tokens[i].compare("/") == 0) {
                int right = stoi(st.top());
                st.pop();
                
                int left = stoi(st.top());
                st.pop();
                
                st.push(to_string(left / right));
                
            } else {
                st.push(tokens[i]);
            }
        }
        
        return stoi(st.top());
    }
};
