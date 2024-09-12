#include "FordJohnson.hpp"

FordJohnson::FordJohnson()
{

}

FordJohnson::FordJohnson(const FordJohnson &other)
{
	*this = other;
}

FordJohnson &FordJohnson::operator=(const FordJohnson &other)
{
	if (this == &other)
		return (*this);
	_comparisons = other._comparisons;
	_finalVec = other._finalVec;
	_finalList = other._finalList;
	_pairVec = other._pairVec;
	_pairList = other._pairList;
	return (*this);
}

FordJohnson::~FordJohnson()
{
	std::cout << __FUNCTION__ << " called" <<std::endl;
}

FordJohnson::FordJohnson(int ac, char **av) : _comparisons(0), _recSortN(0)
{
	int i = ac;
	std::vector<int> intVec;
	
	for (int a = 1; a < i; a++)
		intVec.push_back(atoi(av[a]));
	i--;

	std::cout << i << " numbers given:" << std::endl;
	for (auto &vi : intVec)
		std::cout << vi << " ";
	std::cout << std::endl;
	if (i <= 56)
		std::cout << "max comparisons allowed = " << compArr[i-1] << std::endl;
	makePairs(intVec, i);
	
	// showPairs();
	vectorStart(intVec, i);
	listStart(intVec, i);
	// showPairs();
}

void FordJohnson::recursiveSortForMerge(std::vector <std::pair<int, int>> &_pairVec, int n)
{
	if (n < 2)
		return ;

	int leftLen = n/2;
	int rightLen = n - leftLen;
	std::vector <std::pair<int, int>> leftVec;
	std::vector <std::pair<int, int>> rightVec;

	for (int i = 0; i < leftLen; i++)
		leftVec.push_back(_pairVec[i]);
	for (int i = 0; i < rightLen; i++)
		rightVec.push_back(_pairVec[leftLen+i]);

	recursiveSortForMerge(leftVec, leftLen);
	recursiveSortForMerge(rightVec, rightLen);
	merge(_pairVec, leftVec, rightVec, leftLen, rightLen);
}

void FordJohnson::merge(std::vector <std::pair<int, int>> &_pairVec, std::vector <std::pair<int, int>> leftVec, \
std::vector <std::pair<int, int>> rightVec, \
int leftLen, int rightLen)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < leftLen && j < rightLen)
	{
		if (leftVec[i].second < rightVec[j].second)
		{
			_pairVec[k] = leftVec[i];
			i++;
		}
		else
		{
			_pairVec[k] = rightVec[j];
			j++;
		}
		k++;
		_recSortN++;
	}
	while (i < leftLen)
	{
		_pairVec[k] = leftVec[i];
		i++;
		k++;
	}
	while (j < rightLen)
	{
		_pairVec[k] = rightVec[j];
		j++;
		k++;
	}
}

void FordJohnson::makePairs(std::vector<int> intVec, size_t i)
{
	std::pair<int, int> tmpPair;

	for (size_t a = 0; (a + 1) < i; a+=2)
	{
		if (intVec[a] < intVec[a+1])
		{
			tmpPair.first = intVec[a];
			tmpPair.second = intVec[a+1];
		}
		else
		{
			tmpPair.first = intVec[a+1];
			tmpPair.second = intVec[a];
		}
		_pairVec.push_back(tmpPair);
		std::swap(tmpPair.first, tmpPair.second);
		_pairList.push_back(tmpPair);
	}
}

size_t FordJohnson::jacob(size_t x)
{
	return ((pow(2, x) - pow(-1, x)) / 3);
}

void FordJohnson::showPairs()
{
	std::cout << "\nvectorPairs:\n";
	for (auto &pv : _pairVec)
		std::cout << pv.first << " " << pv.second << std::endl;
	std::cout << "\nlistPairs:\n";
	for (auto &pl : _pairList)
		std::cout << pl.first << " " << pl.second << std::endl;
}
