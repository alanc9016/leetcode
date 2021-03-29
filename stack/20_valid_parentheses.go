func isValid(s string) bool {
	var stack []rune
	myMap := map[rune]rune{
		'{': '}',
		'(': ')',
		'[': ']',
	}

	for _, char := range s {
		if val, ok := myMap[char]; ok {
			stack = append(stack, char)
		} else {
			if len(stack) == 0 {
				return false
			} else {
				val = stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				if myMap[val] != char {
					return false
				}
			}
		}
	}

	return len(stack) == 0
}
