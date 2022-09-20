#pragma once
#include <string>
#include <iostream>

void recursion(int i, std::string from, std::string to, std::string other) {
	if (i == 1) {
		std::cout << i << " " << from << " -> " << to << std::endl;
		return;
	}
	recursion(i - 1, from, other, to); // move 1-(i-1) from -> other
	std::cout << i << " " << from << " -> " << to << std::endl; // move i from -> to
	recursion(i - 1, other, to, from); // move 1-(i-1) other - > from
}

void hanoi() {
	int n = 4;
	recursion(n, "left", "right", "mid");
}