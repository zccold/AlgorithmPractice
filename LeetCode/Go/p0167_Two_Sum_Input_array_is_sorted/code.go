package p0167_Two_Sum_Input_array_is_sorted

func twoSum(numbers []int, target int) []int {
	i := 0
	j := len(numbers) - 1
	for i < j {
		shit := numbers[i] + numbers[j]
		if shit == target {
			return []int{i + 1, j + 1}
		} else if shit < target {
			i++
		} else {
			j--
		}
	}
	return nil
}
