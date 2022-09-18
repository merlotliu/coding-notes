#include "code01_find_median.hpp"

void findMedian() {
	for (int i = 0; i < 5; i++) {
		std::vector<int> arr = generateRandomArray(10, 100, 0);
		printArray(arr);
		Median median;
		for (auto num : arr) {
			median.insert(num);
		}
		std::cout << median.getMedian() << std::endl;
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	findMedian();

	return 0;
}