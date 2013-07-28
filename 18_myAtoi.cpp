class Solution {
public:
	bool isNumericChar(char x)
	{
		return (x >= '0' && x <= '9')? true: false;
	}
	// A simple atoi() function. If the given string contains
	// any invalid character, then this function returns 0
	int atoi(const char *str)
	{
		const char *it = str;
		while (*it == ' '){
			it++;
		}
		if (*it == 0){
			return 0;
		}
		double res = 0;  // Initialize result
		int sign = 1;  // Initialize sign as positive
		if (*it == '+'){
			it ++;
		}
		// If number is negative, then update sign
		if (*it == '-')
		{
			sign = -1;
			it++;  // Also update index of first digit
		}
		// Iterate through all digits of input string and update result
		for (; *it != 0; ++it)
		{
			if (isNumericChar(*it) == false)
			return sign*res; // You may add some lines to write error message
			// to error stream
			
			res = res*10 + *it - '0';
			if (res > (double)0x7fffffff && sign == 1){
				return INT_MAX;
			}
			if (res > (double)0x80000000 && sign == -1){
				return INT_MIN;
			}
		}
		// Return result with sign
		return sign*res;
	}
};