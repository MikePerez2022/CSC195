#pragma once
class Employee
{
public:
	const float TAX = 0.3f;

	char name[33];
	int age = 0;
	

	
	//move back to public
private:
	float hoursPerDay[7];
	unsigned int daysWorked = 0;
	unsigned int totalHours = 0;
	float grossPay = 0; 
	float netPay = 0; 
	float wage = 0; 

public:
	Employee();
	void Read();
	void Write();
};

