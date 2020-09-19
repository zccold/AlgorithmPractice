package p0146_LRU_Cache

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCode(t *testing.T) {
	//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
	//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
	//[null, null, null, 1, null, -1, null, -1, 3, 4]
	lru := Constructor(2)
	lru.Put(1, 1)
	t.Log(lru.m)
	lru.Put(2, 2)
	t.Log(lru.m)
	assert.Equal(t, 1, lru.Get(1))
	t.Log(lru.m)
	lru.Put(3, 3)
	t.Log(lru.m)
	assert.Equal(t, -1, lru.Get(2))
	t.Log(lru.m)
	lru.Put(4, 4)
	t.Log(lru.m)
	assert.Equal(t, -1, lru.Get(1))
	t.Log(lru.m)
	assert.Equal(t, 3, lru.Get(3))
	t.Log(lru.m)
	assert.Equal(t, 4, lru.Get(4))
	t.Log(lru.m)
}
