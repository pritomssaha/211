/*
Name: Pritom Saha Shuvo
Assignment 1
*/


#include <iostream>
using namespace std;

bool checkodd(int x){
	if (x % 2 != 0 && (x / 10) % 2 != 0)  //check the last two digit if they are odd
		return true;              //return true if both digit are odd
	else
		return false;             //return flase if both digit are not odd
}

int main() {
	for (int i = 1;; i++){
		if (checkodd(i*i)){
			cout << i*i<<endl;
			break;
		}
	}
	return 0;
}

/*
conclusion:
the first perfect is negetive number because the first perfect square whose last two digits are both odd is bigger than integer range. 
So it overflows and gives a negative number.
*/