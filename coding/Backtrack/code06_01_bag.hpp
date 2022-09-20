#pragma once
#include <vector>
#include <algorithm>

int backtrack(std::vector<int> &weights, std::vector<int> &values, int bag, int i, int picked_weights, int picked_values) {
	if (picked_weights > bag) {
		return 0;
	}
	if(i == weights.size()) {
		return picked_values;
	}
	int unpicked = backtrack(weights, values, bag, i + 1, picked_weights, picked_values);
	int picked = backtrack(weights, values, bag, i + 1, picked_weights + weights[i], picked_values + values[i]);
	return std::max(unpicked, picked);
}

//std::vector<int> weights = { 2, 4, 5, 8, 10 };
//std::vector<int> values = { 4, 2, 1, 4, 3 };
int getMaxVal(std::vector<int> &weights, std::vector<int> &values, int bag) {
	return backtrack(weights, values, bag, 0, 0, 0);
}