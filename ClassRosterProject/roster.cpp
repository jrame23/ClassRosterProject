#include "roster.h"

void Roster::parse(string studentData)
{
	int rhs = studentData.find(","); /*find comma*/
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1; /*moves us past the og comma*/
	rhs = studentData.find(",", lhs);
	string sFirstName = studentData.substr(lhs, rhs - lhs);//firstname

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sLastName = studentData.substr(lhs, rhs - lhs);//lastname

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sEmailAddress = studentData.substr(lhs, rhs - lhs);//E mail

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));//Age

	lhs = rhs + 1; //keep going
	rhs = studentData.find(",", lhs);
	int numDays1 = stod(studentData.substr(lhs, rhs - lhs)); /*first numdays*/
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int numDays2 = stod(studentData.substr(lhs, rhs - lhs));/*second numdays*/
	lhs = rhs + 1;
	int numDays3 = stod(studentData.substr(lhs, rhs - lhs));/*third numdays*/

	DegreeProgram studentProgram = SECURITY;
	if (studentData.back() == 'K') studentProgram = NETWORK;
	else if (studentData.back() == 'E') studentProgram = SOFTWARE;


	

	add(sID, sFirstName, sLastName, sEmailAddress, sAge, numDays1, numDays2, numDays3, studentProgram);
}



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, DegreeProgram studentProgram)
{
	int daysInCourse[3] = { numDays1, numDays2, numDays3 };


	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, studentProgram);/*use full constructor*/
}

/*display all students using tab separated output*/
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}


/*display only students who match a given type*/
void Roster::printByStudentProgram(DegreeProgram studentProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == studentProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

//each email must contain an '@' a '.' and have no spaces " " //
void Roster::printInvalidEmailAddress()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) 
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find(" ") != string::npos || emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos)
		{
			any = true;
			cout << emailAddress << ": " << classRosterArray[i]->getStudentID() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string sID)
{
	for (int i = 0; i <= Roster::lastIndex; ++i) 
	{
		if (classRosterArray[i]->getStudentID() == sID)
		{
			cout << sID << ":";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
		}
	}
}

void Roster::removeStudentID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " Removed from class roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}


Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Deleting studentID " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}