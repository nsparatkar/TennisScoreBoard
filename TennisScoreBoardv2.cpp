#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[5] = {"0", "15", "30", "40"};
	const string gameD = "Game to D";
	const string gameF = "Game to F";
	const string startingScore = "0 - 0";
	const string advantageToD = "A - ";
	const string advantageToF = " - A";
	const string deuce = "40 - 40";

	public:
	TennisScoreBoard(){
		scoreSequence = "";
		score_D = 0;
		score_F = 0;
		displayedScore = startingScore;
	}

	void displayScore(string scoreSequence){
		this->scoreSequence = scoreSequence;
		computeScore();
		cout << displayedScore << endl;
	}

	private:
	void computeScore(){
		for(int index = 0; index < scoreSequence.length(); index++){
			if(scoreSequence[index] == 'D'){
				score_D++;
			}else{
				score_F++;
			}
			updateScoreBoard();
		}
	}

	void updateScoreBoard(){
		bool deuceReached = !(score_D <= 3 && score_F <= 3);
		if(deuceReached) {
			bool gameWon = abs(score_D - score_F) >= 2;
			bool playerHasAdvantage = abs(score_D - score_F) == 1;
			if(gameWon) {
				if(score_D > score_F)
					displayedScore = gameD;
				else
					displayedScore = gameF;
			}
			else if(playerHasAdvantage) {
				if(score_D > score_F)
					displayedScore = advantageToD;
				else
					displayedScore = advantageToF;
			}
			else {
				displayedScore = deuce;
			}
		} else {
			displayedScore = score[score_D] + " - "  + score[score_F];
		}
	}
};

int main()
{
	string sequenceOfPoints = "DFDDFFF";

	TennisScoreBoard tennisGame;
	tennisGame.displayScore(sequenceOfPoints);
	return 0;
}
