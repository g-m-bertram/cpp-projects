// algorithm practice: mergeSort program for vectors of integers


#include<iostream>
#include<vector>

void print(const std::vector<int>& v);
void mergeSort(std::vector<int>& v, int start, int end);
void merge(std::vector<int>& v, int start, int middle, int end);


int main() {
	std::vector<int> v;
	for (int i = 0; i < 20; ++i) {
		v.push_back(rand() % 1000);
	}
	print(v);
	std::cout << "sorting...\n";
	mergeSort(v, 0, v.size() - 1);
	print(v);
}


void print(const std::vector<int>& v) {
	for (int num : v) {
		std::cout << num << " ";
	}
	std::cout << "\n";
}

void mergeSort(std::vector<int>& v, int start, int end) {
	// check for valid bounds
	if (start < end) {
		int middle = (start + end) / 2;

		// sort halves
		mergeSort(v, start, middle);
		mergeSort(v, middle + 1, end);

		// merge halves
		merge(v, start, middle, end);
	}
}

void merge(std::vector<int>& v, int start, int middle, int end) {
	// create two vectors to be compared and merged
	std::vector<int> left(middle - start + 1);
	std::vector<int> right(end - middle);

	// populate left and right with appropriate values
	for (int i = 0; i < left.size(); ++i) {
		left[i] = v[start + i];
	}
	for (int i = 0; i < right.size(); ++i) {
		right[i] = v[middle + 1 + i];
	}

	// indices l and r for left vector and right vector, respectively
	// curr refers to the index of the main / resultant vector
	int l = 0, r = 0, curr = start;

	// compare values of left and right vectors, smaller value goes into resultant vector first
	while (l < left.size() && r < right.size()) {
		if (left[l] <= right[r]) {
			v[curr] = left[l++];
		}
		else {
			v[curr] = right[r++];
		}
		curr++;
	}

	// deal with any remainders
	while (l < left.size()) {
		v[curr++] = left[l++];
	}

	while (r < right.size()) {
		v[curr++] = right[r++];
	}
}
