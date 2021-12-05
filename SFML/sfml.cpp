/*
Cricbuzz is a cricket news website
It features news, articles and live coverage of cricket matches
including videos, text commentary,
player stats and team rankings.


//Details


CricBuzz Application
performs tasks such as Notifications of live matches
breaking news about Cricket
Tournaments happening around you
updated scores
team positions after every match

*/
#include<cstdio>
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<fstream>
using namespace sf;
using namespace std;
class  Player//(an Abstract Class)
{
protected:
	string Name;
	int Shirt_No;
	float Average;
	int ICCRanking_T20; //in each format
	int Matches_played;
	int Total_wickets;
	//additionl functions
	int ICCRanking_ODI; //in each format
	int ICCRanking_TEST; //in each formaT
	int Total_runs;
	int HIGESTSCORE;
	int FiftyScored;
	int CenturyScored;
public:
	//pure virtual function
	Player();
	/*all are called by using derived class objecs in a function
	called Browser Player*/
	void  virtual addPlayer() = 0;
	void  virtual removePlayer() = 0;
	void  virtual searchPlayer() = 0;
	void  virtual updatePlayer() = 0;
	//Match class is able to navigate around all matches throughout the world
	friend class Match;

};
//inherited from team class
class Team :public Player   //( inherit Player Class)
{
protected:
	int No_Players;
	int Totalmatches_won;
	int Totalmatches_lost;
	int ICC_titles;

	//string Name;
	string Teamname;
	string HomeGround;
	string Team_Captain;
	string Team_Coach;
	string Admin_Username;
	string Admin_Password;
	//THEY ARE ACCESED FROM THE FUNCTION BROWSE PLAYER
	string PlayerName[5];
	int shirt[5];
	int avg[5];
	int iccrankt20[5];
	int iccrankodi[5];
	int iccranktest[5];
	int mplayed[5];
	int wickt[5];
	int  higetruns[5];
	int runs[5];
	int fifty[5];
	int century[5];

	//thy are made virtual so they can be called from base class pointer as well



	virtual	void addPlayer();
	virtual	void removePlayer();
	virtual	void searchPlayer();
	virtual	void updatePlayer();
	//they are protected so they can be only acessed when the adming login is sucessful
	
	//an object of match class is passe to it
	virtual	void displayMatches(Match &M1);
	virtual	void DMatch();
	virtual	void updateCaptain();
	virtual	void updateCoach();
	virtual	void TeamInfo();
public:
	Team();
	virtual	void BrowsePlayer();
	//will display the teams name and other attributes
	virtual	void displayTeam(string n);
	//setup the login process system
	virtual	void Login();
	//Match class is able to navigate around all matches throughout the world
	friend class Match;

};

class Match :public Team
{	//Attributes 
protected:
	int t2;
	int Playerrank;
	int teamrank;
	int Team1Points;
	int Team2Points;
	int Team3Points;
	int Team4Points;
	int target;
	int to_be_chased;
	int batball;
	int toss;
	string playername;
	string Team1[5];
	string Team2[5];
	string Date[5];
	string Venue[5];
	string Match_type; //(ODI etc.)
	string Tournament_Name; //(T20 World Cup, IPL, PSL, etc.)
	string Commentators;
	string Umpires;
	string Match_status;  //(upcoming, recent, etc.)

	//Attributes for the best figures
	string  Mostruns;
	string  HighestsScore;
	string  Most_sixes;
	string  Most_fours;
	string  Most_centuries;
	string  Highestbatting_average;
	string  Best_strikerate;
	string  Most_wickets;
	string  Bestbowling;
	string  Bestbowling_avg;


public:
	//	constructor
	Match();
	virtual void MatchDetails();
	virtual	void BestTeam();
	virtual	void DisplayBestTeam();
	virtual	void conductMatch();
	virtual	void scheduleMatch();
	virtual	void updateWorldRecords();
	virtual	void DisplayWorldRecords();
	virtual	void updateTeamRanking();
	virtual	void updatePlayerRanking();
	virtual	void displayUpcomingMatches();
	virtual	void displayRecentMatches();
	virtual	void SingleMatchDetails(string format);
	virtual	void TournamentMatchDetails(string format);
	friend class Team;
};


/*
News
User must be able to browse certain or specified news, photos or videos from
previous matches/tournaments.
User can ask for details of any recently played match, or schedule of upcoming
matches along with date, venue, etc.
User can prompt the search for ICC World Rankings, which can be of an entire
team, a certain user, or a certain category (e.g T20, or Bowling, etc.)
*/

//Team Class Funcions


	//constructors
Player::Player()
{
	Name = "";
	Shirt_No = 0;
	Average = 0;
	ICCRanking_T20 = 0; //in each format
	Matches_played = 0;
	Total_wickets = 0;
	//additionl functions
	ICCRanking_ODI = 0; //in each format
	ICCRanking_TEST = 0; //in each formaT
	Total_runs = 0;
	HIGESTSCORE = 0;
	FiftyScored = 0;
	CenturyScored = 0;
}

Team::Team()
{
	No_Players = 0;
	Totalmatches_won = 0;
	Totalmatches_lost = 0;
	ICC_titles = 0;

	Name = " ";
	HomeGround = " ";
	Team_Captain = "  ";
	Team_Coach = " ";
	Admin_Username = " ";
	Admin_Password = " ";
}
Match::Match()
{
	target = 0;
	batball = 0;
	toss = 0;
	to_be_chased = 0;
	Playerrank = 0;
	teamrank = 0;
	//Attributes for the best figures
	Mostruns = "";
	HighestsScore = "";
	Most_sixes = "";
	Most_fours = "";
	Most_centuries = "";
	Highestbatting_average = "";
	Best_strikerate = "";
	Most_wickets = "";
	Bestbowling_avg = "";
	Bestbowling = "";
	Team2Points = 0;
	Team3Points = 0;
	Team4Points = 0;
	Team1Points = 0;
}

//Team Class Functions

void Team::BrowsePlayer()
{
	Team T;
	bool stop = false;
	string str;
	int task;
	while (stop == false)
	{
		cout << "Press 1 to Add A Player\n"
			<< "Press  2  to Remove A Player\n"
			<< "Press  3  to Search A Player\n"
			<< "Press  4  to Update A Player\n"
			<< "Press 5 to return to Teams Menu\n"
			<< "Press  6  to Exit \n";
		cin >> task;
		switch (task)
		{
		case 1:
			addPlayer();
			break;
		case 2:
			removePlayer();
			break;
		case 3:
			searchPlayer();
			break;
		case 4:
			updatePlayer();
			break;

		case 5:
			T.Login();
			break;
		case 6:
			stop = true;

			break;
		default:
			cout << "Invalid Choice\n";
		}
	}
}
void Team::addPlayer()
{
	int i = 0;
	cout << "Enter Team in Which You Want to Add a Player\n";
	cin >> Teamname;
	cout << "Enter Player  Name\n";
	cin >> PlayerName[i];
	cout << "Enter Player Shirt Number\n";
	cin >> shirt[i];
	cout << "Enter Player  Average\n";
	cin >> avg[i];
	cout << "Enter Player ICC T20 Ranking \n";
	cin >> iccrankt20[i]; //in each format
	cout << "Enter Player ICC ODI Ranking \n";
	cin >> iccrankodi[i]; //in each format
	cout << "Enter Player ICC Test Ranking \n";
	cin >> iccranktest[i]; //in each formaT
	cout << "Enter Player Total MAtches Played \n";
	cin >> mplayed[i];
	cout << "Enter Player Total Wickets \n";
	cin >> wickt[i];
	cout << "Enter Player Total Runs \n";

	cin >> runs[i];
	cout << "Enter Player Higest Score \n";
	cin >> higetruns[i];
	cout << "Enter Player Fifty Scored \n";
	cin >> fifty[i];
	cout << "Enter Player Century Scored \n";
	cin >> century[i];
	i++;
	system("pause");
	system("cls");
}
void Team::removePlayer()
{
	bool stop = true;
	cout << "Enter Team Name\n";
	cin >> Teamname;
	cout << "Enter Player Name You Want to Remove From Team\n";
	cin >> Name;
	for (int i = 0; i < 5; i++&&stop == true)
	{
		if (Name == PlayerName[i])
		{
			PlayerName[i] = " ";

			shirt[i] = 0;

			avg[i] = 0;

			iccrankt20[i] = 0;
			iccrankodi[i] = 0;

			iccranktest[i] = 0;

			mplayed[i] = 0;

			wickt[i] = 0;

			runs[i] = 0;

			higetruns[i] = 0;

			fifty[i] = 0;

			century[i] = 0;
			stop = false;
		}
		else if (stop == false)
		{


			cout << "Player Removed\n";
			break;
		}
		else if (Name != PlayerName[i])
		{
			cout << "Player Not Found\n";
			break;
		}
	}
	system("pause");
	system("cls");
}

void  Team::searchPlayer()
{
	//searching players
	bool stop = true;
	int i;
	cout << "Enter Team Name\n";
	cin >> Teamname;
	cout << "Enter Player Name In Which You Want to Search Player\n";
	cin >> Name;
	for (i = 0; i < 5; i++&&stop == true)
	{
		if (Name == PlayerName[i])
		{
			cout << "Player Found\n";
			cout << "Player Details\n";
			cout << "Player  Name  " << PlayerName[i] << endl;
			cout << "Player Shirt Number  " << shirt[i] << endl;
			cout << "Player  Average " << avg[i] << endl;
			cout << "Player ICC T20 Ranking  " << iccrankt20[i] << endl; //in each format
			cout << "Player ICC ODI Ranking  " << iccrankodi[i] << endl; //in each format
			cout << "Player ICC Test Ranking  " << iccranktest[i] << endl; //in each formaT
			cout << "Player Total MAtches Played " << mplayed[i] << endl;
			cout << "Player Total Wickets " << wickt[i] << endl;
			cout << "Player Total Runs  " << runs[i] << endl;
			cout << "Player Higest Score  " << higetruns[i] << endl;
			cout << "Total Fifty Scored   " << fifty[i] << endl;
			cout << "Total Century Scored  " << century[i] << endl;
			stop = false;
		}

		else if (Name != PlayerName[i])
		{
			cout << "Player Not Found\n";
			break;
		}
	}

	system("pause");
	system("cls");
}
void  Team::updatePlayer()
{

	bool stop = true;
	cout << "Enter Team Name\n";
	cin >> Teamname;
	cout << "Enter Player Name Which You Update Player\n";
	cin >> Name;

	for (int i = 0; i < 5; i++&&stop == true)
	{
		if (Name == PlayerName[i])
		{
			cout << "Player Found\n";
			cout << "Enter Player Updated Details\n";
			cout << "\nEnter Player Shirt Number\n";
			cin >> shirt[i];
			cout << "Enter Player  Average\n";
			cin >> avg[i];
			cout << "Enter Player ICC T20 Ranking \n";
			cin >> iccrankt20[i]; //in each format
			cout << "Enter Player ICC ODI Ranking \n";
			cin >> iccrankodi[i]; //in each format
			cout << "Enter Player ICC Test Ranking \n";
			cin >> iccranktest[i]; //in each formaT
			cout << "Enter Player Total MAtches Played \n";
			cin >> mplayed[i];
			cout << "Enter Player Total Wickets \n";
			cin >> wickt[i];
			cout << "Enter Player Total Runs \n";
			cin >> runs[i];
			cout << "Enter Player Higest Score \n";
			cin >> higetruns[i];
			cout << "Enter Player Fifty Scored \n";
			cin >> fifty[i];
			cout << "Enter Player Century Scored \n";
			cin >> century[i];
			if (Name != PlayerName[i])
			{
				cout << "Player Not Found\n";
				break;
			}

		}


	}
	system("pause");
	system("cls");
}

void Team::DMatch()
{
	cout << "\nTeam Name  " << Name << endl;
	cout << "\nTeam Captain " << Team_Captain << endl;
	cout << "\nTeam Coach  " << Team_Coach << endl;
	cout << "\nHome Ground " << HomeGround << endl;
	cout << "\nTotal ICC Titles " << ICC_titles << endl;
	cout << "\nTotal Players Selected  " << No_Players << endl;
	cout << "\nTotal matches won  " << Totalmatches_won << endl;
	cout << "\nTotal matches Lost  " << Totalmatches_lost << endl;
	ofstream file("Match.txt");
	file << "\nNew Team " << "\n Teamname  " << Name << "\n Team_Captain \n " << Team_Captain << endl << "Team Coach " << Team_Coach << endl
		<< "\nICC_titles  " << ICC_titles << endl << "\nToal Players " << No_Players << endl
		<< "\nHomeGround" << HomeGround << "\nICC titles" << ICC_titles << "\nTotalmatches won" << Totalmatches_won << "Totalmatches lost\n" << Totalmatches_lost << "\n";
	file.close();
	system("pause");
	system("cls");
	system("pause");
	system("cls");
}

void Team::displayMatches(Match &M1)
{
	/*
	(this function will further display all previous and upcoming matches along
with all details)
	*/
	int choice;

	cout << "\nPress 1 to Display Previous Matches\n"
		<< "Press 2 to Display Upcoming Matches\n";
	cin >> choice;
	if (choice == 1)
		M1.displayRecentMatches();

	if (choice == 2)
		M1.displayUpcomingMatches();
}
void Match::displayUpcomingMatches()
{
	cout << "\nUpcoming Matches\n";
	string tp;
	fstream newfile;
	newfile.open("UpcomingMatches.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open())
	{   //checking whether the file is open
		while (getline(newfile, tp))
		{  //read data from file object and put it into string.
			cout << tp << "\n";   //print the data of the string
		}

	}
}
void Match::displayRecentMatches()
{
	cout << "Recent Matches\n";
	string tp;
	fstream newfile;
	newfile.open("PreviousMatches.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open())
	{   //checking whether the file is open
		while (getline(newfile, tp))
		{  //read data from file object and put it into string.
			cout << tp << "\n";   //print the data of the string
		}

	}

	system("pause");
	system("cls");
}

void Team::updateCaptain()
{
	cout << "Enter Team Name with .txt format\n";
	cin >> Name;
	cout << "Enter New Captain \n";
	cin >> Team_Captain;
	ofstream file(Name);
	file << "\nUpdated Captain" << Team_Captain << "\n";
	cout << "CAPTAIN UPDATED\n";
	file.close();
	system("pause");
	system("cls");
}
void Team::updateCoach()
{

	cout << "Enter Team Name .txt format\n";
	cin >> Name;
	cout << "Enter New Coach \n";
	cin >> Team_Coach;
	ofstream file(Name);
	file << "\nUpdated Captain" << Team_Coach << "\n";
	cout << "Coach Updated\n";
	system("pause");
	system("cls");
}

void Team::displayTeam(string n)
{

	/*
	Team Squad
	THE DATA OF ALL THE TEAMS SQUAD IS STROED IN A FILE AND WHEN
	THE USER ENTER A SPECIFIC TEAM ITS SQUAD IS LOADED FROM FILE AND
	DISPLAYED ON CONSOLE
	*/

	cout << "Team Players\n";

	string tp;
	fstream newfile;
	if (n == "PAKISTAN")
	{
		newfile.open("Pakistan.txt", ios::in); //open a file to perform read operation using file object
		if (newfile.is_open())
		{   //checking whether the file is open


			while (getline(newfile, tp))
			{  //read data from file object and put it into string.
				cout << tp << "\n";   //print the data of the string
			}

		}
	}
	//INDIA 
	if (n == "INDIA")
	{
		newfile.open("India.txt", ios::in); //open a file to perform read operation using file object
		if (newfile.is_open())
		{   //checking whether the file is open


			while (getline(newfile, tp))
			{  //read data from file object and put it into string.
				cout << tp << "\n";   //print the data of the string
			}

		}
	}
	//Austrila
	if (n == "AUSTRALIA")
	{
		newfile.open("Australia.txt", ios::in); //open a file to perform read operation using file object
		if (newfile.is_open())
		{   //checking whether the file is open


			while (getline(newfile, tp))
			{  //read data from file object and put it into string.
				cout << tp << "\n";   //print the data of the string
			}

		}
	}

	if (n == "ENGLAND")
	{
		newfile.open("England.txt", ios::in); //open a file to perform read operation using file object
		if (newfile.is_open())
		{   //checking whether the file is open
			while (getline(newfile, tp))
			{  //read data from file object and put it into string.
				cout << tp << "\n";   //print the data of the string
			}

		}
	}
	system("pause");
	system("cls");
}
//display team infi
void Team::TeamInfo()
{
	string tp;
	ifstream newfile;
	newfile.open("Match.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open())
	{   //checking whether the file is open
		while (getline(newfile, tp))
		{  //read data from file object and put it into string.
			cout << tp << "\n";   //print the data of the string
		}

	}

	system("pause");
	system("cls");
}
void Team::Login()
{

	/*
	 Uername = CRICKETWORLD
	 PASS    = CRICKETHOME
	*/
	cout << "Enter Uername \n";
	cin >> Admin_Username;
	//CRICKETWORLD
	while (Admin_Username != "CRICKETWORLD")
	{
		cout << "Incorrect USERNAME\nTry Again\n\nEnter UserName Again\n";
		cin >> Admin_Username;
	}
	cout << "Enter Password\n";
	cin >> Admin_Password;
	while (Admin_Password != "CRICKETHOME")
	{
		cout << "Incorrect Password\nTry Again\n";
		cin >> Admin_Username;
	}
	if (Admin_Username == "CRICKETWORLD"&&Admin_Password == "CRICKETHOME")
	{
		cout << "Login Sucessful \n Autentication Authorized\nNow You Can Acess Team Functions\n";

	}
	Team T1;
	Match M1;
	int choose;
	cout << "PRESS 1 to EDIT PLAYERS DATA\n"
		<< "PRESS  2 to DISPLAY MATCH DATA\n"
		<< "PRESS  3 to UPDATE CAPTAIN\n"
		<< "PRESS  4 to UPDATE COACH\n"
		<< "Press 5 to Dislay Upcoming or Recent Matches\n";
	cin >> choose;
	switch (choose)
	{
	case 1:
		T1.BrowsePlayer();
		break;
	case 2:
		T1.displayMatches(M1);
		break;

	case 3:
		T1.updateCaptain();
		break;
	case 4:
		T1.updateCoach();
		break;
	case 5:
		displayMatches(M1);
	}
	system("pause");
	system("cls");
}
//tournament 
void Match::MatchDetails()
{
	Match M;
	string format;
	int chi;
	cout << "Press 1 to Display Single Match Details\n"
		<< "Press 2 to Display Tournamnet Match Details\n";
	cin >> chi;
	if (chi == 1)

	{
		cout << "Enter Match Format\n";
		cin >> format;
		M.SingleMatchDetails(format);

	}
	if (chi == 2)

	{
		cout << "Enter Match Format\n";
		cin >> format;
		M.TournamentMatchDetails(format);
	}
}
void Match::TournamentMatchDetails(string format)
{
	//this will be called from the conduct match function
	int overs, balls;
	//match 1 team 1 vs team  2 
	cout << "Match Format " << format << endl;
	cout << "Team PAKISTAN vs INDIA \n";
	if (format == "T20")
	{
		overs = 20;
		balls = 20 * 6;
	}
	if (format == "ODI")
	{
		overs = 50;
		balls = 50 * 6;
	}
	cout << "Toss \n";
	cout << "Enter 1 for Tails and 2 for Heads\n";
	cin >> t2;
	toss = (rand() % 2);
	if (toss == 1)
		cout << "Team PAKISTAN Won the Toss \n";
	if (toss == 2)
		cout << "Team INDIA Won the Toss \n";
	cout << "Press 1 to Bat or Press 2 to Ball\n";
	cin >> batball;
	if (batball == 1)
		cout << "You choose to bat First\n";

	if (batball == 2)
		cout << "You choose to bowl First\n";
	/*

	generating target
	by randonmly generating numbers
	in target as well as in the runs chased
	*/

	for (int i = 0; i < balls; i++)
	{
		target = (rand() % 6) + 1;
	}
	cout << "Team INDIA Batting \n";
	for (int i = 0; i < balls; i++)
	{
		to_be_chased = (rand() % 6) + 1;
	}

	if (target > to_be_chased)
	{
		cout << "Team PAKISTAN Won the Match \n";
		Team1Points + 2;
	}

	else
	{
		cout << "Team INDIA Won the Match\n";
		Team2Points + 2;
	}
	//match - 2  //TEAM 3 VS 4
	cout << "Team ENGLAND  vs AUSTRALIA \n";
	if (format == "T20")
	{
		overs = 20;
		balls = 20 * 6;
	}
	if (format == "ODI")
	{
		overs = 50;
		balls = 50 * 6;
	}
	cout << "Toss \n";
	cout << "Enter 1 for Tails and 2 for Heads\n";
	cin >> t2;
	toss = (rand() % 2);
	if (toss == 1)
		cout << "Team ENGLAND Won the Toss \n";
	if (toss == 2)
		cout << "Team AUSTRALIA Won the Toss \n";
	cout << "Press 1 to Bat or Press 2 to Ball\n";
	cin >> batball;
	if (batball == 1)
		cout << "You choose to bat First\n";

	if (batball == 2)
		cout << "You choose to bowl First\n";
	/*

	generating target
	by randonmly generating numbers
	in target as well as in the runs chased
	*/

	for (int i = 0; i < balls; i++)
	{
		target = (rand() % 6) + 1;
	}
	cout << "Team ENGLAND Batting \n";
	for (int i = 0; i < balls; i++)
	{
		to_be_chased = (rand() % 6) + 1;
	}

	if (target > to_be_chased)
	{
		cout << "Team ENGLAND Won the Match \n";
		Team3Points + 2;
	}

	else
	{
		cout << "Team AUSTRALIA Won the Match\n";
		Team4Points + 2;
	}
	//team 1 vs 4
	if (format == "T20")
	{
		overs = 20;
		balls = 20 * 6;
	}
	if (format == "ODI")
	{
		overs = 50;
		balls = 50 * 6;
	}
	cout << "Toss \n";
	cout << "Enter 1 for Tails and 2 for Heads\n";
	cin >> t2;
	toss = (rand() % 2);
	if (toss == 1)
		cout << "Team PAKISTAN Won the Toss \n";
	if (toss == 2)
		cout << "Team AUSTRALIA Won the Toss \n";
	cout << "Press 1 to Bat or Press 2 to Ball\n";
	cin >> batball;
	if (batball == 1)
		cout << "You choose to bat First\n";

	if (batball == 2)
		cout << "You choose to bowl First\n";
	/*

	generating target
	by randonmly generating numbers
	in target as well as in the runs chased
	*/

	for (int i = 0; i < balls; i++)
	{
		target = (rand() % 6) + 1;
	}
	cout << "Team PAKISTAN Batting \n";
	for (int i = 0; i < balls; i++)
	{
		to_be_chased = (rand() % 6) + 1;
	}

	if (target > to_be_chased)
	{
		cout << "Team PAKISTAN Won the Match \n";
		Team1Points + 2;
	}

	else
	{
		cout << "Team AUSTRALIA Won the Match\n";
		Team4Points + 2;
	}

	//team 2 vs 3
	if (format == "T20")
	{
		overs = 20;
		balls = 20 * 6;
	}
	if (format == "ODI")
	{
		overs = 50;
		balls = 50 * 6;
	}
	cout << "Toss \n";
	cout << "Enter 1 for Tails and 2 for Heads\n";
	cin >> t2;
	toss = (rand() % 2);
	if (toss == 1)
		cout << "Team INDIA Won the Toss \n";
	if (toss == 2)
		cout << "Team ENGLAND Won the Toss \n";
	cout << "Press 1 to Bat or Press 2 to Ball\n";
	cin >> batball;
	if (batball == 1)
		cout << "You choose to bat First\n";

	if (batball == 2)
		cout << "You choose to bowl First\n";
	/*

	generating target
	by randonmly generating numbers
	in target as well as in the runs chased
	*/

	for (int i = 0; i < balls; i++)
	{
		target = (rand() % 6) + 1;
	}
	cout << "Team INDIA Batting \n";
	for (int i = 0; i < balls; i++)
	{
		to_be_chased = (rand() % 6) + 1;
	}

	if (target > to_be_chased)
	{
		cout << "Team ENGLAND Won the Match \n";
		Team3Points + 2;
	}

	else
	{
		cout << "Team INDIA Won the Match\n";
		Team2Points + 2;
	}

}
void Match::SingleMatchDetails(string format)
{
	//this will be called from the conduct match function
	int overs, balls;
	cout << "Match Format " << format << endl;
	if (format == "T20")
	{
		overs = 20;
		balls = 20 * 6;
	}
	if (format == "ODI")
	{
		overs = 50;
		balls = 50 * 6;
	}
	cout << "Toss \n";
	cout << "Enter 1 for Tails and 2 for Heads\n";
	cin >> t2;
	toss = (rand() % 2);
	if (toss == 1)
		cout << "Team Pakistan Won the Toss \n";
	if (toss == 2)
		cout << "Team INDIA Won the Toss \n";
	cout << "Press 1 to Bat or Press 2 to Ball\n";
	cin >> batball;
	if (batball == 1)
		cout << "You choose to bat First\n";
	if (batball == 2)
		cout << "You choose to bowl First\n";
	/*

	generating target
	by randonmly generating numbers
	in target as well as in the runs chased
	*/

	for (int i = 0; i < balls; i++)
	{
		target = (rand() % 6) + 1;
	}
	cout << "Team 2 Batting \n";
	for (int i = 0; i < balls; i++)
	{
		to_be_chased = (rand() % 6) + 1;
	}

	if (target > to_be_chased)
	{
		cout << "Team PAKISTAN Won the Match \n";
		Team1Points + 2;
	}

	else
	{
		cout << "Team INDIA Won the Match\n";
		Team2Points + 2;
	}
}
//Match Class Functions
void   Match::conductMatch()
{

	cout << "Conducting Already Sheduled Match\n";
	int j = 0;
	int k = 0, i = 0;
	int chi;
	cout << "Press 1 to Conduct a Single MAtch\n"
		<< "Press  2 to Conduct  a Tournament\n";
	cin >> chi;
	switch (chi)
	{
	case 1:
		cout << "Single Match\n";
		j = 0;
		k = 0;
		cout << "\nMatch " << j + 1 << "Details\n";

		cout << "Team 1 of Match  " << Team1[i] << endl;
		cout << "Team 2 of Match  " << Team2[i] << endl;
		cout << "Match Date  " << Date[i] << endl;
		cout << "Match Venue " << Venue[i] << endl;
		cout << "Match Format " << Match_type << endl; //(ODI etc.)
		cout << "Commentators  " << Commentators << endl;
		cout << "Umpire  " << Umpires << endl;
		cout << "Match Status " << Match_status << endl;
		i++;
		j++;
		break;

	case 2:
		j = 0;
		k = 0;
		cout << "Tournament Name " << Tournament_Name << endl;
		cout << "Match Format " << Match_type << endl; //(ODI etc.)
		cout << "Commentators  " << Commentators << endl;
		cout << "Umpire  " << Umpires << endl;
		for (i = 0; i < 4; i++)
		{
			cout << "\n\n Match  " << j + 1 << "  Details \n";
			cout << "Team 1 of Match  " << Team1[i] << endl;
			cout << "Team 2 of Match  " << Team2[i] << endl;
			cout << "Match Date  " << Date[i] << endl;
			cout << "Match Venue  " << Venue[i] << endl;
			j++;
		}
		break;
	}


	system("pause");
	system("cls");
}
void   Match::scheduleMatch()
{
	Match M;
	int k = 0, i = 0;
	int chi;
	cout << "Press 1 to Shedule a Single MAtch\n"
		<< "Press  2 to Shedule  a Tournament\n";
	cin >> chi;
	switch (chi)
	{

	case 1:
		cout << "\nAvilable Teams\n"
			<< "\n  PAKISTAN\n  INDIA\n  AUSTRALLIA\n  ENGLAND\n";
		k = 0;
		cout << "Single Match\n";
		cout << "\nEnter New Match Details\n";
		cout << "Enter Team 1 of Match \n";
		cin >> Team1[i];
		cout << "Enter Team 2 of Match\n";
		cin >> Team2[i];
		cout << "Enter Match Date\n";
		cin >> Date[i];
		cout << "Enter Match Venue\n";
		cin >> Venue[i];
		cout << "Enter Match Format \nT20\nODI\nTest\n";
		cin >> Match_type; //(ODI etc.)
		cout << "Enter Commentators\n";
		cin >> Commentators;
		cout << "Enter Umpire\n";
		cin >> Umpires;
		cout << "Enter Match Status\n";
		cin >> Match_status;
		k++;
		break;
	case 2:
		cout << "\nAvilable Teams\n"
			<< "\n  PAKISTAN\n  INDIA\n  AUSTRALLIA\n  ENGLAND\n";
		k = 0;
		cout << "Enter Tournament Name\n";
		cin >> Tournament_Name;
		cout << "Enter Match Format\n";
		cin >> Match_type;
		cout << "Enter Match Commentators\n";
		cin >> Commentators;
		cout << "Enter Match Umpire\n";
		cin >> Umpires;
		for (i = 0; i < 4; i++)
		{
			cout << "\nAvilable Teams\n"
				<< "\n  PAKISTAN\n  INDIA\n  AUSTRALLIA\n  ENGLAND\n";
			cout << "\nEnter New Match Details\n";
			cout << "Enter Team 1 of Match \n";
			cin >> Team1[i];
			cout << "Enter Team 2 of Match\n";
			cin >> Team2[i];
			cout << "Enter Match Date\n";
			cin >> Date[i];
			cout << "Enter Match Venue\n";
			cin >> Venue[i];

		}
		break;
	}
	//writing the details of match to file
	int cho;
	cout << "Do you Want to Conduct a Match\n"
		<< "Press 1 to Conduct Match or Press 2 to Return to Main Menu\n";

	cin >> cho;
	if (cho == 1)
	{
		M.conductMatch();
	}
	system("pause");
	system("cls");
}


void Match::DisplayWorldRecords()
{
	string tp;
	ifstream newfile;
	newfile.open("WorldRecord.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open())
	{   //checking whether the file is open
		while (getline(newfile, tp))
		{  //read data from file object and put it into string.
			cout << tp << "\n";   //print the data of the string
		}

	}
}
void Match::updateWorldRecords()
{
	cout << "\n\n UPDATING WORLD RECORDS \n\n";
	cout << "Enter Team name\n";
	cin >> Name;
	cout << "Enter Most Runs\n";
	cin >> Mostruns;
	cout << "Enter Higest Runs\n";
	cin >> HighestsScore;
	cout << "Enter Most Sixes\n";
	cin >> Most_sixes;
	cout << "Enter Most Fours\n";
	cin >> Most_fours;
	cout << "Enter Most Centuries\n";
	cin >> Most_centuries;
	cout << "Enter   Highest batting average\n";
	cin >> Highestbatting_average;
	cout << "Enter Best Strike Rate\n";
	cin >> Best_strikerate;
	cout << "Enter Most Wickets\n";
	cin >> Most_wickets;
	cout << "Enter Best Bowling Average\n";
	cin >> Bestbowling_avg;
	cout << "Enter Best Bowling Figures\n";
	cin >> Bestbowling;
	//writing details to file
	ofstream file("WorldRecord.txt");
	file << "\nWorld--Record\n" << "\nTeam Name " << Name << "\nHIGE STSCORE " << HIGESTSCORE << "\nMost sixes " << Most_sixes << endl << "Most fours " << Most_fours << endl
		<< "Most_centuries " << Most_centuries << "\n Highestbatting_average " << Highestbatting_average << "\n Best_strikerate " << Best_strikerate << endl
		<< "Most_wickets " << Most_wickets << "\n Bestbowling_avg " << Bestbowling_avg << endl;
	file.close();
	system("pause");
	system("cls");
}
void Match::BestTeam()
{
	cout << "Enter Team  Name\n";
	cin >> Name;
	cout << "Enter Player Name for  Most Runs in Series \n";
	cin >> Mostruns;
	cout << "Enter Higest Runs Scored \n";
	cin >> HighestsScore;
	cout << "Enter Most Sixes\n";
	cin >> Most_sixes;
	cout << "Enter Most fours\n";
	cin >> Most_fours;
	cout << "Enter Most Centuries\n";
	cin >> Most_centuries;
	cout << "Enter Higest Batting Averge\n";
	cin >> Highestbatting_average;
	cout << "Enter Best Strike Rate\n";
	cin >> Best_strikerate;
	cout << "Enter Most Wickets\n";
	cin >> Most_wickets;
	cout << "Enter Best Bowling Average\n";
	cin >> Bestbowling_avg;
	cout << "Enter best bowler\n";
	cin >> Bestbowling;
	ofstream file("BestTeam.txt", ios::app);
	file << "Team  Name " << Name << "\nBest Bowler " << Bestbowling
		<< "\nHigest Runs in Series " << Mostruns << "\nMax Score in Match " << HIGESTSCORE
		<< "\n Most Sixes " << Most_sixes << " Most Fours " << Most_fours << " \n Most Centuries" << CenturyScored
		<< "\n Higest Batting Averge " << Highestbatting_average << "\nBest Strike Rate  " << Best_strikerate
		<< "Most Wickets " << Most_wickets << "\n Enter Best Bowling Average " << Bestbowling_avg
		<< "\n best bowler" << Bestbowling << endl;
	file.close();
	cout << "\n\nTeam Rank Updated\n";
	system("pause");
	system("cls");
}
void Match::DisplayBestTeam()
{
	string tp;
	ifstream newfile;
	newfile.open("BestTeam.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open())
	{   //checking whether the file is open
		while (getline(newfile, tp))
		{  //read data from file object and put it into string.
			cout << tp << "\n";   //print the data of the string
		}

	}
}

void Match::updateTeamRanking()
{
	cout << "Enter Team  Name\n";
	cin >> Name;
	cout << "Enter Updated Ranking of TeamRanking in .txt format \n";
	cin >> teamrank;
	ofstream file(Name, ios::app);
	file << "Updated Rank of Team\n" << Playerrank << endl;
	file.close();
	cout << "\n\nTeam Ranking Updated\n";
	system("pause");
	system("cls");
}

void   Match::updatePlayerRanking()
{
	cout << "Enter Team  Name with .txt format \n";
	cin >> Name;
	cout << "Enter the Updated Ranking of Player  \n";
	cin >> Playerrank;
	ofstream file(Name, ios::app);
	file << "\nPlayer Name " << Name << "\nUpdated Rank of Player \n" << Playerrank << endl;
	file.close();
	cout << "\n\nPlayer Ranking Updated\n";
	system("pause");
	system("cls");
}
int main()
{
	system("color 2");
	string n;
	RenderWindow window(VideoMode(900, 600), " WELCOME CRIC BUZZ! ");
	//RenderWindow window(VideoMode(756, 367), "Welcome");
	//Music music;
	//if (!music.openFromFile("C1.ogg"))
	//{
	//	cout << "file not loaded\n";

	//}
	//music.setVolume(100);
	//music.play();
	// WELCOME
	
	RectangleShape w(Vector2f(900.0f, 600.0f));
	w.setPosition(0, 0);
	Texture wTexture;
	wTexture.loadFromFile("W.jpg");
	w.setTexture(&wTexture);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(w);
		window.display();
	}
	bool stop = true;
	int i = 0, choice = 0;
	Match Match1;
	Team Team1;
	for (i = 0; i < 59; i++)
	{

		cout << "\t@==@";
		Sleep(15);

	}
	//best teams
	//dispy  worldrec and update world rec
	cout << "+";
	cout << "\n\t\t\t\t|   Welcome To CRIC BUZZ\t" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t" << endl;
	Sleep(15);
	while (stop == true)
	{
		cout << "\t\t\t\t| \tPRESS ---> '1' TO Login Teams\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '2' TO Shedule Match\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '3' TO Conduct Match\t\t" << endl;

		cout << "\t\t\t\t| \tPRESS ---> '4' TO SetBest Team\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '5' TO Display Best Team\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '6' TO Update World Record \t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> 7' TO Display World Record\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '8' TO START Match \t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '9' TO DISPLAY TEAMS\t\t" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '10' BROWSE PLAYER DATA\t\t\t|" << endl;
		Sleep(15);
		cout << "\t\t\t\t| \tPRESS ---> '11' For EXIT\t\t\t|" << endl;
		Sleep(15);
		cout << "\t\t\t\t+-----------------------------------------------+" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			
				Team1.Login();
			break;
		case 2:
			Match1.scheduleMatch();
			break;
		case 3:
			Match1.conductMatch();


			break;

		case 4:
			Match1.BestTeam();
			break;

		case 5:
			Match1.DisplayBestTeam();
			break;

		case 6:

			Match1.updateWorldRecords();
			break;

		case 7:
			if (choice == 7)
			{
				RenderWindow window(VideoMode(900, 600), " NEWS");
				RectangleShape nn(Vector2f(900.0f, 600.0f));
				nn.setPosition(0, 0);
				Texture nnTexture;
				nnTexture.loadFromFile("N.jpg");
				nn.setTexture(&nnTexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(nn);
					window.display();
				}
			}
			Match1.DisplayWorldRecords();
			break;

		case 8:
			Match1.MatchDetails();
			break;

		case 9:
			cout << "\n Enter team Name: ";
			cin >> n;
			if (n == "PAKISTAN")
			{
				RenderWindow window(VideoMode(900, 600), " PAKISTAN TEAM!");
				RectangleShape pak(Vector2f(900.0f, 600.0f));
				pak.setPosition(0, 0);
				Texture pakTexture;
				pakTexture.loadFromFile("P.jpg");
				pak.setTexture(&pakTexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(pak);
					window.display();
				}
				Team1.displayTeam(n);
			}
			if (n == "ENGLAND")
			{
				RenderWindow window(VideoMode(900, 600), "ENGLAND TEAM!");
				RectangleShape E(Vector2f(900.0f, 600.0f));
				E.setPosition(0, 0);
				Texture ETexture;
				ETexture.loadFromFile("E.jpg");
				E.setTexture(&ETexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(E);
					window.display();
				}
				Team1.displayTeam(n);
			}
			if (n == "AUSTRALIA")
			{
				RenderWindow window(VideoMode(900, 600), "AUSTRALIA TEAM!");
				RectangleShape AA(Vector2f(900.0f, 600.0f));
				AA.setPosition(0, 0);
				Texture AATexture;
				AATexture.loadFromFile("A.jpg");
				AA.setTexture(&AATexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(AA);
					window.display();
				}
				Team1.displayTeam(n);
			}
			if (n == "INDIA")
			{
				RenderWindow window(VideoMode(900, 600), "INDIA !");
				RectangleShape II(Vector2f(900.0f, 600.0f));
				II.setPosition(0, 0);
				Texture IITexture;
				IITexture.loadFromFile("I.jpg");
				II.setTexture(&IITexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(II);
					window.display();
				}
				Team1.displayTeam(n);
			}
			break;
		
		case 10:
			if (choice == 10)
			{
				RenderWindow window(VideoMode(900, 600), " BROWSE PLAYER!");
				RectangleShape bb(Vector2f(900.0f, 600.0f));
				bb.setPosition(0, 0);
				Texture bbTexture;
				bbTexture.loadFromFile("B.jpg");
				bb.setTexture(&bbTexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(bb);
					window.display();
				}
			}
				break;
			
		case 11:
			if (choice == 11)
			{
				RenderWindow window(VideoMode(900, 600), " THANK YOU");
				RectangleShape tt(Vector2f(900.0f, 600.0f));
				tt.setPosition(0, 0);
				Texture ttTexture;
				ttTexture.loadFromFile("T.jpg");
				tt.setTexture(&ttTexture);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}

					window.clear();
					window.draw(tt);
					window.display();
				}
			}
			stop = false;
			break;
		default:
			cout << "Invalid Entry\n";
		}
	}

	for (i = 0; i < 59; i++)
	{

		cout << "\t@==@";
		Sleep(15);

	}
}




