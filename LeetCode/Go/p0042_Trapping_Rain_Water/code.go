package p0042_Trapping_Rain_Water

func trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}
	left := make([]int, len(height))
	for i := 1; i < len(height); i++ {
		if height[i-1] > left[i-1] {
			left[i] = height[i-1]
		} else {
			left[i] = left[i-1]
		}
	}
	right := make([]int, len(height))
	for i := len(height) - 2; i >= 0; i-- {
		if height[i+1] > right[i+1] {
			right[i] = height[i+1]
		} else {
			right[i] = right[i+1]
		}
	}
	res := make([]int, len(height))
	for i := 0; i < len(height); i++ {
		m := min(left[i], right[i])
		if m > height[i] {
			res[i] = m - height[i]
		}
	}
	sum := 0
	for _, v := range res {
		sum += v
	}
	return sum
}

func min(i, j int) int {
	if i < j {
		return i
	} else {
		return j
	}
}
