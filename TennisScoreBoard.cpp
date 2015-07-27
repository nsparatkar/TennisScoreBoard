#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[5] = {"0", "15", "30", "40"};
	
	void checkAdvantageLost(int i){
		if(score_D == 4 && scoreSequence.at(i) == 'F')
			score_D--;
		if(score_F == 4 && scoreSequence.at(i) == 'D')
			score_F--;
	}
	
	bool playerAdvantage() {
		if(score_D == 4 && score_F == 3)
			return true;
		if(score_D == 3 && score_F == 4)
			return true;
		return false;
	}
	
	void updateScoreBoard(){
		if(playerAdvantage()) {
			if(score_D > score_F)
				displayedScore = "A - ";
			else
				displayedScore = " - A";
		} else {
			displayedScore += score[score_D];
			displayedScore += " ";
			displayedScore += score[score_F];
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
			checkAdvantageLost(i);
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
		cout << displayedScore << endl;
	}

};

int main()
{
    string sequenceOfPoints = "DFDFDFDF";

    TennisScoreBoard tennisGame;
    tennisGame.displayScore(sequenceOfPoints);
	return 0;
}
