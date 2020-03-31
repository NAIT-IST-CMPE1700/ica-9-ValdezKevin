#pragma once

typedef struct Student
{
	char* name;				//Used for names of students
	int ID;					//Used for ID for students
	float mark;				//Used for marks for students
	struct Student* next;	//Uses struct as pointer
}Student;

//Used for creating ID, marks, names
Student* createList(int ID, float marks, char* name);

//Utilizing struct as a pointer to create size of list
Student* CreateList(int size);

//Method used for setting ID's in order
void IDOrder(Student* head);

//Method used for setting marks in order
void MarkOrder(Student* head);

//Methods use for display
void Display(Student* head, int searchID, float searchMark);

//Method used for user menu
void UserMenu();

//Used for setting names
static const char names[10][15] = { "Kevin", "Evan", "Dyaln", "Henry", "Bruno", "Jeremiah", "Carl", "Sam", "Justin", "Jack" }; 
