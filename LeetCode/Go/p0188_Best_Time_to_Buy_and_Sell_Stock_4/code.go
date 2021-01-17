package p0188_Best_Time_to_Buy_and_Sell_Stock_4

import (
	"math"
)

func maxProfit(k int, prices []int) int {
	if k==0{
		return 0
	}
	if k>len(prices)/2{
		return maxProfitLargeK(prices)
	}
	buy:=make([]int,k)
	for i:=range buy{
		buy[i]=math.MinInt32
	}
	sell:=make([]int,k)
	for _,p:=range prices{
		for i:=range sell{
			sell[i]=max(sell[i],buy[i]+p)
			lastSell:=0
			if i<len(sell)-1{
				lastSell=sell[i+1]
			}
			buy[i]=max(buy[i],lastSell-p)
		}
	}
	return sell[0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


func maxProfitLargeK(prices []int) int {
	sum := 0
	for i := 0; i < len(prices)-1; i++ {
		if prices[i+1] > prices[i] {
			sum += prices[i+1] - prices[i]
		}
	}
	return sum
}

