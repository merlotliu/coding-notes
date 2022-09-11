#include <iostream>

#include "code01_selection_sort.hpp"
#include "code02_bubble_sort.hpp"
#include "code03_insertion_sort.hpp"
#include "code04_xor.hpp"
#include "code06_comparator.hpp"
#include "code07_recursion_master_get_max.hpp"
#include "code08_merge_sort.hpp"
#include "code09_netherland_flag.hpp"
#include "code10_quick_sort.hpp"
#include "code11_heap_sort.hpp"
#include "code12_comparator.hpp"
#include "code13_count_sort.hpp"
#include "code14_radix_sort.hpp"

/* 打印数组 */
void printArray(int *arr, int len) {
	if (arr == nullptr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

/* 对数器 */
void compare(ISort *isort, int positive_only = 0) {
	Comparator comparator;
	int test_times = 50000;
	int max_size = 100;
	int max_val = 100;
	bool succeed = true;
	for (int i = 0; i < test_times; i++) {
		int len = 0;
		int *arr1 = comparator.generateRandomArray(max_size, max_val, len, 0, positive_only);
		int *arr2 = comparator.copyArray(arr1, len);
		//printArray(arr1, len);
		isort->sort(arr1, len);
		comparator.sort(arr2, len);
		if (!comparator.isEqual(arr1, len, arr2, len)) {
			succeed = false;
			break;
		}
	}
	std::cout << (succeed ? "Nice!" : "Fucking fuck!" ) << std::endl;
	int len = 0;
	int *arr = comparator.generateRandomArray(max_size, max_val, len, 0, positive_only);
	printArray(arr, len);
	isort->sort(arr, len);
	printArray(arr, len);
}

/* 选择排序 */
void selectionSort(SelectionSort *selection) {
	compare(selection);
}

/* 冒泡排序 */
void bubbleSort(BubbleSort *bubble) {
	compare(bubble);
}

/* 插入排序 */
void insertionSort(InsertionSort *insertion) {
	compare(insertion);
}

/* 异或操作交换两数 */
void xorSwap() {
	int a = 111, b = 222;
	printf("a : %d, b : %d\n", a, b);
	XOR::swap(a, b);
	printf("a : %d, b : %d\n", a, b);
}

/* 奇数次出现数字 */
void oddTimesNum() {
	int arr1[] = { 1, 2, 3, 3, 2, 1, 4};
	int len = sizeof(arr1) / sizeof(int);
	printArray(arr1, len);
	std::cout << "One Odd Times Num : " << XOR::getOnlyOddTimesNum(arr1, len) << std::endl;

	int arr2[] = { 1, 2, 3, 3, 2, 1, 4, 5 };
	len = sizeof(arr2) / sizeof(int);
	printArray(arr2, len);
	std::vector<int> res = XOR::getTwoOddTimesNum(arr2, len);
	std::cout << "Two Odd Times Num : " << res[0] << ", " << res[1] << std::endl;
}

/* 归并排序 */
void mergeSort(MergeSort *merge) {
	compare(merge);
}

/* 小和问题 */
void smallSum(MergeSort *merge) {
	int arr[] = { 1, 3, 4, 2, 5 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	std::cout << "Small Sum : " << merge->getSmallSum(arr, 0, len - 1) << std::endl;
}

/* 荷兰国旗问题 */
void netherlandFlag() {
	int arr[] = {4, 5, 6, 5, 3, 2, 8, 7};
	int len = sizeof(arr) / sizeof(int);
	int num = 5;

	std::cout << "Origin Array:" << std::endl;
	printArray(arr, len);
	
	NetherlandFlag::easyNetherlandFlag(num, arr, len);
	std::cout << "Easy Netherland Flag:" << std::endl;
	printArray(arr, len);

	NetherlandFlag::netherlandFlag(num, arr, len);
	std::cout << "Netherland Flag:" << std::endl;
	printArray(arr, len);
}

/* 快排 */
void quickSort(QuickSort *quick) {
	/*int arr[] = {43, 3, 6, 61, 13};
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	quick->sort(arr, len);
	printArray(arr, len);*/

	compare(quick);
}

/* 堆排（希尔排序） */
void heapSort(HeapSort *heap) {
	compare(heap);
}

/* 比较器 */
void comparator() {
	int len = 0;

	std::cout << "number:" << std::endl;
	int *arr = Comparator::generateRandomArray(10, 100, len, 6);
	std::cout << "origin:" << std::endl;
	printArray(arr, len);

	std::cout << "ascending order:" << std::endl;
	Comp::sortByAscendingOrder(arr, len);
	printArray(arr, len);
	
	std::cout << "descending order:" << std::endl;
	Comp::sortByDescendingOrder(arr, len);
	printArray(arr, len);

	std::cout << "Student（class）:" << std::endl;
	len = 4;
	Student *stus = new Student[len];
	stus[0].set("D", 004, 18);
	stus[1].set("A", 001, 18);
	stus[2].set("B", 002, 16);
	stus[3].set("C", 003, 19);

	std::cout << "Age Ascending Order:" << std::endl;
	Comp::studentSortByAgeAscendingOrder(stus, len);
	Comp::printStudents(stus, len);
}

/* 计数排序 */
void countSort(CountSort *count_sort) {
	int arr[] = {23, 12, 9, 66, 54, 32};
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	count_sort->sort(arr, len);
	printArray(arr, len);

	compare(count_sort, 1);
}

/* 基数排序 */
void radixSort(RadixSort *radix_sort) {
	int arr[] = {13, 100, 24, 54, 82, 53};
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	radix_sort->sort(arr, len);
	printArray(arr, len);

	compare(radix_sort, 1);
}

int main(int argc, char *argv[]) {
	// selection sort
	//SelectionSort *selection_sort = new SelectionSort;
	//selectionSort(selection_sort);

	// bubble sort
	//BubbleSort *bubble_sort = new BubbleSort;
	//bubbleSort(bubble_sort);

	// insertion sort
	//InsertionSort *insertion_sort = new InsertionSort;
	//insertionSort(insertion_sort);

	// xor swap
	//xorSwap();

	// odd times number
	//oddTimesNum();

	// merge sort
	//MergeSort *merge_sort = new MergeSort;
	//mergeSort(merge_sort);

	// small sum
	//smallSum(merge_sort);

	// Netherland Flag
	//netherlandFlag();

	// quick sort
	//QuickSort *quick_sort = new QuickSort;
	//quickSort(quick_sort);

	// heap sort
	//HeapSort *heap_sort = new HeapSort;
	//heapSort(heap_sort);

	// comparator
	//comparator();

	// count sort
	//CountSort *count_sort = new CountSort;
	//countSort(count_sort);
	
	// radix sort
	/*RadixSort *radix_sort = new RadixSort;
	radixSort(radix_sort);*/

	return 0;
}