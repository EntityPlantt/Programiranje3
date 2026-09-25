#include "../impl.hpp"
#include <iostream>
using namespace std;

static constexpr char monthstr[][4] = {"???", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
	footballer pandev;
	pandev.name = "Goran";
	pandev.surname = "Pandev";
	pandev.clubname = "Parma (last)";
	pandev.birthdate.year = 1983;
	pandev.birthdate.month = 7;
	pandev.birthdate.day = 27;
	cout << "Footballer:\n" << pandev.name << ' ' << pandev.surname << "\nClub: " << pandev.clubname
		<< "\nBorn on " << pandev.birthdate.day << ' ' << monthstr[pandev.birthdate.month] << ", "
		<< pandev.birthdate.year << endl;
}