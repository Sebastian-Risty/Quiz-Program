/*
 * Name: Sebastian Risty
 * Date: 10/29/2020
 * File: HW5.cpp
 * Description: Quiz program using classes. (get it?)
 *
 */

#include <iostream>
#include <string>
#include <random> 
#include <ctime> 

using namespace std;
class Question {
public:
    //vars
    string question;
    string answers[3];
    double numDisplayed;
    double numCorrect = 0;
    int correctAnswer;
    //method to calculate percent correct for certain question object
    double percentCorrect() {
        if (numDisplayed == 0) {
            return 0;
        }
        return (numCorrect / numDisplayed) * 100;
    }
    //class constructor (how I make the questions)
    Question(string q, string a0, string a1, string a2, int answer) {
        question = q;
        answers[0] = a0;
        answers[1] = a1;
        answers[2] = a2;
        correctAnswer = answer;
        numDisplayed = 0;
        numCorrect = 0;
    }
};

void menu();
void printQuestion(Question q);
void quiz(Question qList[]);
void stats(Question qList[]);

int main() {
    //10 questions with their possible answers and the correct answer 
    Question q0("What is 2+2?", "2", "4", "fish?", 2);
    Question q1("What is 144 in hex?", "0x90", "0x144", "0x12", 1);
    Question q2("What is the best color?", "Red", "Blue", "Green", 1);
    Question q3("What is the best element?", "Carbon", "Darmstadtium", "Strontium", 3);
    Question q4("What bird can turn its head 270 degrees?", "Starling", "Owl", "Mourning Dove", 2);
    Question q5("What frog species was introduced to australia as a pest control for sugarcane crop in the early 1900's?", "Rhinella marina", "Bufo marinus", "Crinia signifera", 2);
    Question q6("What constellation is messier-15 apart of?", "Little Dipper", "Hydra", "Pegasus", 3);
    Question q7("How many calories are in a Starbuck Double Espresso and Cream beverage?", "140", "200", "80", 1);
    Question q8("How long can David Blaine hold his breath?", "10 min", "4 min", "17 min", 3);
    Question q9("What is the average voltage output of a lemon battery?", "9 volts", "2 volts", "15 volts", 1);
    //make array of objects
    Question qList[] = { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9 };
    //display menu
    menu();
    //take user input
    int userInput;
    cin >> userInput;
    //blocking loop, takes user input
    while (userInput != 3) {
        if (userInput == 1) {
            quiz(qList);
            menu();
            cin >> userInput;
        }
        if (userInput == 2) {
            stats(qList);
            menu();
            cin >> userInput;
        }
        //if wrong input just wait for correct input
        cin >> userInput;
    }
    return 0;
}
//the menu
void menu() {
    cout << "1. Take quiz" << endl;
    cout << "2. View question statistics" << endl;
    cout << "3. Quit" << endl;
}
//prints the question and the possible answers
void printQuestion(Question q) {
    cout << q.question << endl;
    cout << "1.) " << q.answers[0] << " 2.) " << q.answers[1] << " 3.) " << q.answers[2] << endl;
}

void quiz(Question qList[]) {
    //vars
    int userInput;
    int randNum[3];
    double tempNumCorrect;
    //randomly pick 3 questions from our list and make sure there are no repeats. (p.s. this is super hard coded for 10 questions but isn't difficult to make it usable for any number of q's)
    for (int i = 0; i < 3; i++) {
        srand(time(0));
        randNum[i] = rand() % 9;
        if (i == 1) {
            while (randNum[i - 1] == randNum[i]) {
                randNum[i] = rand() % 9;
            }
        }
        if (i == 2) {
            while (randNum[i - 1] == randNum[i] || randNum[i - 2] == randNum[i]) {
                randNum[i] = rand() % 9;
            }
        }
    }
    //ask user to answer each question and display each question
    cout << "Please use the keys 1, 2, and 3 to answer the prompts" << endl;
    for (int i = 0; i < 3; i++) {
        printQuestion(qList[randNum[i]]);
        cin >> userInput;
        //store whether or not the question was answered correctly and also store how many questions were answered correctly for just this quiz.
        if (qList[randNum[i]].correctAnswer == userInput) {
            qList[randNum[i]].numCorrect += 1;
            tempNumCorrect += 1;
        }
        qList[randNum[i]].numDisplayed += 1;
    }
    cout << "You got a " << (tempNumCorrect / 3) * 100 << "%" << endl;
}
//loop through our object array and display the information stored within each objects class
void stats(Question qList[]) {
    for (int i = 0; i < 9; i++) {
        cout << "Q: " << qList[i].question << endl;
        cout << "Total Correct: [" << qList[i].numCorrect << "] Total: [" << qList[i].numDisplayed << "] Percent Correct: [" << qList[i].percentCorrect() << "%]" << endl << endl;
    }
}