public static char[] removeDuplicates(char[] str) {
	if (str == null) return str;
	int len = str.length;
	if (len < 2) return str;
	int tail = 1;
	for (int i = 1; i < len; ++i) {
		int j;
		for (j = 0; j < tail; ++j) {
			if (str[i] == str[j]) break;
		}
		if (j == tail) {
			str[tail] = str[i];
			++tail;
		}	
	}
	str[tail] = 0;
	
	return str;
}