package p0729_My_Calendar

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMyCalendar_Book(t *testing.T) {
	c := Constructor()
	type s struct {
		start int
		end   int
		flag  bool
	}
	x := []s{
		{20, 29, true},
		{13, 22, false},
		{44, 50, true},
		{1, 7, true},
		{2, 10, false},
		{14, 20, true},
		{19, 25, false},
		{36, 42, true},
	}
	for i, s := range x {
		flag := c.Book(s.start, s.end)
		assert.Equal(t, s.flag, flag, fmt.Sprintf("index %d, s %+v", i, s))
	}
	p := c.head
	for p != nil {
		fmt.Println(p.start, p.end)
		p = p.next
	}
}
