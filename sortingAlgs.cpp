#include <chrono>
#include <iostream>
#include <vector>
#include "sortingAlgs.h"
using namespace std;

milliseconds SortingAlgorithms::insertion(){
	auto start = chrono::high_resolution_clock::now();
	int index,j;
	int *array = &origional;
    for(int i = 1; i < inputSize; i++){
        index = array[i];
        j = i;
        while((j > 0) && (array[j - 1] > index)){
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = index;
    }
    auto finish = chrono::high_resolution_clock::now();

	return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

milliseconds SortingAlgorithms::selection(){
	auto start = chrono::high_resolution_clock::now();
	int minIndex;
    int temp;
    int *array = &origional;
    for(int i = 0; i < inputSize - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[minIndex])
                minIndex = j;
        }
        if(minIndex != i){
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    auto finish = chrono::high_resolution_clock::now();

    return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

//This function intentionally left empty to be implemented by others
milliseconds SortingAlgorithms::merge(){
	auto start = chrono::high_resolution_clock::now();

	//Code goes here 

	auto finish = chrono::high_resolution_clock::now();

	return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

milliseconds SortingAlgorithms::heap(){
	auto start = chrono::high_resolution_clock::now();
	int *array = &origional;
	int end = inputSize-1;
	heapToHeap(array);
	while(end>0){
		swap(array[0], array[end]);
		heapShiftDown(array, 0, end);
		--end;
	}
	auto finish = chrono::high_resolution_clock::now();

	return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

void SortingAlgorithms::heapShiftDown(int heap[], int i, int max){
	int iBig, c1, c2;
	while(i < max){
		iBig = i;
		c1 = (2*i) + 1;
		c2 = c1 + 1;
		if(c1<max && heap[c1]>heap[iBig])
			iBig = c1;
		if(c2<max && heap[c2]>heap[iBig])
			iBig = c2;
		if(iBig == c2) 
			return;
		swap(heap[i], heap[iBig]);
		i = iBig;
	}
}

void SortingAlgorithms::heapToHeap(int array[]){
	int i = (array.size()/2)-1;
	while(i>=0){
		heapShiftDown(array, i, array.size());
		--i;
	}
}

milliseconds SortingAlgorithms::quick(int array[], int left, int right){
	auto start = chrono::high_resolution_clock::now();
	int i = left;
	int j = right;
	int temp;
	int pivot = array[(left + right) / 2];
	while(i <= j){ 
	  	while(array[i] < pivot)
	       i++;
	  	while(array[j] > pivot)
	       j--;
	  	if(i <= j){
	       temp = array[i];
	       array[i] = array[j];
	       array[j] = temp;
	       i++;
	       j--;
	  }
	}
	if (left < j)
		quickSort(array, left, j);
	if (i < right)
		quickSort(array, i, right);
	auto finish = chrono::high_resolution_clock::now();

	return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

milliseconds SortingAlgorithms::bubble(){
	auto start = chrono::high_resolution_clock::now();
	int swap;
	int *array = &origional
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < inputSize - i - 1; j++){
            if(array[j] > array[j+1]){
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    auto finish = chrono::high_resolution_clock::now();

    return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

milliseconds SortingAlgorithms::tree(){
	auto start = chrono::high_resolution_clock::now();
	int *array = &origional;
	vector done<int>;
	treeNode *root;
	for(int i=0; i<inputSize; i++)
		treeAddNode(array[i]);

	treeTraverse(root, done);
	auto finish = chrono::high_resolution_clock::now();

	return chrono::duration_cast<std::chrono::milliseconds>(start - finish).count();
}

void SortingAlgorithms::treeAddNode(int data){
	treeNode *node = new treeNode;
	node->data = data;
    
    if(root == NULL)
    {
        root = node;
    }
    else{
        treeNode *parentNode = new treeNode;
        treeNode *currentNode = new treeNode;
        currentNode = root;

        while(currentNode != NULL){
            parentNode = currentNode;
            if(node->data > currentNode->data){
                currentNode = currentNode->right;
            }
            else{
                currentNode = currentNode->left;
            }
        }
        node->parent = parentNode;
        if(node->data > parentNode->data){
            parentNode->right = node;
        }
        else{
            parentNode->left = node;
        }
    }
}

void SortingAlgorithms::treeTraverse(treeNode *node, vector done<int>){
	if(node->left != NULL)
        treeTraverse(node->left);
    done.push_back(node->data, done);
    if(node->right != NULL)
        treeTraverse(node->right);
}

