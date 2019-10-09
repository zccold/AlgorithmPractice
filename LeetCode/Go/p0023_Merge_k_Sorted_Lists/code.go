package p0023_Merge_k_Sorted_Lists

import (
	"container/heap"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type NodeWrapper struct {
	Val    int
	source int //来源于哪个下标的lists
}

//先下面5个方法实现了heap的接口，要注意这里的push和pop是给接口调用的，自己不要用
//用这样结构可以使时间复杂度降低到nlogm，n是节点总量，m是lists个数
type NodeHeap []NodeWrapper

func (h NodeHeap) Len() int            { return len(h) }
func (h NodeHeap) Less(i, j int) bool  { return h[i].Val < h[j].Val }
func (h NodeHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *NodeHeap) Push(x interface{}) { *h = append(*h, x.(NodeWrapper)) }
func (h *NodeHeap) Pop() interface{} {
	x := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return x
}

func mergeKLists(lists []*ListNode) *ListNode {
	h := &NodeHeap{}
	//每个list的首项加入heap
	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			heap.Push(h, NodeWrapper{Val: lists[i].Val, source: i})
			lists[i] = lists[i].Next
		}
	}
	//为了好写，res先弄了个空节点，最后要返回他的next
	res := &ListNode{}
	p := res
	for h.Len() > 0 {
		node := heap.Pop(h).(NodeWrapper)
		p.Next = &ListNode{Val: node.Val}
		p = p.Next
		//如果pop出的节点，来源处仍有下一个节点，那么把它加入heap中
		if lists[node.source] != nil {
			heap.Push(h, NodeWrapper{Val: lists[node.source].Val, source: node.source})
			lists[node.source] = lists[node.source].Next
		}
	}
	return res.Next
}
