package p0901_Online_Stock_Span

type StockSpanner struct {
	prices []int
	first  []int // 这个节点对应范围的开始index
}

func Constructor() StockSpanner {
	return StockSpanner{}
}

func (s *StockSpanner) Next(price int) int {
	s.prices = append(s.prices, price)
	if len(s.prices) == 1 {
		s.first = append(s.first, 0)
		return 1
	}
	lastPrice := s.prices[len(s.prices)-2]
	if lastPrice > price {
		s.first = append(s.first, len(s.prices)-1)
		return 1
	}

	// 从前一个数的区间开头开始找
	var first int
	for first = s.first[len(s.first)-1]; first >= 0; first-- {
		if s.prices[first] > price {
			break
		}
	}
	first++ // 多算了一个，回退一下
	s.first = append(s.first, first)
	return len(s.prices) - first
}
