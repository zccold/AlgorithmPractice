package p0079_Word_Search

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	board := [][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}
	assert.Equal(t, true, exist(board, "ABCCED"))
	assert.Equal(t, true, exist(board, "SEE"))
	assert.Equal(t, false, exist(board, "ABCB"))
}
