#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[5] = {"0", "15", "30", "40","A"};

	

	bool checkAdvantageLost(int i){
		return (score_D == 4 && scoreSequence.at(i) == 'F') || (score_F == 4 && scoreSequence.at(i) == 'D') ;
	}

	bool playerAdvantage() {
		if( (score_D + score_F) == 7 )
			return true;
		return false;
	}

	void updateScoreBoard(){

		if(playerAdvantage()) {
			if(score_D > score_F)
				displayedScore = "A - ";
			else
				displayedScore = " - A";
		} else if(score_D == 5 || score_F == 5) {
				displayedScore = "Game";
		} else {
			displayedScore += score[score_D];
			displayedScore += " ";
			displayedScore += score[score_F];
		}
	}

	void computeScore(){
		for (int i = 0; i < scoreSequence.length(); i++) {
			displayedScore = "";
			if (scoreSequence[i] == 'D') {
				score_D++;
			} else {
				score_F++;
			}
			if( checkAdvantageLost(i) ){
				score_D--;
				score_F--;
			}
			updateScoreBoard();
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
		cout << displayedScore << endl;
	}

};

int main()
{
    string sequenceOfPoints = "DFDFDFDFDD";

    TennisScoreBoard tennisGame;
    tennisGame.displayScore(sequenceOfPoints);
	return 0;
}
