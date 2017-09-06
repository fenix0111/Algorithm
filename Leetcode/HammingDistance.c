// Leetcode 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/description/
// Runtime: 3ms

int hammingDistance(int x, int y) {
    int vx = x;
	int vy = y;
	int dis = 0;
	while (vx || vy)
	{
		if ((vx & 0x1) != (vy & 0x1))
		{
			dis++;
		}
		vx = vx >> 1;
		vy = vy >> 1;
	}
	return dis;
}
