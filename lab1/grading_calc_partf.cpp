#include <iostream>

using namespace std;

int main() {
 // Some variables to get you going
   double homework1 = 0, homework2 = 0, homework3 = 0;
   double quiz1 = 0, quiz2 = 0, quiz3 = 0;
   double exam1 = 0, exam2 = 0, finalexam = 0;
   double homeworksAvg, quizzesAvg, examsAvg;
   double homeworksFinal, quizzesFinal, examsFinal, finalExamFinal;
   double sum;

   cout << "Homework 1: ";
   cin >> homework1;
   cout << "Homework 2: ";
   cin >> homework2;
   cout << "Homework 3: ";
   cin >> homework3;

   cout << "Quiz 1: ";
   cin >> quiz1;
   cout << "Quiz 2: ";
   cin >> quiz2;
   cout << "Quiz 3: ";
   cin >> quiz3;

   cout << "Exam 1: ";
   cin >> exam1;
   cout << "Exam 2: ";
   cin >> exam2;
   cout << "Final Exam: ";
   cin >> finalexam;

   // find average of homeworks, quizzes, and exams then multiply by percentages

   homeworksAvg = (homework1 + homework2 + homework3) / 3;
   quizzesAvg = (quiz1 + quiz2 + quiz3) / 3;
   examsAvg = (exam1 + exam2) / 2;

   homeworksFinal = (homeworksAvg) * 0.3;
   quizzesFinal = (quizzesAvg) * 0.1;
   examsFinal = (examsAvg) * 0.3;
   finalExamFinal = finalexam * 0.3;

   sum = homeworksFinal + quizzesFinal + examsFinal + finalExamFinal;

   cout << "Final Score is: " << sum << endl;


   return 0;
}
