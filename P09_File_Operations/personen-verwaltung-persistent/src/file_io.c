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

#include "file_io.h"
#include "person.h"
#include "list.h"

void perror_and_exit(const char *context) { perror(context); exit(EXIT_FAILURE); } // das muss noch an einen anderen Ort, scia

void store_person_list(void)
{
	char* fileName = "person_list.csv";
	FILE *f = fopen (fileName, "w");

   store_person_list_to_file(f);
	if (fclose(f) != 0) perror_and_exit("fclose");
}

void store_person_list_to_file(FILE  *fs)
{
	char person_csv_string[60];

	person_t* person = list_getFirst();
	while(person != NULL) {
		person_to_csv_string(person,person_csv_string);
		fprintf(fs,"%s\n",person_csv_string);
		person = list_getNext();
	} 
}



void load_person_list(void)
{
	char* fileName = "person_list.csv";
	FILE *f = fopen (fileName, "r");

	if (f == NULL) 
	{
		f = fopen (fileName, "w");
	}
	else
	{
   	load_person_list_from_file(f);
	}
	if (f == NULL) perror_and_exit("fopen");

	if (fclose(f) != 0) perror_and_exit("fclose");
}

void load_person_list_from_file(FILE *fs)
{
	const int buf_size = 60;
	char person_csv_string[buf_size];
	person_t person;
	int r = 0;
	char* rs = 0;

	do {
      rs= fgets(person_csv_string, buf_size,fs);
     	if(rs !=NULL){
			person_from_csv_string(&person,person_csv_string);
	   	list_insert(&person);
		} 
	} while(rs !=0);
}
