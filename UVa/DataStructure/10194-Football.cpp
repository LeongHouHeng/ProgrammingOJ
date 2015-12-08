
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

struct team{
	string name;
	int teamRank;
	int totalPoint;
	int gamesPlayed;
	int wins;
	int ties;
	int losses;
	int goalDifference;
	int goalsScored;
	int goalsAgainst;

};

vector<string> split(string str, char delim){
	vector<string> internal;
	stringstream ss(str);
	string tok;

	while(getline(ss, tok, delim)){
		internal.push_back(tok);
	}
	return internal;
}


bool struct_cmp(team a, team b){
	if(a.totalPoint != b.totalPoint)
		return a.totalPoint > b.totalPoint;
	if(a.wins != b.wins)
		return a.wins > b.wins;
	if((a.goalsScored - a.goalsAgainst) != (b.goalsScored - b.goalsAgainst))
		return (a.goalsScored - a.goalsAgainst) > (b.goalsScored - b.goalsAgainst);
	if(a.goalsScored != b.goalsScored)
		return a.goalsScored > b.goalsScored;
	if(a.gamesPlayed != b.gamesPlayed)
		return a.gamesPlayed < b.gamesPlayed;
	string ta, tb;
	for(int i = 0; i < a.name.size(); i++){
		ta += toupper(a.name[i]);
	}
	for(int i = 0; i < b.name.size(); i++){
		tb += toupper(b.name[i]);
	}
	return ta < tb;
}

int main(){
	int format;
	scanf("%d", &format);
	while(format--){
		cin.ignore();
		int teamNum;
		struct team tm;
		vector<team> teams; 

		string competName;
		getline(cin, competName);
		//cout << "getline" << endl;
		cin >> teamNum;
		int count = 0;
		while(teamNum--){
			teams.push_back(team());
			cin.ignore();
			getline(cin, teams[count].name);
			count ++;
		}
		//cout << teams.size() << endl;
		string teamA, teamB;
		int teamAsource, teamBsource;
		vector<string> splitedStr3;
		vector<string> splitedStr2;
		vector<string> splitedStr;
		int compet;
		cin >> compet;
		while(compet--){
			cin.ignore();
			
			string compet_input;
			getline(cin, compet_input);
			
			splitedStr = split(compet_input, '@');
			splitedStr2 = split(splitedStr[0], '#');
			splitedStr3 = split(splitedStr[1], '#');
			
			//asdf#2@1#qwer
			//splitedStr2[0]: asdf [1]: 2
			//splitedStr3[0]: 1 [1]: qwer
			//cout << "splitedStr2[0]: " << splitedStr2[0] << " [1]: " << splitedStr2[1] << endl;
			//cout << "splitedStr3[0]: " << splitedStr3[0] << " [1]: " << splitedStr3[1] << endl;
			teamA = splitedStr2[0];
			teamB = splitedStr3[1];
			teamAsource = stoi(splitedStr2[1]);
			teamBsource = stoi(splitedStr3[0]);
			//cout << "------------ " << teamA << "------------" << endl;
			if(teamAsource > teamBsource){
				for(int i = 0; i < teams.size(); i++){
					if(teams[i].name == teamA){
						teams[i].wins++;
						teams[i].totalPoint += 3;//teamAsource;
						teams[i].gamesPlayed ++;
						teams[i].goalsScored += teamAsource;
						teams[i].goalsAgainst += teamBsource;
					}
					if(teams[i].name == teamB){
						teams[i].losses++;
						teams[i].totalPoint += 0;//teamBsource;
						teams[i].gamesPlayed ++;
						teams[i].goalsScored += teamBsource;
						teams[i].goalsAgainst += teamAsource;

					}
				}
			}
			if(teamAsource < teamBsource){
				for(int i = 0; i < teams.size(); i++){
					if(teams[i].name == teamB){
						teams[i].wins++;
						teams[i].totalPoint += 3;//teamBsource;
						teams[i].gamesPlayed ++;
						teams[i].goalsScored += teamBsource;
						teams[i].goalsAgainst += teamAsource;

					}
					if(teams[i].name == teamA){
						teams[i].losses++;
						teams[i].totalPoint += 0;//teamAsource;
						teams[i].gamesPlayed ++;
						//teams[i].goalsScored += teamAsource;
						teams[i].goalsAgainst += teamBsource;

					}
				}
			}
			if(teamAsource == teamBsource){
				for(int i = 0; i < teams.size(); i++){
					if(teams[i].name == teamA){
						teams[i].ties++;
						teams[i].totalPoint += 1;//teamAsource;
						teams[i].gamesPlayed ++;
						teams[i].goalsScored += teamAsource;
						teams[i].goalsAgainst += teamBsource;
						
					}
					if(teams[i].name == teamB){
						teams[i].ties++;
						teams[i].totalPoint += 1;//teamBsource;
						teams[i].gamesPlayed ++;
						teams[i].goalsScored += teamBsource;
						teams[i].goalsAgainst += teamAsource;

					}
				}
			}

		}

		//sort
		sort(teams.begin(), teams.end(), struct_cmp);
		//Output answer
		cout << competName << endl;
		for(int i = 0; i < teams.size(); i++){
			cout << i+1 << ") " << teams[i].name << " " << teams[i].totalPoint << "p, " << teams[i].gamesPlayed << "g (" << teams[i].wins << "-" << teams[i].ties << "-" << teams[i].losses << "), " << (teams[i].goalsScored-teams[i].goalsAgainst) << "gd (" << teams[i].goalsScored << "-" << teams[i].goalsAgainst << ")" << endl;
		}

	}


	return 0;
}
