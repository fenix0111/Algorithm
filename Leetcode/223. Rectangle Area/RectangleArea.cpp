// Leetcode 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/
// Runtime: 8ms

class Solution 
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        // check intersection
        bool intersected = true;
        if (C <= E || A >= G)
            intersected = false;
        
        if (D <= F || B >= H)
            intersected = false;

        unsigned long area_a = abs(C - A) * abs(D - B);
        unsigned long area_b = abs(G - E) * abs(H - F);
        
        unsigned long x, y;
        
        if (intersected)
        {
            if (E <= A && E <= C && G >= C && G >= A)
            {
                x = C - A;
            }
            else if (E >= A && E <= C && G <= C && G >= A)
            {
                x = G - E;
            }
            else if (A < E && E < C)
            {
                x = C - E;
            }
            else if (G < C && G > A)
            {
                x = G - A;
            }

            if (H >= B && H >= D && F <= B && F <= D)
            {
                y = D - B;
            }
            else if (H >= B && H <= D && F >= B && F <= D)
            {
                y = H - F;
            }
            else if (H > B && H < D)
            {
                y = H - B;
            }
            else if (F > B && F < D)
            {
                y = D - F;
            }
        }
        
        if (intersected)
            return (int)(area_a + area_b - (x * y));
        else
            return (int)(area_a + area_b);
    }
};
