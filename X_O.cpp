#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

class لعبة_X_O
{
private:

	enum enComputerOrPlayer2 { Computer = 0, Player2 = 1 };
	enum enHardOrEasy { Easy = 0, Hard = 1 };

	short Player_Option[5] = { 0,0,0,0,0 };
	short Player2_Option[5] = { 0,0,0,0,0 };
	short Computer_Option[5] = { 0,0,0,0,0 };


	vector <vector  <short> > Win_Option = { {1, 2, 3},
										   { 7, 8, 9 },
										   { 3, 6, 9 },
										   { 1, 4, 7 },
										   { 1, 5, 9 },
										   { 3, 5, 7 },
										   { 2, 5, 8 },
										   { 4, 5, 6 }
	};

	short Player_number = 0, Player2_number = 0, Computer_number = 0,
		Count_Play_P = 0, Count_Play_P2 = 0, Count_Play_Computer = 0, Round_number = 0;

	enComputerOrPlayer2 ComputerOrPlayer2;
	enHardOrEasy HardOrEasy;


	char Options[9] = { ' ', ' ', ' ',
					  ' ', ' ', ' ',
					  ' ', ' ', ' ' };

	static void  Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static  int  Read_Int_Number(string Message)
	{
		int Number = 0;

		cin >> Number;

		while (Number < 0 || cin.fail())
		{


			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;



		}

		return Number;
	}

	static  bool Is_Number_Between(short number, short From, short To)
	{
		return (number > From && number < To) ? true : false;
	}

	static  short Read_Short_Number_Between(short From, short To, string Message)
	{
		short number = Read_Int_Number(" Wrong Number ! ");

		while (!Is_Number_Between(number, From, To))
		{
			cout << Message << endl;
			number = Read_Int_Number(" Wrong Number ! ");

		}


		return number;
	}

	static  int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	void Resaid()
	{
		system("cls");

	}

	bool Is_Option_Full(short _number, short& Count, char The_Player_Char)
	{

		if (Options[_number - 1] == ' ') {
			Options[_number - 1] = The_Player_Char;
			Count++;
			return false;
		}
		else
		{
			cout << "\nOption Full";
			return true;
		}
	}

	bool IS_Win_Or_Yate(short Player_Option[5])
	{
		if (Player_Option[2] == 0)
		{
			return false;
		}
		for (vector <short>& Option : Win_Option)
		{
			short Option_Correct = 0;
			for (short i = 0; i < 5; i++)
			{
				if (Player_Option[i] == 0)
				{
					break;
				}

				if (Option[0] == Player_Option[i] || Option[1] == Player_Option[i] || Option[2] == Player_Option[i])
				{
					Option_Correct++;
				}

			}
			if (Option_Correct == 3)
			{
				return true;
			}
		}
		return false;
	}

	void Read_Player2()
	{

		printf("The Player [ 2 ] Chooses...:\n");
		printf("Enter {");
		Player2_Option[Count_Play_P2] = (Player2_number = Read_Short_Number_Between(0, 10, "This number Out Of Range !#  Enter Aging{ "));

	}

	void Read_Player()
	{


		printf("\nThe Player [ 1 ] Chooses...:\n");
		printf("Enter {");
		Player_Option[Count_Play_P] = (Player_number = Read_Short_Number_Between(0, 10, "This number Out Of Range !#  Enter Aging{ "));

	}

	enComputerOrPlayer2 Is_Computer_Or_Player2()
	{

		ComputerOrPlayer2 = (enComputerOrPlayer2)Read_Short_Number_Between(-1, 2, "This number Out Of Range !#");
		return ComputerOrPlayer2;
	}

	enHardOrEasy Is_Hard_Or_Easy()
	{
		Resaid();
		cout << "\nChoose The difficulty Level :\n\n";
		cout << "[0] - > * Easy *\n";
		cout << "[1] - > * Hard *\n";
		return HardOrEasy = (enHardOrEasy)Read_Short_Number_Between(-1, 2, "This number Out Of Range !#");

	}

	void Welcome_TO_The_Game()
	{
		cout << setw(40) << "### -                 Welcome TO The Game { X _ O }                 - ###\n";
		cout << setw(40) << "                     _______________________________                     \n\n\n\n\n";
		cout << setw(40) << "# The { X } For Player 1      # ********* #      The { O } For Player 2 #\n\n\n";
		cout << "Enter [0] - >   Play (Vs) Computer                       \n";
		cout << "Enter [1] - >   Play (Vs) Player 2                       \n";
		cout << "-____________________________                      \n\n";

		cout << "Enter{_____";
	}

	void Specify_Option_Computer()
	{
		if (HardOrEasy == enHardOrEasy::Hard)
		{
			//In the Event Of a Hard


			if (Count_Play_P == 1)
			{
				if (Player_Option[0] == 5)
				{
					Computer_number = 1;
				}
				else
				{
					Computer_number = 5;
				}

			}
			else if (Count_Play_P == 2)
			{
				if (Player_Option[0] == 5 && Player_Option[1] == 2)
				{
					Computer_number = 8;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 3)
				{
					Computer_number = 7;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 6)
				{
					Computer_number = 4;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 9)
				{
					Computer_number = 4;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 8)
				{
					Computer_number = 2;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 7)
				{
					Computer_number = 3;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 9)
				{
					Computer_number = 4;
				}
				else if (Player_Option[0] == 5 && Player_Option[1] == 4)
				{
					Computer_number = 6;
				}
				//______________________________________
				else if (Player_Option[0] == 1 && Player_Option[1] == 3 || Player_Option[0] == 3 && Player_Option[1] == 1)
				{
					Computer_number = 2;
				}
				else if (Player_Option[0] == 1 && Player_Option[1] == 2 || Player_Option[0] == 2 && Player_Option[1] == 1)
				{
					Computer_number = 3;
				}
				else if (Player_Option[0] == 2 && Player_Option[1] == 3 || Player_Option[0] == 3 && Player_Option[1] == 2)
				{
					Computer_number = 1;
				}
				//______________________________________
				else if (Player_Option[0] == 1 && Player_Option[1] == 7 || Player_Option[0] == 7 && Player_Option[1] == 1)
				{
					Computer_number = 4;
				}
				else if (Player_Option[0] == 1 && Player_Option[1] == 4 || Player_Option[0] == 4 && Player_Option[1] == 1)
				{
					Computer_number = 7;
				}
				else if (Player_Option[0] == 4 && Player_Option[1] == 7 || Player_Option[0] == 7 && Player_Option[1] == 4)
				{
					Computer_number = 1;
				}
				//______________________________________
				else if (Player_Option[0] == 9 && Player_Option[1] == 7 || Player_Option[0] == 7 && Player_Option[1] == 9)
				{
					Computer_number = 8;
				}
				else if (Player_Option[0] == 7 && Player_Option[1] == 8 || Player_Option[0] == 8 && Player_Option[1] == 7)
				{
					Computer_number = 9;
				}
				else if (Player_Option[0] == 9 && Player_Option[1] == 8 || Player_Option[0] == 8 && Player_Option[1] == 9)
				{
					Computer_number = 7;
				}
				//______________________________________
				else if (Player_Option[0] == 3 && Player_Option[1] == 9 || Player_Option[0] == 9 && Player_Option[1] == 3)
				{
					Computer_number = 6;
				}
				else if (Player_Option[0] == 3 && Player_Option[1] == 6 || Player_Option[0] == 6 && Player_Option[1] == 3)
				{
					Computer_number = 9;
				}
				else if (Player_Option[0] == 9 && Player_Option[1] == 6 || Player_Option[0] == 6 && Player_Option[1] == 9)
				{
					Computer_number = 3;
				}
				//______________________________________
				else
				{
					for (short i = 0; i < 9; i++)
					{
						if (Options[i] == ' ')
						{
							Computer_number = i + 1;
						}
					}
				}

			}
			else
			{
				for (short i = 0; i < 9; i++)
				{
					if (Options[i] == ' ')
					{
						Computer_number = i + 1;
					}
				}
				short Copy = 0;
				for (vector <short>& Option : Win_Option)
				{

					if ((Option[0] == Player_Option[0] || Option[0] == Player_Option[1] || Option[0] == Player_Option[2] || Option[0] == Player_Option[3])
						&& (Option[1] == Player_Option[0] || Option[1] == Player_Option[1] || Option[1] == Player_Option[2] || Option[1] == Player_Option[3])
						&& Options[Option[2] - 1] == ' ')
					{
						Computer_number = Option[2];
					}
					else if ((Option[1] == Player_Option[0] || Option[1] == Player_Option[1] || Option[1] == Player_Option[2] || Option[1] == Player_Option[3])
						&& (Option[2] == Player_Option[0] || Option[2] == Player_Option[1] || Option[2] == Player_Option[2] || Option[2] == Player_Option[3])
						&& Options[Option[0] - 1] == ' ')
					{
						Computer_number = Option[0];
					}
					else if ((Option[0] == Player_Option[0] || Option[0] == Player_Option[1] || Option[0] == Player_Option[2] || Option[0] == Player_Option[3])
						&& (Option[2] == Player_Option[0] || Option[2] == Player_Option[1] || Option[2] == Player_Option[2] || Option[2] == Player_Option[3])
						&& Options[Option[1] - 1] == ' ')
					{
						Computer_number = Option[1];
					}
					//______________________________________
					if ((Option[0] == Computer_Option[0] || Option[0] == Computer_Option[1] || Option[0] == Computer_Option[2] || Option[0] == Computer_Option[3])
						&& (Option[1] == Computer_Option[0] || Option[1] == Computer_Option[1] || Option[1] == Computer_Option[2] || Option[1] == Computer_Option[3])
						&& Options[Option[2] - 1] == ' ')
					{
						Computer_number = Option[2];
						Copy = Computer_number;
					}
					else if ((Option[1] == Computer_Option[0] || Option[1] == Computer_Option[1] || Option[1] == Computer_Option[2] || Option[1] == Computer_Option[3])
						&& (Option[2] == Computer_Option[0] || Option[2] == Computer_Option[1] || Option[2] == Computer_Option[2] || Option[2] == Computer_Option[3])
						&& Options[Option[0] - 1] == ' ')
					{
						Computer_number = Option[0];
						Copy = Computer_number;
					}
					else if ((Option[0] == Computer_Option[0] || Option[0] == Computer_Option[1] || Option[0] == Computer_Option[2] || Option[0] == Computer_Option[3])
						&& (Option[2] == Computer_Option[0] || Option[2] == Computer_Option[1] || Option[2] == Computer_Option[2] || Option[2] == Computer_Option[3])
						&& Options[Option[1] - 1] == ' ')
					{
						Computer_number = Option[1];
						Copy = Computer_number;
					}
					//______________________________________
				}
				if (Copy == 0)
				{

				}
				else
				{
					Computer_number = Copy;
				}

			}

		}
		else
		{
			//In the Event Of a Easy
			Srand();
			short number = 4;

			while (Options[number] != ' ')
			{
				number = RandomNumber(0, 8);
			}
			Computer_number = number + 1;

		}
		// Save
		Computer_Option[Count_Play_Computer] = Computer_number;
	}



	void Print()
	{

		printf("#Round [* %d *] \n\n", ++Round_number);
		printf("\t                                                                                       1 |  2  |  3 \n");
		printf("\t                                                                                     ____|_____|____\n");
		printf("\t                                                                                       4 |  5  |  6 \n");
		printf("\t                                                                                     ____|_____|____\n");
		printf("\t                                                                                       7 |  8  |  9 \n");

		printf("\t    %c   |         %c            |     %c   \n", Options[0], Options[1], Options[2]);
		printf("\t________|______________________|__________\n");
		printf("\t        |                      |          \n");
		printf("\t    %c   |         %c            |     %c   \n", Options[3], Options[4], Options[5]);
		printf("\t________|______________________|__________\n");
		printf("\t    %c   |         %c            |     %c   \n", Options[6], Options[7], Options[8]);
		printf("\t        |                      |          \n\n");

	}

public:


	void Start()
	{

		Resaid();
		Welcome_TO_The_Game();
		Is_Computer_Or_Player2() == enComputerOrPlayer2::Player2 ? /*In the Event Of a Player2 */ true : /*In the Event Of a Computer  -> */   Is_Hard_Or_Easy();
		do
		{

			Resaid();
			Print();

			// Player 2
			if (Count_Play_P > Count_Play_P2 && ComputerOrPlayer2 == enComputerOrPlayer2::Player2)
			{

				// Reading Player 2
				do
				{
					Read_Player2();
				} while (Is_Option_Full(Player2_number, Count_Play_P2, 'O'));


				// Checking Player 2
				if (IS_Win_Or_Yate(Player2_Option))
				{
					//  In Win ->  Print 
					Resaid();
					Print();
					system("color 4F");
					return;
				}
			}





			// Computer
			else if (Count_Play_P > Count_Play_Computer && ComputerOrPlayer2 == enComputerOrPlayer2::Computer)
			{
				// Reading Computer
				Specify_Option_Computer();
				Is_Option_Full(Computer_number, Count_Play_Computer, 'O');

				// Checking Computer
				if (IS_Win_Or_Yate(Computer_Option))
				{

					//  In Win ->  Print 
					Resaid();
					Print();
					system("color 8F");
					return;
				}

			}





			// Player 1
			else
			{

				// Reading Player 1
				do
				{
					Read_Player();
				} while (Is_Option_Full(Player_number, Count_Play_P, 'X'));


				// Checking Player 1
				if (IS_Win_Or_Yate(Player_Option))
				{
					//  In Win ->  Print 
					Resaid();
					Print();
					system("color 2F");
					return;
				}
			}


			//While it Doesn't reach the List Possible Option
		} while (Player_Option[4] == 0);


		//In the Event Of a tie
		Resaid();
		Print();
		system("color 6F");
	}

};


int main()
{
	لعبة_X_O Game;
	Game.Start();

	system("pause>0");
	return 0;
}
