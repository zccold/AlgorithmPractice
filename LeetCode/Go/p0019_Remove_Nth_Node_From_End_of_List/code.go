package p0019_Remove_Nth_Node_From_End_of_List

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	fast := head
	slow := head
	//向后n-1次，如果直接动n次可能会越界，当要去掉的节点是head时
	for i := 1; i < n; i++ {
		fast = fast.Next
	}
	if fast.Next == nil {
		return head.Next
	}
	for {
		fast = fast.Next
		//fast为最后一个时，需要删除slow的下一个节点
		if fast.Next == nil {
			slow.Next = slow.Next.Next
			return head
		}
		slow = slow.Next
	}
}
