package p0122_Best_Time_to_Buy_and_Sell_Stock_2

func maxProfit(prices []int) int {
	sum := 0
	for i := 0; i < len(prices)-1; i++ {
		if prices[i+1] > prices[i] {
			sum += prices[i+1] - prices[i]
		}
	}
	return sum
}
