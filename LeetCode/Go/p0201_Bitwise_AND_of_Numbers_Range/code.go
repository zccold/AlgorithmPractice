package p0201_Bitwise_AND_of_Numbers_Range

func rangeBitwiseAnd(m int, n int) int {
	offset := 0
	for m != n {
		m >>= 1
		n >>= 1
		offset += 1
	}
	return m << offset
}
