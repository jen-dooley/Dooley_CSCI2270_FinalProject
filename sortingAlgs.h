#include <vector>
using namespace std;

//Struct used to create the tree in Tree Sort
struct treeNode{
	int data;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
};

class SortingAlgorithms{
public:
	SortingAlgorithms();
		//Basic constructor, this calls getInput()
	~SortingAlgorithms();
		//Basic destructor

	void getInput();
		//Asks user for input

	void insertion();
		//moves each element to its correct location in the array
		//removes the current element then moves other elements out of the way
		//then insurts the removed element to the correct location.
	void selection();
		//much like insertion sort except it identifies the minimum value first
		//then removes the value and places it in the correct location.
	void merge();
		//A recursive sorting algorithm
		//Merge sort creates n (inputSize) lists and combines two lists in order by
		//comparing each element to the next
		//this continues until all sublists are contained into one list
		// !!This function left empty for contribution!!
	void heap();
		//A recursive sorting algorithm
		//Heap sort stores all data from an array into a binary heap structure,
		//it then removed the maximum value from the heap,
		//builds the sorted list from back to front.
	void quickCall();
		//A recursive sorting algorithm
		//picks a pivot point in the middle of the array, then divides into 2 subarrays
		//sorts so that values greater than the pivot are on the right and less than are on the left
		//then recursively repeats this process on each subarray.
	void bubble();
		//Bubble sort is one of the slowest sorts, 
		//it iterates through the list, compares and swaps consecutive elements
		//which moves the next lowest number in the array to the front.
	void tree();
		//Tree sort places all items into a binary tree then does a 
		//in-order traversal and saves these values 
	void shell();
		//A form of insertion sort that compares items that are far apart,
		//Starts with small subarrays then moves to larger ones that are nearly sorted
	
	void compareSorts();
		//Calls all sorting algorithms and prints runtimes

private:
	vector<int> origional;
	int inputSize;
	treeNode *root;
		//used in tree sort
	
	double getTime();
		//gets the time
	//Helper Function fo Quick Sort
	void quick(int array[], int left, int right);

	//Helper Function for Heap Sort
	void heapToHeap(int array[], int size);

	//Helper Functions for Tree Sort
	void treeAddNode(int data);
	void treeTraverse(treeNode *node, vector<int> done);
};