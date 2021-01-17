package p0123_Best_Time_to_Buy_and_Sell_Stock_3

import (
	"math"
)

func maxProfit(prices []int) int {
	buy1, buy2, sell1, sell2 := math.MinInt32, math.MinInt32, 0, 0
	for _, p := range prices {
		sell2 = max(sell2, buy2+p)
		buy2 = max(buy2, sell1-p)
		sell1 = max(sell1, buy1+p)
		buy1 = max(buy1, -p)
	}
	return sell2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
