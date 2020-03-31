#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void clrscr()
{
	system("@cls||clear");
}

int main()
{
	//Creates list of 10
	Student* start= CreateList(10);

	char uInput = '0';    //Used for user input

	while (uInput != '5')
	{
		//clrscr();

		//Initiates user input to zero
		uInput='0';

		//Shows user menu
		UserMenu();

		//Scans for user input
		scanf_s("%c", &uInput,sizeof(char));

		switch (uInput)
		{
			//Displays the ID of students in order
		case '1':
			IDOrder(start);
			Display(start, NULL, 0);
			break;

			//Displays student marks in order
		case '2':
			MarkOrder(start);
			Display(start, NULL, 0);
			break;

			//Displays all student info
		case '3':
			Display(start, NULL, 0);
			break;

			//Displays passing students
		case '4':
			Display(start, NULL, 50);
			break;

			//Closes program
		default:
			exit(EXIT_SUCCESS);
			break;
		}
		getchar();
	}
}