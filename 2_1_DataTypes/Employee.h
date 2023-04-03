#pragma once
class Employee
{
public:
	char name[28];
	int age = 0;
	float hoursPerDay[7];
	

public:
	Employee();
	void Read();
	void Write();
};

