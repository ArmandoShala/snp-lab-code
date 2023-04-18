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
 * @brief Lab P02 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE

enum month_t { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE

typedef struct date_t {
    int year;
    int month;
    int day;
} date_t;

// END-STUDENTS-TO-ADD-CODE



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE

typedef enum weekday_t { Sun=0, Mon, Tue, Wed, Thu, Fri, Sat } Weekday;

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_leap_year(date_t date)
{
    if(date.year % 4 == 0)
    {
        if(date.year % 100 == 0)
        {
            if(date.year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}
// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int get_month_length(date_t date)
{
    if(date.month < 1 || date.month > 12)
    {
        return 0;
    }

    switch (date.month)
    {
        case FEB:
            return is_leap_year(date) ? 29 : 28;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30; 
        default:
            return 31;
    }
}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_gregorian_date(date_t date)
{
    if(date.day < 15 && date.month <= OKT && date.year <= 1582)
    {
        return 0;
    }
    if(date.year > 9999)
    {
        return 0;
    }
    return 1;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_valid_date(date_t date)
{
    if(date.day < 0 || date.day > 31)
    {
        return 0;
    }
    if(date.month < JAN || date.month > DEZ)
    {
        return 0;
    }
    if(get_month_length(date) < date.day)
    {
        return 0;
    }
    if(date.year < 1582 || date.year > 9999)
    {
        return 0;
    }
    return 1;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int get_weekday(date_t date)
{
    int m = 1 + (date.month + 9) % 12;
    int a = date.month < MAR ? date.year - 1 : date.year;
    int y = a % 100;
    int c = a / 100;

    return ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE

void print_weekday(date_t date)
{
    int weekday;
    weekday = get_weekday(date);

    char* dayName;

    switch (weekday) 
   {
      case Sun: dayName = "Sun"; break;
      case Mon: dayName = "Mon"; break;
      case Tue: dayName = "Tue"; break;
      case Wed: dayName = "Wed"; break;
      case Thu: dayName = "Thu"; break;
      case Fri: dayName = "Fri"; break;
      case Sat: dayName = "Sat"; break;
   }
    printf("%04d-%02d-%02d is a %s\n", date.year, date.month, date.day, dayName);
}

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
    date_t date;

    if(argv[1] == NULL)
    {
        printf("Input arguments are null!");
        return EXIT_FAILURE;
    }

    int res = sscanf(argv[1]
                , "%d-%d-%d"
                , &date.year, &date.month, &date.day
                );
    if (res != 3) {
        printf("Input nicht korrekt.");
        return EXIT_FAILURE;
    }

    //printf("Eingegebenes Datum: %d.%d.%d \n", date.day, date.month, date.year); 

    if(!is_valid_date(date) || !is_gregorian_date(date))
    {
        printf("... is not a valid date. Exiting!"); 
        return EXIT_FAILURE;
    }
    // END-STUDENTS-TO-ADD-CODE


    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE
    
    print_weekday(date);

    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}

