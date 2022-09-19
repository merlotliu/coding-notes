#pragma once
#include <vector>

void backtrack(std::vector<int> &weights, std::vector<int> &values, int bag, int i, int picked_weights, int picked_values) {
	if (picked_weights > bag || i >= weights.size()) {
		return ;
	}
	// picked
	backtrack(weights, values, bag, i + 1, picked_weights + weights[i], picked_values + values[i]);
	
	// not picked
	backtrack(weights, values, bag, i + 1, picked_weights, picked_values);
}

//std::vector<int> weights = { 2, 4, 5, 8, 10 };
//std::vector<int> values = { 4, 2, 1, 4, 3 };
int getMaxVal(std::vector<int> &weights, std::vector<int> &values, int bag) {
	return backtrack(weights, values, bag, 0, 0);
}