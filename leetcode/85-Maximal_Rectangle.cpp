class Solution {

	struct Node {
		int verticalCheck;
		int horizonCheck;
		Node() : verticalCheck(0), horizonCheck(0) {}
	};

public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) {
			return 0;
		}

		vector<vector<Node>> board(matrix.size(), vector<Node>(matrix[0].size()));
		int maxArea = 0;

		vector<int> hList(matrix[0].size());
		int vList = 0;
		for (int i = matrix.size() - 1; i >= 0 ; --i) {
			for (int j = matrix[0].size() - 1; j >= 0 ; --j) {
				if (matrix[i][j] == '0') {
					hList[j] = 0;
					vList = 0;
					continue;
				}
				board[i][j].verticalCheck = ++hList[j];
				board[i][j].horizonCheck = ++vList;
			}
			vList = 0;
		}

		cout << "=======" << endl;
		for (auto row : board) {
			for (auto col : row) {
				cout << col.verticalCheck;
			}
			cout << endl;
		}
		cout << "=======" << endl;
		for (auto row : board) {
			for (auto col : row) {
				cout << col.horizonCheck;
			}
			cout << endl;
		}
        cout << "=======" << endl;

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				Node &node = board[i][j];
				cout << i << ":" << j << "==> ";

				if (maxArea < (node.verticalCheck * node.horizonCheck)) {
					cout << "in" << endl;
					if (node.verticalCheck == 1 || node.horizonCheck == 1) {
						maxArea = max(maxArea, node.verticalCheck * node.horizonCheck);
						cout << endl;
						continue;
					}

					int check = node.horizonCheck;
					for (int index = 0; index < node.verticalCheck; ++index) {
						check = min(check, board[i + index][j].horizonCheck);
						maxArea = max(maxArea, check * (index + 1));
					}

					check = node.verticalCheck;
					for (int index = 0; index < node.horizonCheck; ++index) {
						check = min(check, board[i][j + index].verticalCheck);
						maxArea = max(maxArea, check * (index + 1));
					}
				}
				cout << maxArea << endl;
			}
		}

		return maxArea;

	}
};
