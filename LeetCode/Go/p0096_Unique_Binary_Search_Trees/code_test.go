package p0096_Unique_Binary_Search_Trees

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestNumTrees(t *testing.T){
	assert.Equal(t,1, numTrees(0))
	assert.Equal(t,1,numTrees(1))
	assert.Equal(t,2,numTrees(2))
	assert.Equal(t,5,numTrees(3))
}
