#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	const string score[] = {"0", "15", "30", "40"};

	TennisScoreBoard(){
		scoreSequence = "";
		score_D = 0;
		score_F = 0;
	}

	string computeScore(){

	}

	public:
	void displayScore(string scoreSequence){
		this->scoreSequence = scoreSequence;
		computeScore();
		cout << score[score_D] <<" - "<< score[score_F]<<endl;
	}

};

void main()
{
    string sequence0fPoints = "D F F D D F D D F F D F D F D";

    TennisScoreBoard tennisGame = new TennisScoreBoard();
    tennisGame.displayScore(sequence0fPoints);

}
