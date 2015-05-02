#include <sys/time.h>
#include <iostream>
#include <vector>
#include "sortingAlgs.h"
using namespace std;

SortingAlgorithms::SortingAlgorithms(int arraySize){
	//generate the random sized array of random numbers
	getInput(arraySize);
	root = NULL;
}

void SortingAlgorithms::getInput(int arraySize){
	//make size a random number from 20 to 1000
	inputSize = arraySize;
	srand(time(NULL));
	cout<<"\nRunning comparison on "<<inputSize<<" elements\n";
	for(int i=inputSize; i>0; i--){
		//fill the array with random numbers from 0 to 999
		origional.push_back(rand()%1000);
	}
}

SortingAlgorithms::~SortingAlgorithms(){}

//Function used to return the time to the precision of microseconds
double SortingAlgorithms::getTime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double d = t.tv_sec + (double) t.tv_usec;
    return d;
}

void SortingAlgorithms::insertion(){
	double start = getTime();

	int index,j;
	int *array = &origional[0];

    for(int i = 1; i < inputSize; i++){
        index = array[i];
        j = i;
        while((j > 0) && (array[j - 1] > index)){
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = index;
    }
    double finish = getTime();

	double dif = finish-start;
	cout<<"\tInsertion Sort: "<<dif<<endl;
}

void SortingAlgorithms::selection(){
	double start = getTime();

	int minIndex;
    int temp;
    int *array = &origional[0];

    for(int i = 0; i < inputSize - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < inputSize; j++){
            if(array[j] < array[minIndex])
                minIndex = j;
        }
        if(minIndex != i){
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    double finish = getTime();

    double dif = finish-start;
    cout<<"\tSelection Sort: "<<dif<<endl;
}

//This function intentionally left empty to be contributed to by others
void SortingAlgorithms::merge(){
	double start = getTime();
	
	vector<int> vec = origional;
	vector<int> comp=merge_sort(vec);
	//Code goes here

	double finish = getTime();

	double dif = finish-start;
	cout<<"\tMerge Sort: "<<dif<<endl;
}

vector<int> SortingAlgorithms::merge_sort(vector<int>& vec){

    if(vec.size() == 1)
    {
        return vec;
    }


    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return mergeRecurs(vec,left, right);
}

vector<int> SortingAlgorithms::mergeRecurs(vector<int> &vec,const vector<int>& left, const vector<int>& right){

    vector<int> result;
    unsigned left_int = 0, right_int = 0;

    while(left_int < left.size() && right_int < right.size())
    {
        if(left[left_int] < right[right_int])
        {
            result.push_back(left[left_int]);
            left_int++;
        }
        else
        {
            result.push_back(right[right_int]);
            right_int++;
        }
    }

    while(left_int < left.size())
    {
        result.push_back(left[left_int]);
        left_int++;
    }

    while(right_int < right.size())
    {
        result.push_back(right[right_int]);
        right_int++;
    }

	vec = result;
	return vec;
}

void SortingAlgorithms::heap(){
	double start = getTime();

	int *array = &origional[0];

	for(int i = inputSize-1; i > 0; i--){
		int iValue = array[i];
		array[i] = array[0];
		array[0] = iValue;
		heapToHeap(array, i);
	}
	double finish = getTime();
	double dif = finish - start;
	cout<<"\tHeap Sort: "<<dif<<endl;
}

//function creats a heap
void SortingAlgorithms::heapToHeap(int array[], int size){
	for(int i = 1; i < size; i++){
		int val = array[i];
		int s = i;
		int f = (s-1)/2;
		while(s>0 && array[f] < val){
			array[s] = array[f];
			s = f;
			f = (s-1)/2;
		}
		array[s] = val;
	}
}

void SortingAlgorithms::quickCall(){
	double start = getTime();

	//Calls the recursive function for quick sort
	quick(&origional[0], 0, inputSize);

	double finish = getTime();

	double dif = finish-start;
	cout<<"\tQuick Sort: "<<dif<<endl;
}

void SortingAlgorithms::quick(int array[], int left, int right){
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
		quick(array, left, j);
	if (i < right)
		quick(array, i, right);
}

void SortingAlgorithms::bubble(){
	double start = getTime();
	int swap;
	int *array = &origional[0];
    for(int i = 0; i < inputSize - 1; i++){
        for(int j = 0; j < inputSize - i - 1; j++){
            if(array[j] > array[j+1]){
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    double finish = getTime();

    double dif = finish-start;
    cout<<"\tBubble Sort: "<<dif<<endl;
}

void SortingAlgorithms::tree(){
	double start = getTime();
	int *array = &origional[0];
	vector<int> done;
	for(int i=0; i<inputSize; i++)
		treeAddNode(array[i]);
	treeTraverse(root, done);
	double finish = getTime();

	double dif = finish-start;
	cout<<"\tTree Sort: "<<dif<<endl;
}

void SortingAlgorithms::treeAddNode(int num){
	treeNode *node = new treeNode;
	node->data = num;
	node->right = NULL;
	node->left = NULL;

    if(root == NULL){
        root = node;
    }
    else{
        treeNode *currentNode = root;
        treeNode *parentNode = NULL;

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

void SortingAlgorithms::treeTraverse(treeNode *node, vector<int> done){
	if(node->left != NULL)
        treeTraverse(node->left, done);
    done.push_back(node->data);
    if(node->right != NULL)
        treeTraverse(node->right, done);
}

void SortingAlgorithms::shell(){
	double start = getTime();
	int *array = &origional[0];
	int temp;

	for(int i = inputSize/2; i>0; i /= 2){
		for(int j = i; j<inputSize;j++){
			temp = array[j];
			for(int k = j; k >= i; k -= i){
				if(temp < array[k-1])
					array[k] = array[k-i];
				else
					break;
			}
			array[j] = temp;
		}
	}
	double finish = getTime();

	double dif = finish-start;
	cout<<"\tShell Sort: "<<dif<<endl;
}

void SortingAlgorithms::gnome()
{
	double start = getTime();
	int *array = &origional[0];

	//declare values
	int place = 1;
	int temp;
	while (place < inputSize)
	{
		if (array[place] >= array[place-1]) //compare index to previous index
        {
            place = place +1; //ignore if it's already ordered
        }
        else //Swap the values in the array
        {
            temp = array[place];
            array[place] = array[place -1];
            array[place-1] = temp;
            
            //bring place down 1 to make sure it goes all the way down
            place -=1; 
        }
	}

	double finish = getTime();
	double dif = finish - start;
	cout<<"\tGnome Sort: "<<dif<<endl;
}

void SortingAlgorithms::compareSorts(){
	cout<<"Runtime results for sorting input in microseconds:\n";
	insertion();
	selection();
	merge();
	heap();
	quickCall();
	bubble();
	tree();
	shell();
	gnome();
}
