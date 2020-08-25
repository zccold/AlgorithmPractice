package p0084_Largest_Rectangle_in_Histogram

import "container/list"

//这个题解不错https://blog.csdn.net/Zolewit/article/details/88863970
func largestRectangleArea(heights []int) int {
	if len(heights) == 0 {
		return 0
	}
	heis := make([]int, len(heights)+2)
	copy(heis[1:], heights)
	tmp := 0
	l := list.New()
	for i := range heis {
		for l.Len() != 0 {
			topE := l.Back()
			top := topE.Value.(int)
			if heis[top] > heis[i] {
				l.Remove(topE)
				area := heis[top] * (i - l.Back().Value.(int) - 1)
				if area > tmp {
					tmp = area
				}
			} else {
				break
			}
		}
		l.PushBack(i)
	}

	return tmp
}
