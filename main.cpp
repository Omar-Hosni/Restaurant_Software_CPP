/*
Name:Mohamed Emad
Id:1191102751
Lab: 87G
Title: Restuarant/Eatery
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


void menu() {
	//displaying food items choices for the user
	//maximum items to order is 5 items
	cout << "Welcome to our Restaurant, please choose something to eat\n";
	cout << "you can order up to 5 items\n";
	cout <<"----------------------------------"<<endl;
	cout << "1-Pizza - 5 dollars" << endl;
	cout << "2-Pasta - 7 dollars" << endl;
	cout << "3-Shawarma - 3 dollars" << endl;
	cout << "4-Sushi - 8 dollars" << endl;
	cout <<"----------------------------------"<< endl;
}

int process(int choice[], int n) {

	//declaring variable to count total of payment
	int total = 0;
	int price;
	//declaring file and type of data to store in 
	ifstream file;
	file.open("order.txt", ios::in);
	string food=" ";

	//looping through the array to read the user's input for restaurants order
	for (int i = 0; i < n; ++i) {

		cout << "choose the items you want to eat: ";
		cin >> choice[i];

		//if-else statements to determine the user's order list
		switch (choice[i]) {
		case 1: 
				total += 5;
				price = 5;
				food = "pizza\n";
				file.open("order.txt", ios::in);
				file >> food;
				cout << "you chose a pizza, your total payment is " << total << endl;
				break;

		case 2:
				total += 7;
				price = 7;
				food = "pasta\n";
				file.open("order.txt", ios::in);
				file >> food;
				cout << "you chose a pasta, your total payment is " << total << endl;
				break;

		case 3:
				total += 3;
				price = 3;
				food = "shawarma\n";
				file.open("order.txt", ios::in);
				file >> food;
				cout << "you chose a shawarma, your total payment is " << total << endl;
				break;

		case 4:
				total += 8;
				price = 8;
				food = "sushi\n";
				file.open("order.txt", ios::in);
				file >> food;
				cout << "you chose a sushi, your total payment is " << total << endl;
				break;

		default:
				cout << "choose a number from the menu" << endl;
				break;
		}
	}
	//read file content
	fstream readfile;
	readfile.open("order.txt", ios::app);
	readfile << food;


	//casting total payment to double using iomanip library
	return static_cast<double>(total);
	
}

//setting the amount of tips for waiters
int tips_to_leave(int tips) {
	return tips;
}

//asking the user to input their opinion of restaurant's quality
void rating(int n) {
	string rate;
	for (int i = 0; i < n; ++i) {
		cout << "enter your " << i+1 << " comment: ";
		cin >> rate;
		
	}

	cout << "Thanks for your evaluation to our restaurant, your comments over our quality will help us imporve" << endl;
}

int main() {
	//declaring variables and constants
	int comments_amount;
	const int length = 4;
	int tips;
	int* arr{ new int[length] {} };

	
	menu();
	process(arr, length);
	delete arr;
	
	//injecting the data into the file
	ifstream myfile;
	myfile.open("order.txt", ios::in);


	//asking the user for comments over quality
	cout << "how many comments do you want to give for rating: ";
	cin >> comments_amount;
	rating(comments_amount);

	//function for leaving tips for waiters
	cout << "leave tips for the waiter: ";
	cin >> tips;
	tips_to_leave(tips);

	
}
