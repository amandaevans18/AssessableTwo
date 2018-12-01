// HighScoreEntry.h
#pragma once
#include <iostream>
class HighScoreEntry
{
public:
	std::string name;
	int score;
	int level;

	HighScoreEntry();
	~HighScoreEntry();

	bool operator<(HighScoreEntry& entry);
	bool operator>(HighScoreEntry& entry);
	bool operator<=(HighScoreEntry& entry);
	bool operator>=(HighScoreEntry& entry);

	void clear();
};