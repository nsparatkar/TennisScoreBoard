#include<iostream>
using namespace std;

class TennisScoreBoard{
	
	string scoreSequence;
	int score_D;
	int score_F;
	string score[] = {"0", "15", "30", "40"};

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
	}
	
};
