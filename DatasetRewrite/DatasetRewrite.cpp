// DatasetRewrite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>


#include "Date.h"

using var_t = std::variant<int, double, float, short>;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;


class testC {
public:
	Date it;
	testC(int i, int j, int k) { it = Date(i, j, k); };
	bool operator<( testC right) {
		return (this->it < right.it);
	}
};

int main()
{
	var_t test;
    std::cout << "Hello World!\n"; 
	
	test = 1;
	
	std::visit(overloaded{
			[](double arg) { std::cout << arg << " double "; },
			[](int  arg) { std::cout << arg << " int "; },
			[](short  arg) { std::cout << arg << " short "; },
			[](float  arg) { std::cout << arg << " float "; },
		}, test);

	std::cout << std::endl;
	
	test = 2.45;

	std::visit(overloaded{
			[](double arg) { std::cout << arg << " double "; },
			[](int  arg) { std::cout << arg << " int "; },
			[](short  arg) { std::cout << arg << " short "; },
			[](float  arg) { std::cout << arg << " float "; },
		}, test);

	std::cout << std::endl;


	std::vector<testC> testV;

	int i = 0;

	int d, m, y;

	while (i != -1) {
		
		

		for (int index = 0; index < 3; index++) {
			if (index == 0) {
				std::cout << "Next Day: ";
				std::cin >> d;
				std::cout << " ";
			} else if (index == 1) {
				std::cout << "Next Month: ";
				std::cin >> m;
				std::cout << " ";
			}
			else {
				std::cout << "Next Year: ";
				std::cin >> y;
				std::cout << " ";
			}
		}


		testV.push_back(testC(d,m,y));

		std::sort(testV.begin(), testV.end());
		

		for (testC i : testV) {
			std::cout << " " << i.it.getDay() << "/" << i.it.getMon() << "/" << i.it.getYear() << " " ;
		}
		std::cout << std::endl;
	}

	

}



