// highscoretable.h
#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include<fstream>
#include<string>
class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	size_t firstIndex = 0;
	size_t middleIndex = 0;
	size_t lastIndex = 0;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	HighScoreEntry operator[](size_t index);
	bool pruneBottomNNScores(int bottomRows);
	void bubbleSort();
	void insertionSort();
	void mergeSort(std::vector<HighScoreEntry> arr, size_t _firstIndex, size_t _lastIndex);
	void Merge(std::vector<HighScoreEntry> arr, size_t _firstIndex, size_t _middleIndex, size_t _lastIndex);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
};