package p0188_Best_Time_to_Buy_and_Sell_Stock_4

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 2, maxProfit(2,[]int{2,4,1}))
	assert.Equal(t, 7, maxProfit(2,[]int{3,2,6,5,0,3}))
}
