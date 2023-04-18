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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"

// 2022-04-18
#include <list.h>

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK   EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

// setup & cleanup
static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

// tests
static void test_person_compare(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange

	person_t person_first;
	strcpy(person_first.name, "Alfons");
	strcpy(person_first.first_name, "Albert");
	person_first.age = 1;

	person_t person2;
	strcpy(person2.name, "Alfons");
	strcpy(person2.first_name, "Albert");
	person2.age = 120;

	person_t person3;
	strcpy(person3.name, "Alfons");
	strcpy(person3.first_name, "Zachary");
	person3.age = 1;

	person_t person4;
	strcpy(person4.name, "Zuboff");
	strcpy(person4.first_name, "Albert");
	person4.age = 1;

	person_t person_last;
	strcpy(person_last.name, "Zuboff");
	strcpy(person_last.first_name, "Zachary");
	person_last.age = 120;

	// act
	// CU_FAIL("missing test");
	
	// assert
	CU_ASSERT_EQUAL(person_compare(&person_first, &person_first), 0);
	CU_ASSERT_EQUAL(person_compare(&person_last, &person_last), 0);
	CU_ASSERT_TRUE(person_compare(&person_first, &person_last) < 0);
	CU_ASSERT_TRUE(person_compare(&person_last, &person_first) > 0);

	CU_ASSERT_TRUE(person_compare(&person2, &person_first) > 0);
	CU_ASSERT_TRUE(person_compare(&person3, &person_first) > 0);
	CU_ASSERT_TRUE(person_compare(&person4, &person_first) > 0);
	CU_ASSERT_TRUE(person_compare(&person4, &person2) > 0);
	CU_ASSERT_TRUE(person_compare(&person4, &person3) > 0);
	CU_ASSERT_TRUE(person_compare(&person_last, &person3) > 0);

	CU_ASSERT_TRUE(person_compare(&person2, &person_last) < 0);
	CU_ASSERT_TRUE(person_compare(&person3, &person_last) < 0);
	CU_ASSERT_TRUE(person_compare(&person4, &person_last) < 0);
	CU_ASSERT_TRUE(person_compare(&person2, &person4) < 0);
	CU_ASSERT_TRUE(person_compare(&person3, &person4) < 0);
	CU_ASSERT_TRUE(person_compare(&person3, &person_last) < 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_insert(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person;
	strcpy(person.name, "Alfons");
	strcpy(person.first_name, "Albert");
	person.age = 20;
	insert_sorted(person);
	//node_t root;
	//root.content = person;

	person_t person2;
	strcpy(person2.name, "Zuboff");
	strcpy(person2.first_name, "Zachary");
	person2.age = 30;
	insert_sorted(person2);

	person_t person3;
	strcpy(person3.name, "Alfons");
	strcpy(person3.first_name, "Zachary");
	person3.age = 1;
	insert_sorted(person3);

	// act
	//CU_FAIL("missing test");
	
	// assert
	node_t root;
	root = get_testing_head();
	// expected Order:
	// Albert Alfons 20
	// Zachary Alfons 1
	// Zachary Zuboff 30

	//printf("\n\n%s\n", root.content.first_name);
	//printf("\n%d\n", strcmp(root.content.first_name, "Albert"));
	CU_ASSERT_EQUAL(strcmp(root.content.first_name, "Albert"), 0);
	CU_ASSERT_EQUAL(strcmp(root.content.name, "Alfons"),0);
	CU_ASSERT_EQUAL(root.content.age, 20);
	//printf("\n%d\n\n", strcmp(root.next->content.first_name, "Zachary"));
	CU_ASSERT_EQUAL(strcmp(root.next->content.first_name, "Zachary"),0);
	CU_ASSERT_EQUAL(strcmp(root.next->content.name, "Alfons"),0);
	CU_ASSERT_EQUAL(root.next->content.age, 1);
	//CU_ASSERT_EQUAL(person_compare(&root.next->next->content, &person3), 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person;
	strcpy(person.name, "Alfons");
	strcpy(person.first_name, "Albert");
	person.age = 20;
	insert_sorted(person);

	person_t person2;
	strcpy(person2.name, "Zuboff");
	strcpy(person2.first_name, "Zachary");
	person2.age = 30;
	insert_sorted(person2);

	person_t person3;
	strcpy(person3.name, "Alfons");
	strcpy(person3.first_name, "Zachary");
	person3.age = 1;
	insert_sorted(person3);

	// act
	//CU_FAIL("missing test");
	node_t root;
	root = get_testing_head();
	// expected Order:
	// Albert Alfons 20
	// Zachary Alfons 1
	// Zachary Zuboff 30

	// assert
	CU_ASSERT_EQUAL(person_compare(&root.content, &person), 0);
	CU_ASSERT_EQUAL(person_compare(&root.next->content, &person3), 0);
	CU_ASSERT_EQUAL(person_compare(&root.next->next->content, &person2), 0);
	remove_person(person3);
	// expected Order:
	// Albert Alfons 20
	// Zachary Zuboff 30
	CU_ASSERT_EQUAL(person_compare(&root.content, &person), 0);
	CU_ASSERT_EQUAL(person_compare(&root.next->content, &person2), 0);
	
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person;
	strcpy(person.name, "Alfons");
	strcpy(person.first_name, "Albert");
	person.age = 20;

	person_t person2;
	strcpy(person2.name, "Zuboff");
	strcpy(person2.first_name, "Zachary");
	person2.age = 30;
	insert_sorted(person2);

	person_t person3;
	strcpy(person3.name, "Alfons");
	strcpy(person3.first_name, "Zachary");
	person3.age = 1;
	insert_sorted(person3);

	// act
	//CU_FAIL("missing test");
	node_t root;
	root = get_testing_head();
	// expected Order:
	// Albert Alfons 20
	// Zachary Alfons 1
	// Zachary Zuboff 30
	
	// assert
	CU_ASSERT_EQUAL(person_compare(&root.content, &person), 0);
	CU_ASSERT_EQUAL(person_compare(&root.next->content, &person3), 0);
	CU_ASSERT_EQUAL(person_compare(&root.next->next->content, &person2), 0);
	clear(&root);
	// root = get_testing_head();
	// CU_ASSERT_PTR_NULL(&root);
	
	// END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown
                  , test_person_compare
                  , test_list_insert
                  , test_list_remove
                  , test_list_clear
                  );
}
