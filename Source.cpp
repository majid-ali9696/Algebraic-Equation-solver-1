#include<conio.h>
#include<iostream>
using namespace std;
#include<math.h>
#include<string>
#include<stack>
bool check(string s1){ //this function check for validation of polynomial function

	char i; int j = 0;
	char symb;

	for (int i = 0; i < s1.length(); i++){
		if (s1[i] == '+' && s1[i + 1] == '+' || s1[i] == '-' && s1[i + 1] == '-' || s1[i] == '+' && s1[i + 1] == '-' || s1[i] == '-' && s1[i + 1] == '+')
		{
			return false;
		}



	}


	
	stack<char>  s;
	bool valid = true;

	while (j <= 20)
	{
		symb = s1[j];
		if (symb == '(' || symb == '{' || symb == '{')
		{
			s.push(symb);
		}
		if (symb == ')' || symb == '}' || symb == ']')
		{
			if (s.empty() == -1)
			{
				valid = false;
				break;
			}
			else
			{

				i = s.top();
				s.pop();
				if (i == '(' && symb == ')' || i == '{' && symb == '}' || i == '[' && symb == ']')
				{
					valid = true;
				}
				else{
					valid = false;
				}

			}
		}
		j++;
	}
	if (valid == true)
	{
		return true;
		
	}
	else
	{
		return false;
		

	}



}
void linear(int a, int b)
{

	cout << "the root of the equation is" << -b / a;


}
void quadratic(float a, float b, float c)
{
	float x1, x2, determinant, realPart, imaginaryPart;

	determinant = b*b - 4 * a*c;

	
	x1 = (-b + sqrt(determinant)) / (2 * a);
	x2 = (-b - sqrt(determinant)) / (2 * a);
	cout << "the root of the equation are" << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
}
void degree(string exp){   //this function calculate the degree of function 

     
	int check = 0;
	int check1 = 0;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == 'x')
		{
			check = int(exp[i + 1] - '0');
			if (check1 < check){
				check1 = check;

			}

		}


	}
	cout << "the equation is of order = " << check1 << endl;




}




void main(){

	string exp1;
	cout << "enter the expression" << endl;
	cin >> exp1;
	degree(exp1);
	bool check1;
	check1 = check(exp1);
	if (check1 == 1){

		cout << "the expression is valid" << endl;
	}
	else{
		cout << "the expression is invalid " << endl;
	}
    
	
	quadratic(1,5,6);


	_getch();

}