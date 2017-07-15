class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0) {
			return 0;
		}

		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < 10; ++i) {
			dp[i] = 10 * dp[i-1] + pow(10, i-1);
		}

		int length = to_string(n).size();
		return findTotalOne(length, n);
	}

	int findTotalOne(int length, int number) {
		if (1 == length) {
			return (1 <= number) ? 1 : 0;
		}

		int divider = pow(10, length-1);
		int firstNumber = number / divider;
		int totalOneCount = firstNumber * dp[length-1];

		if (1 == firstNumber) {
			totalOneCount += ((number % divider) + 1);
		} else if (1 < firstNumber) {
			totalOneCount += divider;
		}

		return totalOneCount + findTotalOne(length-1, number % divider);
	}

	int dp[11];
};