#include "list.h"
#include <stdio.h>
#include <stdlib.h>


Student* createList(int ID, float marks, char* name)
{
	Student* newNode = (Student*)malloc(sizeof(Student));
	newNode->name = name;
	newNode->ID = ID;
	newNode->mark = marks;
	newNode->next = NULL;
	return newNode;
}

//Create a list of student ID, grade and name 
Student* CreateList(int sise)
{
	srand(time(NULL));
	int ranGen = rand() % 100 + 1;
	int ranGenID = rand() % 1000 + 1;
	
	Student* start = createList(ranGenID, ranGen, names[0]);
	Student* current = start;

	for (int i = 1; i < sise; i++)
	{
		ranGen = rand() % 100 + 1;
		int ranGenID = rand() % 1000 + 1;
		current->next = createList(ranGenID, ranGen, names[i]);
		current = current->next;
	}
	return start;
}

//Displays student ID in order
void IDOrder(Student* head)
{
	Student* curnt = head;
	Student* temp;

	while (curnt!=NULL)
	{
		temp = curnt->next != NULL ? curnt->next : NULL;
		while (temp != NULL)
		{
			if (curnt->ID > temp->ID)
			{
				Student tempData = { curnt->name,curnt->ID,curnt->mark };
				curnt->ID = temp->ID; curnt->mark = temp->mark; curnt->name = temp->name;
				temp->ID = tempData.ID; temp->mark = tempData.mark; temp->name = tempData.name;
			}
			temp = temp->next;
		}
		curnt = curnt->next;
	}
}

//Displays students marks in order
void MarkOrder(Student* head)
{
	Student* curnt = head;
	Student* temp;

	while (curnt != NULL)
	{
		temp = curnt->next != NULL ? curnt->next : NULL;
		while (temp != NULL)
		{
			if (curnt->mark < temp->mark)
			{
				Student tempData = { curnt->name,curnt->ID,curnt->mark };
				curnt->ID = temp->ID; curnt->mark = temp->mark; curnt->name = temp->name;
				temp->ID = tempData.ID; temp->mark = tempData.mark; temp->name = tempData.name;
			}
			temp = temp->next;
		}
		curnt = curnt->next;
	}
}

//Displays students with marks over 50%
void Display(Student* display, int searchID, float searchMark)
{
	Student* current = display;

	while (current != NULL)
	{
		if (current->ID != searchID && searchID != NULL)
		{
			current = current->next;
			continue;
		}
		if (current->mark < searchMark && searchMark >= 0)
		{
			current = current->next;
			continue;
		}
		printf("\n");
		printf("\nID: %i", current->ID);
		printf("\nName: %s",current->name); //printf(current->name);
		printf("\nMark: %.1f", current->mark);
		current = current->next;
	}
}

//Displays user options
void UserMenu()
{
	printf("\n\nInput 1 to display ID Numbers in order\n");
	printf("Input 2 to display student grades\n");
	printf("Input 3 to display all information\n");
	printf("Input 4 to display student marks above 50%\n\n");
	printf("Enter your choice: ");
}