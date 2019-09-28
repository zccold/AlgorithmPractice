package p0021_Merge_Two_Sorted_Lists

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	//这样初始化res的时候（取第一个点），就不用处理直接是nil了，非常舒适
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var res *ListNode
	if l1.Val < l2.Val {
		res = l1
		l1 = l1.Next
	} else {
		res = l2
		l2 = l2.Next
	}
	p := res
	for {
		if l1 == nil && l2 == nil {
			return res
		} else if l1 == nil { //下边这两个情况，虽然用原链表的数据不好，但是反正leetcode也不会管的，不想用就照常处理就好了
			p.Next = l2
			return res
		} else if l2 == nil {
			p.Next = l1
			return res
		} else if l1.Val < l2.Val {
			p.Next = &ListNode{Val: l1.Val}
			p = p.Next
			l1 = l1.Next
		} else {
			p.Next = &ListNode{Val: l2.Val}
			p = p.Next
			l2 = l2.Next
		}
	}
}
