package p0374_Guess_Number_Higher_or_Lower

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

var guess func(num int) int

func buildGuess(pick int) {
	guess = func(num int) int {
		if num > pick {
			return -1
		}
		if num < pick {
			return 1
		}
		return 0
	}
}

func guessNumber(n int) int {
	i := 1
	j := n
	for i <= j {
		mid := (i + j) / 2
		g := guess(mid)
		if g == 0 {
			return mid
		} else if g == -1 {
			j = mid
		} else {
			i = mid + 1
		}
	}
	return 0
}
