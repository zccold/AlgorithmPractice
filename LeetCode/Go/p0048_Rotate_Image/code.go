package p0048_Rotate_Image

func rotate(matrix [][]int) {
	//找一张纸，画画坐标什么的，还是比较好弄的，烦的点在于下标方向和正常坐标轴不一致
	if len(matrix) <= 1 {
		return
	}
	n := len(matrix)
	for i := 0; i < (n+1)/2; i++ {
		for j := 0; j < n/2; j++ {
			x1, y1 := i, j
			x2, y2 := j, n-1-i
			x3, y3 := n-1-i, n-1-j
			x4, y4 := n-1-j, i
			matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4] = matrix[x4][y4], matrix[x1][y1], matrix[x2][y2], matrix[x3][y3]
		}
	}
}
