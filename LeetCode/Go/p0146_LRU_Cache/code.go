package p0146_LRU_Cache

import "container/list"

type LRUCache struct {
	cap  int
	list *list.List
	m    map[int]*list.Element
}

type eStruct struct {
	key   int
	value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cap:  capacity,
		list: list.New(),
		m:    make(map[int]*list.Element),
	}
}

func (this *LRUCache) Get(key int) int {
	if e, ok := this.m[key]; ok {
		this.list.MoveToFront(e)
		return e.Value.(eStruct).value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if oldE, ok := this.m[key]; ok {
		oldE.Value = eStruct{
			key:   key,
			value: value,
		}
		this.list.MoveToFront(oldE)
	} else {
		e := this.list.PushFront(eStruct{
			key:   key,
			value: value,
		})
		this.m[key] = e
		if this.list.Len() > this.cap {
			lastE := this.list.Back()
			this.list.Remove(lastE)
			//写到这突然脑子短路，发现不知道怎么能知道要删谁，于是搞了个sb的struct当value
			delete(this.m, lastE.Value.(eStruct).key)
		}
	}
}
