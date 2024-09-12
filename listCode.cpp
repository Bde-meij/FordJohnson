#include "FordJohnson.hpp"

void FordJohnson::listStart(std::vector<int> intVec, int i)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	_pairList.sort();
	_comparisons = i/2;
	std::list<int> lowList;
	std::list<int> highList;
	for (auto &a : _pairList)
	{
		lowList.push_back(a.second);
		highList.push_back(a.first);
	}
	if (i % 2 == 1)
		lowList.push_back(intVec[i - 1]);

	listInsertion(lowList, highList);

	std::cout << "\nlist:\n";
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "time used in ms: " \
	<< std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	int ln = 0;
	for (auto &l : _finalList)
	{
		std::cout << l << " ";
		ln++;
	}
	std::cout << std::endl << ln << " numbers printed"\
	<< " with n comparisons: " << _comparisons + _recSortN << std::endl;
}


void FordJohnson::listInsertion(std::list<int> lowList, std::list<int> highList)
{
	_finalList = highList;
	size_t a = 0;
	while (jacob(a+1) <= highList.size()) 
	{
		listBetweenJacobs(lowList, highList, jacob(a) -1, jacob(a+1) - 1);
		a++;
	}
	listBetweenJacobs(lowList, highList, jacob(a) -1, highList.size() -1);
	if (lowList.size() > highList.size())
		listInsertLast(lowList);
}

void FordJohnson::listBetweenJacobs(std::list<int> lowList, std::list<int> highList, int a, int b)
{
	std::list<int>::iterator leftI;
	std::list<int>::iterator rightI;
	std::list<int>::iterator lowVal;
	std::list<int>::iterator highVal;

	while (a < b)
	{
		lowVal = lowList.begin();
		std::advance(lowVal, b);
		highVal = highList.begin();
		std::advance(highVal, b);
		leftI = _finalList.begin();
		rightI = _finalList.begin();

		while (*rightI != *highVal)
			rightI++;
		_finalList.insert(listBinSearch(leftI, rightI, *lowVal), *lowVal);
		b--;
	}
}

void FordJohnson::listInsertLast(std::list<int> lowList)
{
	std::list<int>::iterator finStart = _finalList.begin();
	std::list<int>::iterator finEnd = _finalList.end();
	finEnd--;
	std::list<int>::iterator lowLi = lowList.end();
	lowLi--;
	_finalList.insert(listBinSearch(finStart, finEnd, *lowLi), *lowLi);
}

std::list<int>::iterator FordJohnson::listBinSearch(std::list<int>::iterator first, \
std::list<int>::iterator last, int value)
{
	std::list<int>::iterator it;
    int count = std::distance(first, last);
	int step = 0;
 
	_comparisons++;
    while (count > 0)
    {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
        if (!(value < *it))
        {
			_comparisons++;
            first = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
    return (first);
}