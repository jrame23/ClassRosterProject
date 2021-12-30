#include "roster.h"

int main()
{
	cout << "C867 Scripting and programming applications, C++, ID:000999024, Jacob c. Ramey" << std::endl << std::endl;
		const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jacob,Ramey,jrame23@wgu.edu,21,30,40,35,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying all Students: " << std::endl;
	roster.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << std::endl;
		roster.printByStudentProgram((DegreeProgram)i);
	}

	cout << "Displaying all Invalid Student Email Addresses" << std::endl;
	roster.printInvalidEmailAddress();
	cout << std::endl;

	cout << "Displaying average number of days in courses: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
	}

	cout << "Removing Student with ID number: A1, A2, A3, due to an invalid email input: " << std::endl;
	roster.removeStudentID("A1");
	roster.removeStudentID("A2");
	roster.removeStudentID("A3");
	cout << std::endl;



	return 0;
}
