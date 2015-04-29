#include <iostream>
#include "sortingAlgs.h"
#include <stdexcept>
using namespace std;

int main(){
	system("clear");
	cout<<"---Sorting Algorithm Runtime Comparison---\n";
	cout<<"----Created by Jennifer Dooley------------\n";

    string in_num;
	int num;
	cout<<endl<<"How many elements would you like to sort?"<<endl;
	getline(cin >>ws, in_num);
    try{
        num = stoi(in_num);
    }
    catch(invalid_argument& e){
        num = 8;
    }
	while(num < 20 || num > 1000){
        cout<<"Please input a number from 20 to 1000."<<endl;
        getline(cin >> ws, in_num);
        try{
            num = stoi(in_num);
        }
        catch(invalid_argument& e){
            num = 8;
        }
	}
	SortingAlgorithms input = SortingAlgorithms(num);
	input.compareSorts();
	cout<<endl;

	cout<<"----------------Thank You-----------------\n";
	return 0;
}
