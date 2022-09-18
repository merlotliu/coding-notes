#include <iostream>
#include <time.h>

#include "code01_meeting_arrange.hpp"

void meetingArrange() {
	for (int i = 0; i < 1; i++) {
		std::vector<std::vector<int>> arr = generateRandomArray(10, 10, 1);
		std::cout << getMaxArrangeMeetingCount(arr) << std::endl;
	}
}

int main(int argc, char *agrv) {
	srand((unsigned int)time(NULL));
	// 
	meetingArrange();

	return 0;
}