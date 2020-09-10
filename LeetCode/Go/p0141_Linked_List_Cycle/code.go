package p0141_Linked_List_Cycle

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	p1 := head
	p2 := head
	for {
		if p2.Next != nil && p2.Next.Next != nil {
			p2 = p2.Next.Next
			p1 = p1.Next
			if p1 == p2 {
				return true
			}
		} else {
			return false
		}
	}
}
