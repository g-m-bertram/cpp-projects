// quickSort program for vectors of integers
// time complexity:
//		O(n log n) in best case
//		O(n^2) in worst case

#include<iostream>
#include<vector>

void print(const std::vector<int>& v);
void quickSort(std::vector<int>& v, int start, int end);
static int partition(std::vector<int>& v, int start, int end);


int main() {
	std::vector<int> v;
	for (int i = 0; i < 20; ++i) {
		v.push_back(rand() % 1000);
	}
	print(v);
	std::cout << "sorting...\n";
	quickSort(v, 0, v.size() - 1);
	print(v);
}


void print(const std::vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

void quickSort(std::vector<int>& v, int start, int end) {
	// check if bounds are appropriate
	if (start < end) {
		int pivot = partition(v, start, end);

		// perform quickSort on both sides of pivot
		quickSort(v, start, pivot - 1);
		quickSort(v, pivot, end);
	}
}

int partition(std::vector<int>& v, int start, int end) {
	int pivot = start + (end - start) / 2;
	int pivotVal = v[pivot];

	int i = start, j = end, temp;
	while (i <= j) {
		while (v[i] < pivotVal) {
			i++;
		}

		while (v[j] > pivotVal) {
			j--;
		}

		// swap
		if (i <= j) {
			temp = v[i];
			v[i++] = v[j];
			v[j--] = temp;
		}
	}
	// i becomes new bound for next iteration
	return i;
}