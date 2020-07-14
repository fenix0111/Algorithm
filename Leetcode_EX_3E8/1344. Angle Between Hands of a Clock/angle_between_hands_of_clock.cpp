// Leetcode 1344. Angle Between Hands of a Clock
// https://leetcode.com/problems/angle-between-hands-of-a-clock/

// a bit tricky
class Solution 
{
public:
    double angleClock(int hour, int minutes) 
    {
        double angleHour = (double)(hour % 12) * 30.0;
        double angleMin = (double)minutes * 6.0;
        
        // offset according to the minutes
        double angleDelta = (double)minutes / 2.0;
        
        angleHour += angleDelta;
        
        double angle = abs(angleHour - angleMin);

        // ensure less than 180 degree
        if (angle >= 180.0)
        {
            angle = 360.0 - angle;
        }
        
        return angle;
    }
};
