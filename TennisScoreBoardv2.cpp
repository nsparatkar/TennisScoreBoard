#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[5] = {"0", "15", "30", "40"};
	
	void updateScoreBoard(){
		if(score_D <= 3 && score_F <= 3) {
			displayedScore += score[score_D];
			displayedScore += " - ";
			displayedScore += score[score_F];
		} else {
			bool hasWon = abs(score_D - score_F) >= 2;
			bool playerHasAdvantage = abs(score_D - score_F) == 1;
			if(hasWon) {
				displayedScore = "Game";
			}
			else if(playerHasAdvantage) {
				if(score_D > score_F)
					displayedScore = "A - ";
				else
					displayedScore = " - A";
			}
			else {
				displayedScore = "40 - 40";
			}
		}
	}
	
	void computeScore(){
		for(int i = 0; i < scoreSequence.length(); i++){
			displayedScore = "";
			if(scoreSequence[i] == 'D'){
				score_D++;
			}else{
				score_F++;
			}
			updateScoreBoard();
			cout << displayedScore << endl;
		}
	}

	public:
	TennisScoreBoard(){
		scoreSequence = "";
		score_D = 0;
		score_F = 0;
		displayedScore = "0 - 0";
	}	
		
	void displayScore(string scoreSequence){
		this->scoreSequence = scoreSequence;
		computeScore();
		//cout << displayedScore << endl;
	}

};

int main()
{
    string sequenceOfPoints = "DDDD";

    TennisScoreBoard tennisGame;
    tennisGame.displayScore(sequenceOfPoints);
	return 0;
}
