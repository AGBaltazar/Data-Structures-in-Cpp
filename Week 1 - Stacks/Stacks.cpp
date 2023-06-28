// Garcia_CS325W1Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Page {
	string title;
	string description;
	string URL;
	string dateAccessed;
};

stack<Page> backStack; // Stack for storing URLs for going back
stack<Page> forwardStack; // Stack for storing URLs for going forward

void goBack() {
	if (!backStack.empty()) {
		forwardStack.push(backStack.top());
		backStack.pop();
		cout << "\nWent back to the previous page.\n\n";
	}
	else {
		cout << "\nCannot go back. No previous pages.\n\n";
	}
}

void goForward() {
	if (!forwardStack.empty()) {
		backStack.push(forwardStack.top());
		forwardStack.pop();
		cout << "Went forward to the next page.\n\n";
	}
	else {
		cout << "Cannot go forward. No next pages.\n\n";
	}
}

void listAllPages() {
	cout << "Pages in the browser history:\n";
	cout << "-----------------------------\n";

	stack<Page> tempStack = backStack;
	while (!tempStack.empty()) {
		Page page = tempStack.top();
		cout << "Title: " << page.title << "\n";
		cout << "Description: " << page.description << "\n";
		cout << "URL: " << page.URL << "\n";
		cout << "Date Accessed: " << page.dateAccessed << "\n";
		cout << "-----------------------------\n\n";
		tempStack.pop();
	}

	cout << "(Current Page)\n";

	tempStack = forwardStack;
	while (!tempStack.empty()) {
		Page page = tempStack.top();
		cout << "Title: " << page.title << "\n";
		cout << "Description: " << page.description << "\n";
		cout << "URL: " << page.URL << "\n";
		cout << "Date Accessed: " << page.dateAccessed << "\n";
		cout << "-----------------------------\n\n";
		tempStack.pop();
	}
}

void addPage() {
	Page newPage;

	cout << "\n\nEnter page title: ";
	cin.ignore(); // Ignore any remaining newline characters in the input buffer
	getline(std::cin, newPage.title);

	cout << "Enter page description: ";
	getline(std::cin, newPage.description);

	cout << "Enter page URL: ";
	getline(std::cin, newPage.URL);

	cout << "Enter date accessed: ";
	getline(std::cin, newPage.dateAccessed);

	backStack.push(newPage);
	cout << "Added new page to the browser history.\n\n";
}

void deletePage() {
	if (!backStack.empty()) {
		backStack.pop();
		cout << "Deleted the current page from the browser history.\n\n";
	}
	else {
		cout << "Cannot delete. No pages in the browser history.\n\n";
	}
}

int main() {
	int menuChoice;

	cout << "Welcome to our Browser!\n";

	while (true) {
		cout << "Please select from the following Menu:\n";
		cout << "1. Go Back\n";
		cout << "2. Go Forward\n";
		cout << "3. List All Pages\n";
		cout << "4. Add Page\n";
		cout << "5. Delete Page\n";
		cout << "Enter your choice: \n\n";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			goBack();
			break;
		case 2:
			goForward();
			break;
		case 3:
			listAllPages();
			break;
		case 4:
			addPage();
			break;
		case 5:
			deletePage();
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}
	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

