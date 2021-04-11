// Leetcode 535. Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

// using base 62 conversion
class Solution 
{
    char base[62] = {'0','1','2','3','4','5','6','7','8','9',                                                        
                     'a','b','c','d','e','f','g','h','i','j',
                     'k','l','m','n','o','p','q','r','s','t',
                     'u','v','w','x','y','z','A','B','C','D',
                     'E','F','G','H','I','J','K','L','M','N',
                     'O','P','Q','R','T','S','U','V','W','X','Y','Z'};
    
    unordered_map<string, string> urlTable;
    string domain = "http://tinyurl.com/";
    
public:

    string base62Conversion(uint64_t t)
    {
        string result = "";
        while (t > 0)
        {
            result.push_back(base[t % 62]);
            t /= 62;
        }
        
        return result;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        uint64_t t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
                
        string shortUrl = domain + base62Conversion(t);
        urlTable[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return urlTable[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
