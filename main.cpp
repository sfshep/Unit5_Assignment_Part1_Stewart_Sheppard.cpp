// Stewart Sheppard
// Unit 5 Assignment Part 1
// COCS 1436 - 57002
//Calculate weekly pay

#include <iostream>
#include <string>
#include <locale>
#include <iomanip> 
using namespace std;

//function prototype
double weeklyPay (double, double, string, int);



int main() 
{
          cout << fixed << setprecision(2);
          cout << weeklyPay (47, 505.75, "Fred", 1);
          cout << weeklyPay (45, 55.25, "Melivin", 1);
          cout << weeklyPay (15, 65.25, "Susan", 2);
          cout << weeklyPay (41, 14.75, "Mika", 1);
          cout << weeklyPay (25, 15.00, "Eldridge", 2);
          cout << weeklyPay (55, 203.50, "Freedom", 1);
          cout << weeklyPay (32.5, 100.25,"Dr_T", 1);

          double weeklyPay (double, double, string, int);

  return 0;
}

double weeklyPay (double hours, double rate, string name, int empType)
{
  double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
  double ss = 0.062, med = 0.0145, sSwages = 0.0, medWages = 0.0;
  double FIT = 0.0, fitTax = 0.0, dental =  0.0, retirement = 0.0;
  double clockHours = 40.0, overtimeRate = 2.0, overTimeIfAny = 0.0;
  locale loc;
  string status = "";
  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(32) +";4m"; //green and underlined
  string color2 = "x1b[" + to_string(34) + ";1m"; //blue

  //display the name on screen CAP and in colore
  cout << color << endl;  //format a new line before each name
  for(int i = 0; i < name.length(); i++ )
  {
    cout << toupper(name[i],loc);
  }
  cout << reset << endl;

//determine employment status
  status = (empType ==1) ? "Full Time" : "PartTime"; //set status
  cout << "\ttStatus:" << status << endl;
  cout << "\tHours Worked: " << hours << "Rate: $" << rate << endl;

  overTimeIfAny = ((hours -clockHours) > 0.0) ? (hours - clockHours) : 0.0;
  if (empType == 1) //overtime for fulltime employees only
  {
    
  }















}

