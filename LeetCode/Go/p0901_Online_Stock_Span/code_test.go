package p0901_Online_Stock_Span

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestStockSpanner_Next(t *testing.T) {
	x := Constructor()
	shit := []struct {
		input  int
		output int
	}{
		{100, 1},
		{80, 1},
		{60, 1},
		{70, 2},
		{60, 1},
		{75, 4},
		{85, 6},
	}
	for _, item := range shit {
		output := x.Next(item.input)
		assert.Equal(t, item.output, output, item)
	}
}
