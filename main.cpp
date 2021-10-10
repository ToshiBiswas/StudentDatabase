#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "program_functions.h"
#include <climits>
#include <algorithm>
using namespace std;


//--------------------------------Manually to be edited
string version = "V1.0";
string dev_team = "Barret Klics, Toshi Biwas, Tanish Datta, Sam Schroeder";
string release_date = "June 16th 2021";
//-----------------------------------------------------------------------------------



int main(){
	
	system("clear");
	
	cout << "Student Registration System: " << version << endl;
	cout << "Developement Team: "<< dev_team << endl;
	cout << "Release Date: " << release_date << endl;
	cout << endl;
	
	enter_wait();
	system("clear");
	
	cout << "Please enter the name of the courses file you would like to use, followed by the students file you would like to use" << endl;
	
	vector<Course> allCourses;
	vector<Student> allStudents;	
	
	if ( ((load_coursefile(get_input(), allCourses)) + (load_studentfile(get_input(), allStudents))) == 0)
	{
		cout << " wrong number of input files " << endl << endl;
	}
	else
	{
		cout << allCourses.size() << " Courses were loaded from courses file " << endl;
		cout << allStudents.size() << " Students were loaded from students file " << endl;		
	}

	while (true)
	{
		buffer_cleaner();	
		enter_wait();
			
		system("clear");
			
		int selection = main_menu();
			
		if ((selection >= 1) && (selection <= 12))
		{
			system("clear");
				
			if (selection == 1)
			{
				cout << "Input students list file name (include extension)" << endl;
				cout << load_studentfile(get_input(), allStudents) << " students added to database from file" << endl;
			}

			if (selection == 2)
			{
				cout << "Input courses list file name (include extension)" << endl;
				cout << load_coursefile(get_input(), allCourses) << " courses added to database from file" << endl;
			}
			
			if (selection == 3)
			{
				cout << "Enter the file you would like to enroll from" << endl;
				enrollment_file(get_input(), allCourses, allStudents);
				nl();
			}

			if (selection == 4)
			{
				cout << "Input ID of course to show:" << endl << endl;
				show_course_details(get_input(), allCourses);
			}

			if (selection == 5)
			{
				cout << "Input ID of student to show:" << endl << endl;
				show_student_details(get_input(), allStudents);
			}
					
			if (selection == 6)
			{
				Course c = create_course();
					
				if (find_course(c.get_cid(), allCourses) != NULL){
					cout << "ERROR: Course ID already exists!" << endl;
				}
				else{
					allCourses.push_back(c);
				}
			}
		
			if (selection == 7)
			{
				Student s = create_student();
					
				if (find_student(s.get_ID(), allStudents) != NULL){
					cout << "ERROR: A student with that ID already exists!" << endl;
				}
				else{
					allStudents.push_back(s);
				}
			}	
			
			if (selection == 8)
			{
				cout << "Enroll a student to a course:" << endl;	

				Student* s = find_student(prompt_get("Enter student ID: "), allStudents);
				Course* c = find_course(prompt_get("Enter course ID: "), allCourses);

				if (s == NULL)
				{
					cout << "A student with that ID is not in the database" << endl;
				}
				else if (c == NULL)
				{
					cout << "That Course is not in the database!" << endl;
				}
				else
				{
					enroll_to_course(s->get_ID(), c->get_cid(), allStudents, allCourses);
							
				}
			}
			
			if (selection == 9)
			{
				string s = prompt_get("Enter student ID: ");
				string c = prompt_get("Enter course ID: ");
				cout << withdraw_from_course(s, c, allStudents, allCourses) << endl;
			}
				
				
			if (selection == 10)
			{
				string s = prompt_get("Enter student ID: ");
				string c = prompt_get("Enter course ID: ");
				double g = prompt_get_double("Enter student grade: ");

				cout << update_grade(s, c, g, allStudents, allCourses) << endl;
			}
			
			if (selection == 11)
			{
				cout << "Saving..." << endl;
				
				if (save(allStudents, allCourses)){
					cout << endl;
				}
				else{
					cout << endl;
					cout << "ERROR: Could not save" << endl;
				}
				cout << "Saving Complete!" << endl;
			}
			
			if (selection == 12)
			{
				cout << "Exiting program, thank you!" << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid selection!" << endl;
			continue;		
		}
	}
}