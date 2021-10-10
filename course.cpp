#include <iostream>
#include "date.h"
#include "student.h"
#include <vector>
using namespace std;


//Constructors/destructors

Course::Course(){	
}

Course::Course(string id, Date s, Date e, int max){
	Cid = id;
	start = s;
	end = e;
	capacity = max;

}
Course::~Course(){}
//-------------------------------------------


//getters
string Course::get_cid(){
	return Cid;
}
Date Course::get_StartDate(){
	return start;
}
Date Course::get_EndDate(){
	return end;
}
int Course::get_max(){
	return capacity;
}
//

string Course::course_info(){
	string rtn;
	rtn.append("Course ID: "); rtn.append(Cid);
	rtn.append("\n");
	rtn.append("Start date: "); rtn.append(start.date_string());
	rtn.append("\n");	
	rtn.append("End date: "); rtn.append(end.date_string());	
	rtn.append("\n");
	rtn.append("Capcatiy: "); rtn.append(to_string(capacity));
	rtn.append("\n");
	
	rtn.append("Enrolled: "); rtn.append(to_string(student_list.size()));	
	rtn.append("\n");
	rtn.append("List of students:");	

	rtn.append("\n");		
	rtn.append("		"); rtn.append("Student name"); rtn.append("	"); rtn.append("Grade");
		
	for (unsigned int i = 0; i < student_list.size(); i++)
	{	
		rtn.append("\n");		
		rtn.append("		"); rtn.append(student_list[i].student->get_Fname()); rtn.append(" "); rtn.append(student_list[i].student->get_Lname());
		rtn.append("		"); rtn.append(to_string(student_list[i].grade));
	}
		//Course ID: ENSF337
		//Start date: 5/5/2021
		//End date: 6/17/2021
		//Capacity: 70
		//Enrolled: 0
		//List of students:
		//        Student name    Grade

	return rtn;

}

void Course::enroll(Student* S_obj){
	
	
	int has = this->find_student(S_obj->get_ID());
	if (has == -1){
		student_list.push_back({S_obj, 0});	
	}
	
	
	
}
		// looks up the student id in the student list and removes the student from the student list and also updates the course list of the student object, be carefull with the sequence of how you do this.
void Course::withdraw(string uid){
	
	int i = this->find_student(uid);
	if (i != -1)
	{
		Student* s = student_list[find_student(uid)].student;	
		s->drop_course(this);
		student_list.erase(student_list.begin() + i);
	}
	
}


// modifies the grade of the student in the course. note that the grade must be updated in the course object and the corresponding student object
void Course::update_grade(string uid, double g){
	int i = this->find_student(uid);
	student_list[i].grade = g;
}

//private
int Course::find_student(string id){
	
	for (unsigned int i = 0; i < student_list.size(); i++){

		if (student_list[i].student->get_ID() == id){
			return i;
		}
		
	}
	return -1;
}
