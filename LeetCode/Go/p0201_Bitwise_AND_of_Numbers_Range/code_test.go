package p0201_Bitwise_AND_of_Numbers_Range

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	assert.Equal(t, 4, rangeBitwiseAnd(5, 7))
}
