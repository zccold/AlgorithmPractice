package p0766_Toeplitz_Matrix

func isToeplitzMatrix(matrix [][]int) bool {
	line := matrix[0]
	for i := 1; i < len(matrix); i++ {
		next := matrix[i]
		if !same(line[:len(line)-1], next[1:]) {
			return false
		}
		line = next
	}
	return true
}

func same(a, b []int) bool {
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
