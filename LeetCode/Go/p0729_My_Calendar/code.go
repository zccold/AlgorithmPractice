package p0729_My_Calendar

type MyCalendar struct {
	head *shit
}

type shit struct {
	start int
	end   int
	next  *shit
}

func Constructor() MyCalendar {
	return MyCalendar{}
}

func (c *MyCalendar) Book(start int, end int) bool {
	if c.head == nil {
		c.head = &shit{
			start: start,
			end:   end,
			next:  nil,
		}
		return true
	}
	if c.head.start > start {
		if c.head.start < end {
			return false
		}
		node := &shit{
			start: start,
			end:   end,
			next:  c.head,
		}
		c.head = node
		return true
	}

	p := c.head
	var tail *shit
	for p != nil {
		if p.start <= start && p.next != nil && p.next.start > start {
			if start < p.end {
				return false
			}

			if p.next.start < end {
				return false
			}
			node := &shit{
				start: start,
				end:   end,
				next:  p.next,
			}
			p.next = node
			return true
		} else {
			if p.next == nil {
				tail = p
			}
			p = p.next
		}
	}

	if tail.end > start {
		return false
	}
	tail.next = &shit{
		start: start,
		end:   end,
		next:  nil,
	}
	return true
}
