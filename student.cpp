#include <vector>
#include <string>
#include "date.h"
#include "course.h"


#include <iostream>
using namespace std;


//PRIVATE

		// function to find course name in the course_list. useful for the modify grade function
int Student::find_course(string c_name){
	for (unsigned int i =0; i < course_list.size(); i++){
		if (course_list[i].reg_course->get_cid() == c_name)
			return i;
	}
	return -1;
}

//PUBLIC
// constructors and destructor
Student::Student(){
	Fname = "zero";
	Lname = "zero";
	phone= "zero";
	ID= "zero";
	Date birthday;
}
Student::Student(string first, string last, string cell, string uid, Date birth){
	Fname = first;
	Lname = last;
	phone= cell;
	ID= uid;
	birthday = birth;
}
Student::~Student(){}
		
//setters
void Student::set_Fname(string Fn){
	Fname= Fn;
}
void Student::set_Lname(string ln){
	Lname= ln;
}
void Student::set_phone(string cell){
	phone = cell;
}
void Student::set_ID(string uid){
	ID = uid;
}
void Student::set_Date(Date bd){
	birthday = bd;
}	
//getters
string Student::get_Fname(){
	return Fname;
}
string Student::get_Lname(){
	return Lname;
}
string Student::get_phone(){
	return phone;
}
string Student::get_ID(){
	return ID;
}
Date Student::get_Date(){
	return birthday;
}

vector<string> Student::get_enrolled_courses(vector<Course>& clist){
	vector<string> enrolled;
	for (unsigned int i = 0; i < clist.size(); i++){
		if ((this->find_course(clist.at(i).get_cid())) != -1){
			enrolled.push_back(clist.at(i).get_cid());
		}
	}
	return enrolled;		
}

		
// function to add a course record to the vector course_list. to be called by the course object
void Student::add_course(Course* course_to_add, double g){
	
	int has = find_course(course_to_add->get_cid());
	if (has == -1)
	{
		course_record add;
		
		add.reg_course = course_to_add;
		add.grade = g;
		course_list.push_back(add);
	}
}

// removes a course from the course list. to be called by the course object
void Student::drop_course( Course* course_to_drop){
	int i = find_course(course_to_drop->get_cid());
	
	//if (i != NULL)
		course_list.erase(course_list.begin()+i);
}

//function to modify a grade for a given course name. to be called by the course object
void Student::modify_grade( Course* course_to_add, double grade_update){
	int i = find_course(course_to_add->get_cid());
	
	course_to_add->update_grade(this->get_ID(), grade_update);
	course_list[i].grade = grade_update;
}

// returns a formated string of the student information. the format follows the example provided in the suplementary material
string Student::student_info(){
	string info;
	info.append("\n");	
	info.append("Student id: "); info.append(this->get_ID());
	info.append("\n");
	info.append("First name: "); info.append(this->get_Fname()); info.append("		"); info.append("Last name: "); info.append(this->get_Lname());
	info.append("\n");
	
	info.append("Phone number: "); info.append(this->get_phone());
	info.append("\n" );
	info.append("Birth date: "); info.append(this->get_Date().date_string());
	info.append("\n");
	info.append("Course list:\n ");
	info.append("\tCourse ID \tGrade\n");
	long unsigned int counter = 0;
	while (counter<course_list.size()){
		info.append("\t"); info.append(this->course_list[counter].reg_course->get_cid()); info.append("\t"); info.append(to_string(this->course_list[counter].grade));
		info.append("\n");
		counter++;
	}
	return info;
}
// Student id:
// Firstname:      Last name:
// constant number:
// birth date:
// courses list:
//       course name           grade
//        ENSF337				92
			