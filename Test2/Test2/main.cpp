#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <thread>

using namespace std;

const int WINCOUNT = 3;

vector<string> PlayersCondition = {
	"A",
	"B"
};

unsigned Seed = std::chrono::system_clock::now().time_since_epoch().count();

std::mt19937 engine(Seed);

bool CheckWinCondition(vector<string>* Players, string CheckPlayer)
{
	

	

	size_t PlayersSize = Players->size();


	std::uniform_int_distribution<int> dist(0, PlayersSize - 1);

	int RandomIndex = dist(engine);

	string SelectedPlayer = Players->at(RandomIndex);



	return SelectedPlayer == CheckPlayer;

}


int main()
{

	int Round = 1;
	int Index = 0;
	int WinCount = 0;

	int RepeatCount;

	cout << "Enter Repeat Count: ";
	cin >> RepeatCount;

	for (int i = 0; i < RepeatCount - 1; i++)
	{

		int LocalLostCount = 0;
		int LocalWinCount = 1;

		while (LocalLostCount != WINCOUNT && LocalWinCount != WINCOUNT)
		{

			Index++;

			bool DidWin = CheckWinCondition(&PlayersCondition, "A");

			if (DidWin)
			{
				LocalWinCount++;
			}
			else
			{
				LocalLostCount++;
			}
		}

		if (LocalWinCount == 3)
		{
			WinCount++;

			//cout << "Round " << Round << "Won" << endl;
		}
		else
		{
			//cout << "Round " << Round << "Lost" << endl;
		}

		Round++;
	}

	cout << "Won " << WinCount << " / " << Round << endl;

	this_thread::sleep_for(chrono::seconds(2));
	return 0;
}
