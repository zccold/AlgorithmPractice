package p0079_Word_Search

func exist(board [][]byte, word string) bool {
	if len(board) == 0 || len(board[0]) == 0 {
		return false
	}
	flag := make([][]bool, len(board))
	for i := range flag {
		flag[i] = make([]bool, len(board[0]))
	}
	for i := range board {
		for j := range board[i] {
			if word[0] == board[i][j] {
				if search(&word, board, flag, 0, i, j) {
					return true
				}
			}
		}
	}
	return false
}
func search(word *string, board [][]byte, flag [][]bool, matchLen int, i, j int) bool {
	if matchLen == len(*word) {
		return true
	}
	iLen := len(board)
	jLen := len(board[0])
	if i < 0 || j < 0 || i == iLen || j == jLen || flag[i][j] || (*word)[matchLen] != board[i][j] {
		return false
	}
	flag[i][j] = true
	res := search(word, board, flag, matchLen+1, i-1, j) ||
		search(word, board, flag, matchLen+1, i+1, j) ||
		search(word, board, flag, matchLen+1, i, j-1) ||
		search(word, board, flag, matchLen+1, i, j+1)
	//这里把当前位的flag改回去，就可以完美复用flag了
	flag[i][j] = false
	return res
}
