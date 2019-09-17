package p0013_Roman_to_Integer

func romanToInt(s string) int {
	m := make(map[byte]int)
	m['I'] = 1
	m['V'] = 5
	m['X'] = 10
	m['L'] = 50
	m['C'] = 100
	m['D'] = 500
	m['M'] = 1000
	v := m[s[0]]
	for i := 1; i < len(s); i++ {
		if m[s[i]] > m[s[i-1]] {
			v = v + m[s[i]] - 2*m[s[i-1]]
		} else {
			v = v + m[s[i]]
		}
	}
	return v
}
