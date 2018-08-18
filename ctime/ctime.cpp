// CLOCKS_PER_SEC - number of processor clock ticks per second

// clock_t - arithmetic type capable of representing the process running time
//           of implementation-defined range and precision

// time_t - arithmetic type capable of representing times
//          Although not defined, this is almost always an integral value holding the number
//          of seconds since 00:00, Jan 1 1970 UTC, corresponding to POSIX time

// tm     - structure holding a calendar date and time broken down into its components
//  tm_sec - seconds after the minute [0, 60]
//  tm_min - minutes after the hour - [0, 59]
//  tm_hour - hours since midnight - [0, 23]
//  tm_mday - day of the month - [1, 31]
//  tm_mon  - months since January - [0, 11]
//  tm_year - years since 1900
//  tm_wday - days since Sunday - [0, 6]
//  tm_yday - days since January 1 - [0, 365]
//  tm_isdst - Daylight Saving Time flag. The value is positive if DST is in effect, zero
//              if not and negative if no information is available

// The range 0...61 was a defect introduced in C89 and corrected in C99


// timespec - time in seconds and nanoseconds


// clock - returns raw processor clock time since the program is started
// time  - returns the current time of the system as time since epoch
// difftime - computes the difference between times
// timespec_get - returns the calendar time based on a given time base


// ctime
// asctime
// strftime
// wcsftime
// gmtime
// localtime
// mktime

#include <ctime>