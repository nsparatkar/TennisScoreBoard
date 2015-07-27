#include<iostream>
using namespace std;

class TennisScoreBoard{
	
	string scoreSequence;
	int score_D;
	int score_F;
	string score[] = {"0", "15", "30", "40"};

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
	}
	
	void computeScore(){
		
	}
	
	public:
	void displayScore(string scoreSequence){
		computeScore();
		this->scoreSequence = scoreSequence;
	}
	
};

int main() {
	TennisScoreBoard tennis_board();
	tennis_board.displayScore("DFDDFD");
	return 0;
}
