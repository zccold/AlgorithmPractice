package p0207_Course_Schedule

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	//assert.Equal(t, true, canFinish(2, [][]int{{1, 0}}))
	//assert.Equal(t, false, canFinish(2, [][]int{{1, 0}, {0, 1}}))
	assert.Equal(t, true, canFinish(3, [][]int{{1, 0}, {2, 1}}))
}
