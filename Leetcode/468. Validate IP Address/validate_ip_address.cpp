// Leetcode 468. Validate IP Address
// https://leetcode.com/problems/validate-ip-address/
// Runtime: 4 ms
// Memory: 6.9 MB

class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find(".") != string::npos && IP.find(":") != string::npos)
        {
            return "Neither";
        }
        
        vector<string> addr;
        if (IP.find(".") != string::npos)
        {
            addr = split(IP, ".");
            if (addr.size() != 4)
            {
                return "Neither";
            }
            
            for (string s : addr)
            {
                if (!isValid4(s))
                {
                    return "Neither";
                }
            }
            
            return "IPv4";
        }
        else
        {
            addr = split(IP, ":");
            if (addr.size() != 8)
            {
                return "Neither";
            }
            for (string s : addr)
            {
                if (!isValid6(s))
                {
                    return "Neither";
                }
            }
            
            return "IPv6";
        }
    }
    
    bool isValid4(string ip)
    {
        if (ip.length() == 1)
        {
            return true;
        }
        
        // invalid length
        if (ip.length() == 0 || ip.length() > 3)
        {
            return false;
        }
        
        // check leading zero
        if (ip[0] == '0' && ip.length() > 1)
        {
            return false;
        }
        
        // check range of each character
        for (char c : ip)
        {
            if (!(c >= '0' && c <= '9'))
            {
                return false;
            }
        }
        
        // is greater than 255 ?
        int val = stoi(ip);
        if (val > 255)
        {
            return false;
        }
        
        return true;
    }
    
    bool isValid6(string ip)
    {
        if (ip.length() > 4 || ip.length() == 0)
        {
            return false;
        }
        
        // check range, character should be 0 ~ 9 , and A ~ F or a ~ f
        for (char c : ip)
        {
            if ( !( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') ) )
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> split(string ip, string delimiter)
    {
        vector<string> ret;
        size_t pos = 0;
        size_t last = 0;
        string token;
        string ss = ip;
        
        while ((pos = ss.find(delimiter)) != string::npos) 
        {
            token = ss.substr(0, pos);
            ss = ss.substr(token.length() + 1, ss.length() - token.length() + 1);
            ret.push_back(token);
        }
        ret.push_back(ss);
        
        return ret;
    }
};
