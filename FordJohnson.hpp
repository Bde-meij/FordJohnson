#ifndef FORDJOHNSON_HPP
#define FORDJOHNSON_HPP

#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <string.h>

class FordJohnson
{
	public:
	// FordJohnson.cpp
	FordJohnson();
	FordJohnson(int ac, char **av);
	FordJohnson(const FordJohnson &other);
	FordJohnson &operator=(const FordJohnson &other);
	~FordJohnson();

	void makePairs(std::vector<int> intVec, size_t i);
	void recursiveSortForMerge(std::vector <std::pair<int, int>> &_pairVec, int n);
	void merge(std::vector <std::pair<int, int>> &_pairVec, std::vector <std::pair<int, int>> leftVec,\
	std::vector <std::pair<int, int>> rightVec, int leftLen, int rightLen);
	size_t jacob(size_t x);
	void showPairs();

	// vectCode.hpp
	void vectorStart(std::vector<int> intVec, int i);
	void vectorInsertion(std::vector<int> lowVec, std::vector<int> highVec);
	void vectorBetweenJacobs(std::vector<int> lowVec, std::vector<int> highVec, int a, int b);
	void vectorInsertLast(std::vector<int> lowVec);
	std::vector<int>::iterator vectorBinSearch(std::vector<int>::iterator first, \
	std::vector<int>::iterator last, int value);

	// listCode.hpp
	void listStart(std::vector<int> intVec, int i);
	void listInsertion(std::list<int> lowList, std::list<int> highList);
	void listBetweenJacobs(std::list<int> lowList, std::list<int> highList, int a, int b);
	void listInsertLast(std::list<int> lowList);
	std::list<int>::iterator listBinSearch(std::list<int>::iterator first, \
	std::list<int>::iterator last, int value);


	private:
	int _comparisons;
	int _recSortN;

	std::vector<int> _finalVec;
	std::vector<std::pair<int, int>> _pairVec;

	std::list<int> _finalList;
	std::list<std::pair<int, int>> _pairList;

	// https://oeis.org/A001768
	int compArr[56] = {
		0, 1, 3, 5, 7, 10, 13, 16, 19, 22, 26, 30, 34, 38, 42, 
		46, 50, 54, 58, 62, 66, 71, 76, 81, 86, 91, 96, 101, 106, 
		111, 116, 121, 126, 131, 136, 141, 146, 151, 156, 161, 
		166, 171, 177, 183, 189, 195, 201, 207, 213, 219, 225, 
		231, 237, 243, 249, 255
	};
};

#endif
