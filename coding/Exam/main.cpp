#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

int getRecordLimit(int N, int total, std::vector<int> &records) {
	std::sort(records.begin(), records.end());
	int avg = total / N;
	int sum = 0;
	int limit = -1;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (flag && sum + records[i] > (i + 1) * avg) {
			limit = (total - sum) / (N - i);
			flag = false;
		}
		sum += records[i];
	}
	if (sum <= total) return -1;
	std::cout << limit << std::endl;
	sum = 0;
	flag = true;
	for (int i = 0; i < N; i++) {
		if (flag && (sum + records[i]) > (i + 1) * (avg + 1)) {
			limit = (total - sum) / (N - i);
			flag = false;
		}
		sum += records[i];
	}
	std::cout << limit << std::endl;
	/*while (1) {
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (records[i] > limit) {
				sum += limit * (N - i);
				break;
			}
			else {
				sum += records[i];
			}
		}
		if (sum > total) {
			return limit - 1;
		}
		limit++;
	}*/
	return limit;
}

int force(int N, int total, std::vector<int> &records) {
	std::sort(records.begin(), records.end());
	int sum = 0;
	for (auto num : records) {
		sum += num;
	}
	if (sum <= total) return -1;
	int limit = total / N;

	while (1) {
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (records[i] > limit) {
				sum += limit * (N - i);
				break;
			}
			else {
				sum += records[i];
			}
		}
		if (sum > total) {
			return limit - 1;
		}
		limit++;
	}
}
using namespace std;

class Solution {
	vector<string> res;
public:
	vector<string> getMinDictSort(vector<string> &other) {
		if (res.empty()) return other;
		int i = 0;
		while (i < other.size() && other[i] == res[i]) i++;
		return i == other.size() ? res : other[i] < res[i] ? other : res;
	}

	void backtrack(vector<vector<string>>& tickets, string last, vector<string>& picked, vector<bool>& memo) {
		if (picked.size() == tickets.size()) {
			picked.push_back(last);
			res = getMinDictSort(picked);
			picked.pop_back();
			return;
		}
		//["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
		for (int i = 0; i < tickets.size(); i++) {
			if (picked.empty() && "JFK" != tickets[i][0]) {
				continue;
			}
			if (memo[i]) {
				continue;
			}
			if (last == tickets[i][0]) {
				memo[i] = true;
				picked.push_back(tickets[i][0]);
				backtrack(tickets, tickets[i][1], picked, memo);
				picked.pop_back();
				memo[i] = false;
			}
		}
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<bool> memo(tickets.size(), false);
		vector<string> picked;
		backtrack(tickets, "JFK", picked, memo);
		return res;
	}
};

int main() {
	vector<vector<string>> tickets = { {"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"} };
	Solution s;
	vector<string> res = s.findItinerary(tickets);
	for (auto str : res) {
		cout << str << endl;
	}
	//int n = 100;
	//while(n--) {
	//	int N = rand() % 99999 + 1;
	//	
	//	std::vector<int> records;
	//	for (int i = 0; i < N; i++) {
	//		records.push_back(rand() % 100000);
	//	}
	//	//std::vector<int> records = {3, 3, 8, 7, 10, 10};
	//	//std::vector<int> records = { 3, 3, 5, 7, 9 };
	//	int total = rand() % 999999999 + 1;
	//	std::cout << N << " " << total << std::endl;
	//	getRecordLimit(N, total, records);
	//	std::cout << force(N, total, records) << std::endl;
	//	/*if (getRecordLimit(N, total, records) != force(N, total, records)) {
	//		std::cout << "False!" << std::endl;
	//		return -1;
	//	}*/	
	//}
	return 0;
}