class Solution {
public:
	vector<string> wordsAbbreviation(vector<string>& dict) {
		int size = dict.size();
		if (0 == size) {
			return dict;
		}

		// copy vector string
		copyDict = dict;

		for (int i = 0; i < size; ++i) {
			int prefix = 1;
			string abbr = wordAbbre(i, prefix);

			while(true) {
				auto it = abbrMap.find(abbr);

				if (it == abbrMap.end()) {
					abbrMap.emplace(abbr, i);
					dict[i] = abbr;
					break;
				}

				int sameStrIndex = it->second;
				if (-1 == sameStrIndex) {
					abbr = wordAbbre(i, ++prefix);
					continue;
				}

				// find same abbr string
				abbrMap[abbr] = -1;
				while(true) {
					++prefix;
					string token1 = wordAbbre(i, prefix);
					string token2 = wordAbbre(sameStrIndex, prefix);

					if (token1 == token2) {
						abbrMap.emplace(token1, -1);
						continue;
					}

					abbrMap.emplace(token1, i);
					dict[i] = token1;
					abbrMap.emplace(token2, sameStrIndex);
					dict[sameStrIndex] = token2;
					break;
				}
				break;
			}
		}

		return dict;
	}

	string wordAbbre(int index, int wordPrefix) {
		string &str = copyDict[index];
		int middleLength = str.length() - wordPrefix - 1;

		if (1 >= middleLength) {
			return str;
		}
		return str.substr(0, wordPrefix) + to_string(middleLength) + str.back();
	};

	map<string, int> abbrMap;
	vector<string> copyDict;
};