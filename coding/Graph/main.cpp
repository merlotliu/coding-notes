#include "code07_arrange_journey.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	//vector<vector<string>> tickets = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
	//vector<vector<string>> tickets = { {"EZE", "AXA"}, { "TIA","ANU" }, { "ANU","JFK" }, { "JFK","ANU" }, { "ANU","EZE" }, { "TIA","ANU" }, { "AXA","TIA" }, { "TIA","JFK" }, { "ANU","TIA" }, { "JFK","TIA" }};
	vector<vector<string>> tickets = { {"AXA", "EZE"}, { "EZE","AUA" }, { "ADL","JFK" }, { "ADL","TIA" }, { "AUA","AXA" }, { "EZE","TIA" }, { "EZE","TIA" }, { "AXA","EZE" }, { "EZE","ADL" }, { "ANU","EZE" }, { "TIA","EZE" }, { "JFK","ADL" }, { "AUA","JFK" }, { "JFK","EZE" }, { "EZE","ANU" }, { "ADL","AUA" }, { "ANU","AXA" }, { "AXA","ADL" }, { "AUA","JFK" }, { "EZE","ADL" }, { "ANU","TIA" }, { "AUA","JFK" }, { "TIA","JFK" }, { "EZE","AUA" }, { "AXA","EZE" }, { "AUA","ANU" }, { "ADL","AXA" }, { "EZE","ADL" }, { "AUA","ANU" }, { "AXA","EZE" }, { "TIA","AUA" }, { "AXA","EZE" }, { "AUA","SYD" }, { "ADL","JFK" }, { "EZE","AUA" }, { "ADL","ANU" }, { "AUA","TIA" }, { "ADL","EZE" }, { "TIA","JFK" }, { "AXA","ANU" }, { "JFK","AXA" }, { "JFK","ADL" }, { "ADL","EZE" }, { "AXA","TIA" }, { "JFK","AUA" }, { "ADL","EZE" }, { "JFK","ADL" }, { "ADL","AXA" }, { "TIA","AUA" }, { "AXA","JFK" }, { "ADL","AUA" }, { "TIA","JFK" }, { "JFK","ADL" }, { "JFK","ADL" }, { "ANU","AXA" }, { "TIA","AXA" }, { "EZE","JFK" }, { "EZE","AXA" }, { "ADL","TIA" }, { "JFK","AUA" }, { "TIA","EZE" }, { "EZE","ADL" }, { "JFK","ANU" }, { "TIA","AUA" }, { "EZE","ADL" }, { "ADL","JFK" }, { "ANU","AXA" }, { "AUA","AXA" }, { "ANU","EZE" }, { "ADL","AXA" }, { "ANU","AXA" }, { "TIA","ADL" }, { "JFK","ADL" }, { "JFK","TIA" }, { "AUA","ADL" }, { "AUA","TIA" }, { "TIA","JFK" }, { "EZE","JFK" }, { "AUA","ADL" }, { "ADL","AUA" }, { "EZE","ANU" }, { "ADL","ANU" }, { "AUA","AXA" }, { "AXA","TIA" }, { "AXA","TIA" }, { "ADL","AXA" }, { "EZE","AXA" }, { "AXA","JFK" }, { "JFK","AUA" }, { "ANU","ADL" }, { "AXA","TIA" }, { "ANU","AUA" }, { "JFK","EZE" }, { "AXA","ADL" }, { "TIA","EZE" }, { "JFK","AXA" }, { "AXA","ADL" }, { "EZE","AUA" }, { "AXA","ANU" }, { "ADL","EZE" }, { "AUA","EZE" }};
	Solution s;
	vector<string> res = s.findItinerary(tickets);
	for (auto str : res) {
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return 0;
}