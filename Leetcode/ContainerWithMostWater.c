// Leetcode 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/description/
// Runtime: 169ms (纯粹的不及格)

int maxArea(int* height, int heightSize) 
{
    int max = 0;
    int len = heightSize;
    for (int i = 0; i < heightSize - 1; i++) 
    {
        int last = heightSize - 1;
        int biggestSmall = 0;
        int area = 0;

        if ((height[i] * (last - i) < max)) 
        {
            continue;
        }

        while (last > i) 
        {
            if (height[last] >= height[i]) 
            {
                break;
            }
            if (height[last] < height[i]) 
            {
                biggestSmall = height[last] * (last - i);
                if (biggestSmall > max) 
                {
                    max = biggestSmall;
                }
            }
            last--;
        }
        if (last != i) 
        {
            area = (last - i) * height[i];
        }
         
        if (area > max) 
        {
            max = area;
        }
    }
    return max;
}

// 4ms参考解法
int maxArea_fast(int* height, int heightSize) 
{
    int head,tail, left,right, maxi, vol;
    head = 0, tail = heightSize - 1;
    maxi = 0;
    while(head != tail)
    {
        left = height[head];
        right = height[tail];
        if( left < right )
        {
            vol = left * (tail - head);
            if( vol > maxi )
                maxi = vol;
            head++;
        }
        else
        {
            vol = right * (tail - head);
            if( vol > maxi )
                maxi = vol;
            tail--;
        }
    }
    return maxi;
}
