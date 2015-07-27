#include<iostream>
using namespace std;

class TennisScoreBoard{

	string scoreSequence;
	int score_D;
	int score_F;
	string displayedScore;
	const string score[6] = {"0", "15", "30", "40","A"," "};

	void checkAdvantageLost(int i){
		if (score_D == 4  && score_F == 4 ) {
		    score_F--;
			score_D--;
		}
	}

	void updateScoreBoard(){

        displayedScore += score[score_D];
        displayedScore += " ";
        displayedScore += score[score_F];
	}

    bool won(){
        if ((score_D-score_F >=2) && (score_D >=4)) {
            displayedScore = "Game to D";
            return true;
        }
        else if ((score_F-score_D >=2) && (score_F >=4)) {
            displayedScore = "Game to F";
            return true;
        }
        else {
            return false;
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
			checkAdvantageLost(i);
			updateScoreBoard();
			if (won()) {
			    return;
			}
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
