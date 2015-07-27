#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[] = {"0", "15", "30", "40"};

	TennisScoreBoard(){
		scoreSequence = "";
		score_D = 0;
		score_F = 0;
		displayedScore = "0 - 0";
	}
	
	void updateScoreBoard(){
		displayScore += score[score_D];
		displayScore += " ";
		displayScore += score[score_F];
	}
	
	void computeScore(){
		for(char scorer : scoreSequence){
			displayedScore = "";
			if(scorer == 'D'){
				score_D++;
			}else{
				score_F++;
			}
			if( scoreDuece() ){
				score_D--;
				score_F--;
			}
			updateScoreBoard();
		}
	}

	public:
	void displayScore(string scoreSequence){
		this->scoreSequence = scoreSequence;
		computeScore();
		cout << displayedScore << endl;
	}

};

int main()
{
    string sequence0fPoints = "DFFDDFDDFFDFDFDFDDFDDFFDFFDF";

    TennisScoreBoard tennisGame = new TennisScoreBoard();
    tennisGame.displayScore(sequence0fPoints);

    return 0;
}
