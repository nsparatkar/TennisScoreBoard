#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[] = {"0", "15", "30", "40"};

	bool scoreDeuce() {
		if(score_D == 3 && score_F == 3)
			return true;
		return false;
	}

	bool playerAdvantage() {
		if(
	}

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
		computeScore();
		this->scoreSequence = scoreSequence;
		computeScore();
		cout << displayedScore << endl;
	}

};

int main()
{
<<<<<<< HEAD
    string sequence0fPoints = "DFFDDFDDFFDFDFDFDDFDDFFDFFDF";

    TennisScoreBoard tennisGame = new TennisScoreBoard();
    tennisGame.displayScore(sequence0fPoints);

    return 0;
=======
    string sequence0fPoints = "D F F D D F D D F F D F D F D";
    TennisScoreBoard tennisGame = new TennisScoreBoard();
    tennisGame.displayScore(sequence0fPoints);
>>>>>>> e4cea4ceb10edf96969c6f3558f28c860983d0ce
}
