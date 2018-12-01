#include "HighScoreTable.h"
#include <vector>

int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");

	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them


	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(3);

	//retrieve the top 10 scores
	//std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them
	

	system("pause");
	return 0;
}