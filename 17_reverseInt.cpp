class Solution {
public:
	int reverse(int x) {
		int positive = 1;
		if (x < 0){
			positive = -1;
			x = -x;
		}
		int y = 0;
		
		while (x > 0){
			y = y * 10 + x %10;
			x = x/10;
		}
		return positive * y;
		
	}
};