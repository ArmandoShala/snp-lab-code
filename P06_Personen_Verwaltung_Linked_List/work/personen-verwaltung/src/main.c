/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include "list.h"
#include "person.h"

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char *argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE

	char command = ' ';
	//while ((c = getchar()) != '\n' && c != EOF);
	

	while ( toupper(command) != 'E' )
	{
		printf("Geben sie eine der Folgenden Eingaben ein:\n");
		printf("\nI für Insert\nR für Remove\nS für Show\nC für Clear\nE für End\n\n");
		scanf("%s", &command);
		//command = getchar();
		command = toupper(command);
		//printf("das comand ist %c\n", command);
		switch (command)
		{
			case 'I':
				printf("Das command ist %c\n", command);
				char firstName[NAME_LEN];
				char name[NAME_LEN];
				unsigned int age;
				printf("Vorname:\n");
				scanf("%21s", &firstName);
				printf("Nachname:\n");
				scanf("%21s", &name);
				printf("Alter:\n");
				scanf("%3d", &age);

				insert_sorted(make_person(firstName, name, age));
				break;
			case 'R':
				printf("Das command ist %c\n", command);
				firstName[NAME_LEN] = "";
				name[NAME_LEN] = "";
				age = 0;
				printf("Vorname:\n");
				scanf("%21s", &firstName);
				printf("Nachname:\n");
				scanf("%21s", &name);
				printf("Alter:\n");
				scanf("%3d", &age);

				remove_person(make_person(firstName, name, age));
				break;
			case 'S':
				printf("Das command ist %c\n", command);
				print_list();
				break;
			case 'C':
				printf("Das command ist %c\n", command);
				clear();
				break;
			case 'E':
				printf("Abbruch!\n");
				break;
			default:
			printf("Die Eingabe ist ungültig\n");
				break;
		}
	} 

	// END-STUDENTS-TO-ADD-CODE
	return EXIT_SUCCESS;
}
