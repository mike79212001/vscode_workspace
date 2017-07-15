#define PARENTHESES_PATTERN "(R)R"
#define EMPTY_PARENTHESES_PATTERN "()"
#define PARENTHESES_TOKEN "R"
#define NULL_PATTERN ""

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		findPattern(PARENTHESES_TOKEN, n);
		return _result;
	}

	void findPattern(string pattern, int leftParentheses) {
		cout << leftParentheses << ": " << pattern << endl;
		if (leftParentheses == 1) {
			int index = 0;
			while(string::npos != (index = pattern.find(PARENTHESES_TOKEN))) {
				string temp = pattern;
				temp.replace(index, 1, EMPTY_PARENTHESES_PATTERN);
				removeAllToken(temp, PARENTHESES_TOKEN);
				cout << "ans: " << temp << endl;
				_result.push_back(temp);
				pattern.replace(index, 1, NULL_PATTERN);
			}
			return;
		}

		int index = pattern.find(PARENTHESES_TOKEN);
		if (index != string::npos) {
			string temp = pattern;
			temp.replace(index, 1, PARENTHESES_PATTERN);
			findPattern(temp, leftParentheses-1);
			pattern.replace(index, 1, NULL_PATTERN);
			findPattern(pattern, leftParentheses);
		}
	}

	void removeAllToken(string &inputStr, const string &token) {
		int index = 0;
		while(string::npos != (index = inputStr.find(token))) {
			inputStr.erase(index, 1);
		}
	}

	vector<string> _result;
};