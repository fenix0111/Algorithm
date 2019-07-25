// revised solution
class Solution 
{
public:
    int min(int x, int y)
    {
        return x < y ? x : y;
    }
    
    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        // check intersection
        bool intersected = true;
        if (C <= E || A >= G)
            intersected = false;
        
        if (D <= F || B >= H)
            intersected = false;
        
        unsigned long area_a = (C - A) * (D - B);
        unsigned long area_b = (G - E) * (H - F);
        
        unsigned long x, y;
        
        if (intersected)
        {
            x = max(A, E) - min(G, C);
            y = max(B, F) - min(D, H);
        }
        
        if (intersected)
            return (int)(area_a + area_b - (x * y));
        else
            return (int)(area_a + area_b);
    }
};
