#include "FordJohnson.hpp"

void FordJohnson::vectorStart(std::vector<int> intVec, int i)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	recursiveSortForMerge(_pairVec, i/2);
	_comparisons = i/2;
	std::vector<int> highVec;
	std::vector<int> lowVec;
	for (auto &p : _pairVec)
	{
		highVec.push_back(p.second);
		lowVec.push_back(p.first);
	}
	if (i % 2)
		lowVec.push_back(intVec[i - 1]);

	vectorInsertion(lowVec, highVec);

	std::cout << "\nvector:\n";
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "time used in ms: " \
	<< std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	int vn = 0;
	for (auto &v : _finalVec)
	{
		std::cout << v << " ";
		vn++;
	}
	std::cout << std::endl << vn << " numbers printed"\
	<< " with n comparisons: " << _comparisons + _recSortN << std::endl;
}

void FordJohnson::vectorInsertion(std::vector<int> lowVec, std::vector<int> highVec)
{
	_finalVec = highVec;
	size_t a = 0;
	while (jacob(a+1) <= highVec.size()) 
	{
		vectorBetweenJacobs(lowVec, highVec, jacob(a) -1, jacob(a+1) - 1);
		a++;
	}
	vectorBetweenJacobs(lowVec, highVec, jacob(a) -1, highVec.size() -1);
	if (lowVec.size() > highVec.size())
		vectorInsertLast(lowVec);
}

void FordJohnson::vectorBetweenJacobs(std::vector<int> lowVec, std::vector<int> highVec, int a, int b)
{
	std::vector<int>::iterator leftI;
	std::vector<int>::iterator rightI;
	while (a < b)
	{
		leftI = _finalVec.begin();
		rightI = _finalVec.begin();
		while (*rightI != highVec[b])
			rightI++;
		_finalVec.insert(vectorBinSearch(leftI, rightI, lowVec[b]), lowVec[b]);
		b--;
	}
}

void FordJohnson::vectorInsertLast(std::vector<int> lowVec)
{
	std::vector<int>::iterator finStart = _finalVec.begin();
	std::vector<int>::iterator finEnd = _finalVec.end()-1;
	std::vector<int>::iterator lowVi = lowVec.end()-1;
	_finalVec.insert(vectorBinSearch(finStart, finEnd, *lowVi), *lowVi);
}

std::vector<int>::iterator FordJohnson::vectorBinSearch(std::vector<int>::iterator first, \
std::vector<int>::iterator last, int value)
{
	std::vector<int>::iterator it;
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