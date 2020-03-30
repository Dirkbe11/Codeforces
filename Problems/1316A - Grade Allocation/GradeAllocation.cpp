#include <iostream>
#include <vector>

using namespace std;

void calculate(int numberStudents, int highestScore, vector<int>& scores)
{
	if(scores.size() == 1)
	{
		std::cout << scores[0] << "\n";
	}
	// int average = std::accumulate(scores.begin(), scores.end(), 0)/scores.size();

	int ourScore = scores[0];
	int index = 1;
	while(index < scores.size() && ourScore < highestScore)
	{
		if(scores[index] == 0)
		{
			index++;
			continue;
		}

		ourScore++;
		scores[index]--; 
	}

	std::cout << ourScore << "\n";
}

int main()
{
	int testCases;
	std::cin >> testCases;

	while(testCases--)
	{
		int numberStudents;
		int highestScore;
		std::cin >> numberStudents;
		std::cin >> highestScore;

		int score = 0;
		std::vector<int> scores(numberStudents, 0);
		while(numberStudents--)
		{
			std::cin >> score;
			scores.push_back(score);
		}

		calculate(numberStudents, highestScore, scores);
	}
}