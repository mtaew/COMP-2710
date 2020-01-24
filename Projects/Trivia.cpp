//Libary imports.
#include <iostream>
#include <fstream>
#include <cstdlib> //for exit()
#include <assert.h>
#include <climits>
#include <string>
using namespace std;


//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct triva_node {
	string question;
	string answer;
	int point;
	triva_node *next;

};
//creates a pointer to triva_node.
typedef triva_node* ptr_node;

//Prototypes
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void clear(); // method for cin.clear and cin.ignore
void Unit_Test(); // test driver

//keeps track of number of Triva questions.
int num_of_questions;

//creates two versions.
//#define UNIT_TESTING
#define triva_quiz

int main() {

	ptr_node node_list = new triva_node;
	//Creates a new trivia game /
	//Sets up three original  questions/
	//Sets up loop for user to input his or her own questions.
	//Quiz questions are stored in linked list.
#ifdef triva_quiz
	init_question_list(node_list);
	string stop = "Yes";
	cout << "*** Welcome to Tae's trivia quiz game ***\n";
	string test = "test";
	cout << "Enter Test: ";
	getline(cin, test);
	if(test == "test")
		cout << "working";



	while (stop == "Yes" || stop == "yes" || stop == "YES") {
	add_question(node_list);
	cout << "Continue? (Yes/No): ";
	cin >> stop;
	clear();


	}
	//This is start of Trivia quiz game.
	ask_question(node_list, num_of_questions);
	cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
	return 0;
}
#endif
//Method for testing
#ifdef UNIT_TESTING

	Unit_Test();
	return 0;
	}
#endif



//initializes the quiz to have these three questions inputed into the linked list.
void init_question_list(ptr_node& q_list) {
	//ptr_node cur_ptr;
	//ptr_node cur_ptr;
	string bob;
	ptr_node cur_ptr = new triva_node;
	cur_ptr->question = "How long was the shortest war on record?";
	cur_ptr->answer = "38";
	cur_ptr->point = 100;
	cur_ptr->next = new triva_node;
	q_list = cur_ptr;
	cur_ptr = q_list->next;
	cur_ptr->question = "What was Bank of America's original name?(Hint: Bank of Italy or Bank of Germany)?";
	cur_ptr->answer = "Bank of Italy";
	cur_ptr->point = 50;
	cur_ptr->next = new triva_node;
	cur_ptr = cur_ptr->next;
	cur_ptr->question = "What is the best-selling video game of all time?(Hint: Call of Duty or Wii Sports)?";
	cur_ptr->answer = "Wii Sports";
	cur_ptr->point = 20;
	cur_ptr->next = NULL;
	num_of_questions = 3;
}
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
	string answer;
	//gets data from user.
	ptr_node new_ptr = new triva_node;
	cout << "Enter a new question: ";
	getline(cin, new_ptr->question);
	cout << "Enter an answer: ";
	getline(cin, new_ptr->answer);
	cout << "Enter award points: ";
	cin >> new_ptr->point;
	new_ptr->next = q_list;
	q_list = new_ptr;
	num_of_questions++;

}
//Checks for null value
//Ask the user trivia questions and starts the game
//num_ask is the amount of questions to be asked
//Problem: Was not able to fix bug where answer inputed did not
// equal Trivia question answer but only for the original questions set up.
// the user input was adding a Enter to the answer.
//Does work if number of questions asked is less than 1 or more than the amount of trivia questions.
int ask_question(ptr_node q_list, int num_ask) {
	string user_answer;
	string correct_answer;
	int point_total = 0;
	ptr_node cur_ptr;
	cur_ptr = q_list;
	if (q_list == NULL)
		return 0;
	if(num_ask < 1) {
		cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
	}
	else if(num_of_questions < num_ask) {
		cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
	}
	else {
	for(int x = 0; x < num_ask; x++) {
		cout << "Question: " << cur_ptr->question << endl;
		cout << "Answer: ";
		getline(cin, user_answer);
		if (user_answer.compare(cur_ptr->answer) == 0) {//correct_answer) {
			cout << "Your answer is correct! You receive " << cur_ptr->point << " points.\n";
			point_total += cur_ptr->point;
			cout << "Your total points: " << point_total << endl;
		}
		else {
			cout << "incorrect answer, correct answer is " << cur_ptr-> answer  << endl;
			cout << user_answer << cur_ptr->answer;
			cout << "Your total points " << point_total << endl;
		}

	cur_ptr = cur_ptr->next;
	clear();
	}
}

	return 0;

}
//able to make getLine method work.
void clear() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
//Test cases to check weather the methods work.
void Unit_Test() {
	ptr_node node_list = new triva_node;
	init_question_list(node_list);
	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	ask_question(node_list, 0);
	cout << "\nCase 1 Passed\n\n";

	cout << "Unit Test Case 2: Ask 1 question in the linked list.  The tester enters an incorrect answer." << endl;
	ask_question(node_list, 1);
	cout << "Case 2 passed";

	cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list.  The tester enters an correct answer." << endl;
	ask_question(node_list, 1);
	cout << "Case 2.1 passed";

	cout << "\nUnit Test Case 3: Ask all the questions of the last trivia in the linked list."<< endl;
	ask_question(node_list, 3);
	cout << "Case 3 passed";

	cout << "\nUnit Test Case 4: Ask 5 questions in the linked list."<< endl;
	ask_question(node_list, 5);
	cout << "\nCase 4 passed";

	cout << "\n\n*** End of the Debugging Version ***";
}





