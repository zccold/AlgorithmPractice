package p0011_Container_With_Most_Water

/*
	如果没能找到最优解，那么一定是：
	其中一边先到达最优解位置后的下一步，此边移动了，而不是另一边，
	出现这种情况的条件是，此边比当前的另一边矮，
	如果真的是这样，那么此时的容积已经超过最优解（min(left,right)与最优解相同，底边更长）
	所以我们必然不会错过最优解
*/
func maxArea(height []int) int {
	var max int
	i, j := 0, len(height)-1
	for i != j {
		//比较当前容积与当前最优解
		if min(height[i], height[j])*(j-i) > max {
			max = min(height[i], height[j]) * (j - i)
		}
		//较矮的一边向内移动
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return max
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
