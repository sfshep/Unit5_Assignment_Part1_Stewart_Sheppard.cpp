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
          cout << weeklyPay (47, 505.75, "Fred", 1) << endl;
          cout << weeklyPay (45, 55.25, "Melivin", 1) << endl;
          cout << weeklyPay (15, 65.25, "Susan", 2) << endl;
          cout << weeklyPay (41, 14.75, "Mika", 1) << endl;
          cout << weeklyPay (25, 15.00, "Eldridge", 2) << endl;
          cout << weeklyPay (55, 203.50, "Freedom", 1) << endl;
          cout << weeklyPay (32.5, 100.25,"Dr_T", 1) << endl;

          double weeklyPay (double, double, string, int);
          

//Extending Code - Part 2 or 3

//display "TCC-TR IS COOL" in all lower case
 
  cout << endl; 
  locale loc; 
  string coolPhrase = "TCC-TR IS COOL";
  for(int i = 0; i < coolPhrase.length(); i++ )
  {
    cout << tolower(coolPhrase[i], loc);
  }
  cout  << endl;

// display "i will succeed at c++" in upper case letters
  cout << endl;
  string upperPhrase = "i will succeed at c++";
  for (int i = 0; i < upperPhrase.length(); i++)
  {
    cout << toupper(upperPhrase[i], loc);
  }
  cout << endl;


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
  string color = "\x1b[" + to_string(32) + ";4m"; //green and underlined
  string color2 = "\x1b[" + to_string(34) + ";1m"; //blue

  //display the name on screen CAP and in color
  cout << color << endl;  //format a new line before each name
  for(int i = 0; i < name.length(); i++ )
  {
    cout << toupper(name[i],loc);
  }
  cout << reset << endl;

//determine employment status
  status = (empType ==1) ? "Fulltime" : "Parttime"; //set status
  cout << "\tStatus:" << status << endl;
  cout << "\tHours Worked: " << hours << " Rate: $" << rate << endl;

  overTimeIfAny = ((hours -clockHours) > 0.0) ? (hours - clockHours) : 0.0;
  if (empType == 1) //overtime for fulltime employees only
  {
   cout << "\tOvertime Hours: " << overTimeIfAny << endl; 
  }

  FIT = (rate < 15.0) ? 0.12 : 0.15; //set FIT based upon rate
  cout << "\tFIT Rate: " << FIT << endl;
  dental = (empType ==1) ? 17.00 : 0.00; // deduction for fulltime emp.
  retirement = (empType ==1) ? 77.00 : 0.00; //dedcution for fulltime emp.


  grossPay = (hours <= clockHours) ? (hours * rate) :
            ((clockHours * rate) + ((overTimeIfAny) * (overtimeRate * rate)));


  cout << "Gross Pay: $" << grossPay;
  taxableWages = grossPay - (dental + retirement);
  fitTax = taxableWages * FIT; //less pre-tax deductions

  sSwages = grossPay * ss;
  medWages = grossPay * med;

  //print deductionscout
  cout << color2 << "\n\tDEDUCTIONS (preTax):" << reset << endl;
  cout << "\tDental Deductions: $" << dental << "\n\tRet. Deduction: $" << retirement << endl;
  cout << "Taxable Wages (for FIT): $" << taxableWages << endl;
  cout << color2 << "\tDEDUCTIONS:" << reset << endl;
  cout << "\tFIT Tax Amount: $" << fitTax << endl;

  cout << "\tSSDed = $" << sSwages << " MedDed = $" << medWages << endl;

  netPay = grossPay - (dental + retirement + fitTax + sSwages + medWages);

  cout << "NET PAY for " << name << " "<< color << "$";

  return netPay;


}  

