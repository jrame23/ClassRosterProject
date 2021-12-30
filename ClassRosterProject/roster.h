#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);

	void add(string sID,
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sAge,
		int sNumDays1,
		int sNumDays2,
		int sNumDays3,
		DegreeProgram studentProgram);
		
	void printAll();
	void printByStudentProgram(DegreeProgram studentProgram);
	void printInvalidEmailAddress();
	void printAverageDaysInCourse(string sID);
	void removeStudentID(string sID);
	~Roster();
};