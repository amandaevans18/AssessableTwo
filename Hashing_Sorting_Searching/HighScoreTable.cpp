#include "highScoreTable.h"

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	return hsVector;
}

HighScoreEntry HighScoreTable::operator[](size_t index)
{
	return hsVector[index];
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return false;
}

void HighScoreTable::bubbleSort()
{
	std::vector<HighScoreEntry> tempVector;
	for (size_t i = 0; hsVector.size(); i++)
	{
		for (size_t j = 0; j < hsVector.size(); j++)
		{
			if (hsVector[j].score < hsVector[j - 1].score)
			{
				hsVector[j] = tempVector[j - 1];
			}
		}
	}
}

void HighScoreTable::insertionSort()
{
}

//   p is the first index to start merging and sorting from
//   q is the index between p and r
//   r is the last index to merge and sort through
void HighScoreTable::mergeSort(std::vector<HighScoreEntry> arr, size_t _firstIndex, size_t _lastIndex)
{
	if (_firstIndex < _lastIndex)
	{
		middleIndex = (_firstIndex + _lastIndex) / 2;
		mergeSort(arr, _firstIndex, middleIndex);
		mergeSort(arr, middleIndex + 1, _lastIndex);
		Merge(arr, _firstIndex, middleIndex, _lastIndex);
	}
}

void HighScoreTable::Merge(std::vector<HighScoreEntry> arr, size_t _firstIndex, size_t _middleIndex, size_t _lastIndex)
{
	size_t leftEnd = _middleIndex - firstIndex + 1;
	size_t rightEnd = lastIndex - _middleIndex;

	// create an array that is size: leftEnd
	std::vector<HighScoreEntry> leftEndArr;
	leftEndArr.resize(leftEnd);
	// create an array that is size: rightEnd
	std::vector<HighScoreEntry> rightEndArr;
	leftEndArr.resize(rightEnd);

	// copy left elements into leftArray
	for (size_t i = _firstIndex; i < leftEnd; i++)
	{
		arr[i] = leftEndArr[i];
	}
	// copy right elements into rightArray
	for (size_t i = _middleIndex; i < _lastIndex; i++)
	{
		arr[i] = leftEndArr[i];
	}
	size_t i = 0;
	size_t j = 0;

	// for all values from p to r = k
	if ((j >= rightEnd) || (i < leftEnd && leftEndArr[i] <= rightEndArr[j]))
	{
		// set A[k] to the value of leftEndArr[i]
		// increase i by one
		// else
		// set A[k] = R[j] 
		// increase j by one
	}
}



HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)//copying data from file into the vector of high score entrys.
{
	std::fstream file;
	int amtOfCommas = 0;
	HighScoreEntry temp;
	file.open(fileName, std::ios_base::in);
	if (!file.is_open())
	{
		std::cout << "Failed to open file!" << std::endl;
		return;
	}
	std::string buffer;
	//copying all the info into our dearest vector
	while (std::getline(file, buffer))
	{
		for (int i = 0; i < buffer.length(); i++)
		{
			if (buffer[i] == ',')
			{
				amtOfCommas++;
			}
			switch (amtOfCommas)
			{
			case 0:
				temp.name += buffer[i];
				break;
			case 1:
				temp.score += buffer[i];
				break;

			case 2:
				temp.level += buffer[i];
				break;
			}
		}

		hsVector.push_back(temp);
		temp.clear();
	}
	file.flush();
	file.close();

	//sorting the data!
	bubbleSort();
}

HighScoreTable::~HighScoreTable()
{

}