class IslandUnion {
public:
	IslandUnion(int size) {
		_totalGroup = 0;
		_records = new int[size]();
		memset(_records, -1, size*sizeof(int));
	};

	void mark(int index) {
		_records[index] = index;
		_totalGroup++;
	}

	int find(int index) {
		if (_records[index] == index) {
			return index;
		} else {
			_records[index] = find(_records[index]); // accelerate ???
			return _records[index];
		}
	}

	void makeUnion(int xIndex, int yIndex) {
		int x = find(xIndex);
		int y = find(yIndex);

		if (x == y) {
			return;
		}
		_records[x] = y;
		_totalGroup--;
	}

	int getTotalGroup() {
		return _totalGroup;
	}

private:
	int _totalGroup;
	int* _records;
};


class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		IslandUnion islands(m*n);
		vector<int> ret;
		pair<int, int> director[4] = {	make_pair(0, -1), make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1) };

		bool **board = new bool*[m]();
		for (int i = 0; i < m; ++i) {
			board[i] = new bool[n]();
		}

		int size = positions.size();
		if (0 == size) {
			return ret;
		}

		for (int i = 0; i < size; ++i) {
			pair<int, int> &it = positions[i];
			int position = it.first * n + it.second;

			// mark current position
			islands.mark(position);
			board[it.first][it.second] = true;

			// union position
			for (int i = 0; i < 4; ++i) {
				int xPos = it.first + director[i].first;
				int yPos = it.second + director[i].second;
				if (xPos >= 0 && xPos < m && yPos >= 0 && yPos < n && true == board[xPos][yPos]) {
					islands.makeUnion(position, xPos * n + yPos);
				}
			}
			ret.push_back(islands.getTotalGroup());
		}
		return ret;
	}

};