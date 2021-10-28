
/*
Name: Pritom Saha Shuvo
Assignment 2
*/

#include <iostream>
#include<string>
using namespace std;

//function to reverse the string
string reverse_string(string x){
	int y = x.length() - 1;
	string z = "";	
	for (int i = 0; i<x.length(); i++){
		z.append(1, x[y]);
		y--;
	}
	return z;
}

//function to calculate the sum
string find_sum(string a, string b){

	if (a.length()<b.length())                            //if second string is bigger than first string then swap the string
		a.swap(b); 

	string str = "";
	string q = "";
	int carry = 0;

	string m = reverse_string(a);
	string n = reverse_string(b);

	for (int i = 0; i<b.length(); i++){                   //calculate the sum of smallest string
		int sum = ((m[i] - '0') + (n[i] - '0') + carry);
		str.append(1, sum % 10 + '0');
		carry = sum / 10;
	}

	for (int j = b.length(); j<a.length(); j++){         //calculate the largest string
		int sum = ((m[j] - '0') + carry);
		str.append(1, sum % 10 + '0');
		carry = sum / 10;
	}
	
	if (carry>0){                                        //calculate the rest of the string
		str.append(1, carry + '0');
	}
	q = reverse_string(str);
	return q;
}



int main() {
	string s1 = "";
	string s2 = "";
	string q;
	while (q != "end"){
		cout << "Enter a number: ";
		cin >> s1;
		cout << "Enter another number: ";
		cin >> s2;
		cout << "sum of two number is: "<<find_sum(s1, s2) << endl;
    cout<<endl;
		cout << "Enter end to quit or press any key to continue ";
		cin >> q;
    cout<<endl;
	}
	return 0;
}