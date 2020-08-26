package p0085_Maximal_Rectangle

import (
	"container/list"
)

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	res := 0
	for i := range matrix[0] {
		heights := make([]int, len(matrix))
		for j := range matrix {
			height := 0
			for k := i; k >= 0; k-- {
				if matrix[j][k] == '1' {
					height++
				} else {
					break
				}
			}
			heights[j] = height
		}
		tmp := largestRectangleArea(heights)
		if tmp > res {
			res = tmp
		}
	}
	return res
}

//84题的方法
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
