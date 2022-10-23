#include <vector>
#include <stack>
#include <iostream>

// #include "dailyTemperatures.h"
// #include "nextGreaterElements2.h"
#include "trap.h"

using namespace std;


void printArr(vector<int> &arr) {
	for (auto elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}

int main() {
	vector<int> temperatures = { 73,74,75,71,69,72,76,73 };

	Solution s;
	// vector<int> arr = s.dailyTemperatures(temperatures);
	// printArr(arr);

	// vector<int> nums = { 1,2,1 };
	// vector<int> arr = s.nextGreaterElements(nums);
	// printArr(arr);

	//vector<int> height = { 4,2,0,3,2,5 };
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << s.trap(height);

}