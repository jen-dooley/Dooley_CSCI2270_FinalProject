#include <chrono>
using namespace std;

struct DataPoint{
	int data;
	DataPoint *next;
};

struct treeNode{
	int data;
	DataPoint *left;
	DataPoint *right;
	DataPoint *parent;
};

class SortingAlgorithms{
public:
	SortingAlgorithms();
	~SortingAlgorithms();

	milliseconds insertion();
		//moves each element to its correct location in the array
		//removes the current element then moves other elements out of the way
		//then insurts the removed element to the correct location.
	milliseconds selection();
		//much like insertion sort except it identifies the minimum value first
		//then removes the value and places it in the correct location.
	milliseconds merge();
		//A recursive sorting algorithm
		//Merge sort creates n (inputSize) lists and combines two lists in order by
		//comparing each element to the next
		//this continues until all sublists are contained into one list
	milliseconds heap();
		//A recursive sorting algorithm
		//Heap sort stores all data from an array into a binary heap structure,
		//it then removed the maximum value from the heap,
		//builds the sorted list from back to front.
	milliseconds quick(int array[], int left, int right);
		//A recursive sorting algorithm
		//picks a pivot point in the middle of the array, then divides into 2 subarrays
		//sorts so that values greater than the pivot are on the right and less than are on the left
		//then recursively repeats this process on each subarray.
	milliseconds bubble();
		//Bubble sort is one of the slowest sorts, 
		//it iterates through the list, compares and swaps consecutive elements
		//which moves the next lowest number in the array to the front.
	milliseconds tree();
		//Tree sort places all items into a binary tree then does a 
		//in-order traversal and saves these values 
		//Considered one of the fastest sorts

	void compareSorts();
private:
	vector origional<int>;
	int inputSize;

	void heapShiftDown(int heap[], int i, int max);
	void heapToHeap(int array[]);

	void treeAddNode(int data);
	void treeTraverse(treeNode *node);
};