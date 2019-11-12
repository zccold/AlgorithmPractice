package p0036_Valid_Sudoku

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		if !isOjbk(board[i]) {
			return false
		}
		row := make([]byte, 9)
		for j := 0; j < 9; j++ {
			row[j] = board[j][i]
		}
		if !isOjbk(row) {
			return false
		}
		startX := i / 3 * 3
		startY := i % 3 * 3
		index := 0
		for x := 0; x < 3; x++ {
			for y := 0; y < 3; y++ {
				row[index] = board[startX+x][startY+y]
				index++
			}
		}
		if !isOjbk(row) {
			return false
		}
	}
	return true
}

func isOjbk(nums []byte) bool {
	shit := make([]bool, 10, 10)

	for i := 0; i < len(nums); i++ {
		if nums[i] == '.' {
			continue
		} else if shit[nums[i]-'1'] {
			return false
		} else {
			shit[nums[i]-'1'] = true
		}
	}
	return true
}
