package p0869_Reordered_Power_of_2

func reorderedPowerOf2(n int) bool {
	nl := fuck(n)
	shit := 1
	for i := 0; i < 31; i++ {
		shitL := fuck(shit)
		if nl == shitL && findN(shit) == findN(n) {
			return true
		}
		shit *= 2
	}
	return false
}

// 十进制位数，n>=1
func fuck(n int) int {
	res := 0
	for n > 0 {
		n /= 10
		res++
	}
	return res
}

// 每个数的个数
func findN(n int) [10]int {
	res := [10]int{}
	for n > 0 {
		res[n%10]++
		n /= 10
	}
	return res
}
