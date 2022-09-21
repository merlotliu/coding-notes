#include "code07_arrange_journey.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	vector<vector<string>> tickets = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
	Solution s;
	vector<string> res = s.findItinerary(tickets);
	for (auto str : res) {
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return 0;
}