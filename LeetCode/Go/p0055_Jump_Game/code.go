package p0055_Jump_Game

func canJump(nums []int) bool {
	max := 0
	for i, num := range nums {
		if max < i {
			return false
		}
		if i+num > max {
			max = i + num
		}
	}
	return true
}
