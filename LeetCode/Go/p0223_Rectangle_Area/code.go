package p0223_Rectangle_Area

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	total := (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1)
	if ax2 <= bx1 || ay2 <= by1 || bx2 <= ax1 || by2 <= ay1 {
		return total
	}

	x1 := max(ax1, bx1)
	x2 := min(ax2, bx2)
	y1 := max(ay1, by1)
	y2 := min(ay2, by2)
	shit := (x2 - x1) * (y2 - y1)
	return total - shit
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
