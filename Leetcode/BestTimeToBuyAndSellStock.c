// Leetcode 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Runtime: 712 ms

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;

	for (int i = 0; i < pricesSize - 1; i++)
	{
		for (int j = i + 1; j < pricesSize; j++)
		{
			if (prices[j] - prices[i] > 0 && (prices[j] - prices[i] > profit))
				profit = prices[j] - prices[i];
		}
	}
	return profit;
}
