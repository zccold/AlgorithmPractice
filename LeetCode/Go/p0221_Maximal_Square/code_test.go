package p0221_Maximal_Square

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
*/

func TestCode(t *testing.T) {
	assert.Equal(t, 4, maximalSquare([][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}))
}
