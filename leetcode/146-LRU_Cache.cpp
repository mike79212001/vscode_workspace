class CacheData {
public:
	int value;
	list<int>::iterator ptr;
	CacheData(): value(0), ptr(0) {}
	CacheData(int val, list<int>::iterator it): value(val), ptr(it) {}
};

class LRUCache {
public:
	LRUCache(int capacity) : _capacity(capacity) {}

	int get(int key) {
		if (_mappingTable.find(key) == _mappingTable.end()) {
			return -1;
		}
		touch(key);
		return _mappingTable[key].value;
	}

	void put(int key, int value) {
		if (_mappingTable.find(key) == _mappingTable.end()) {
			_recentlyUsedQueue.push_front(key);
			CacheData data(value, _recentlyUsedQueue.begin());
			_mappingTable.emplace(key, data);
		} else {
			_mappingTable[key].value = value;
			touch(key);
		}

		if (_recentlyUsedQueue.size() <= _capacity) {
			return;
		}

		int oldestKey = _recentlyUsedQueue.back();
		_recentlyUsedQueue.pop_back();
		_mappingTable.erase(oldestKey);
	}

	void touch(int key) {
		auto &it = _mappingTable[key];
		_recentlyUsedQueue.erase(it.ptr);
		_recentlyUsedQueue.push_front(key);
		it.ptr = _recentlyUsedQueue.begin();
	}

	int _capacity;
	unordered_map<int, CacheData> _mappingTable;
	list<int> _recentlyUsedQueue;
};
