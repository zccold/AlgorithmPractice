package p0342_Power_of_Four

func isPowerOfFour(n int) bool {
	if n <= 0 {
		return false
	}
	for n%4 == 0 {
		n /= 4

	}
	return n == 1
}
