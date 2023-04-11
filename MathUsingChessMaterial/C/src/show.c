#include <stdio.h>
#include <time.h>

void show_digit_grid(char **digit_grid, int width, int height)
{
    for(int y=height-1; y>=0; y-=1)
    {
        for(int x=0; x<width; x+=1)
        {
            printf("%d", *(*(digit_grid+y)+x));
        }
        printf("\n");
    }
}

void show_grid(char **grid, int width, int height)
{
    for(int y=height-1; y>=0; y-=1)
    {
        for(int x=0; x<width; x+=1)
        {
            printf("%c", *(*(grid+y)+x));
        }
        printf("\n");
    }
}

struct tm long_to_time_delta(long time_in_second)
{
    /*
    The <time.h> header declares the structure tm, which includes at least the following members:

    int    tm_sec   seconds [0,61]
    int    tm_min   minutes [0,59]
    int    tm_hour  hour [0,23]
    int    tm_mday  day of month [1,31]
    int    tm_mon   month of year [0,11]
    int    tm_year  years since 1900
    int    tm_wday  day of week [0,6] (Sunday = 0)
    int    tm_yday  day of year [0,365]
    int    tm_isdst daylight savings flag
    */
    struct tm datetime_struct;
    // second 
    datetime_struct.tm_sec = time_in_second % 60;
    time_in_second /= 60;
    // minute 
    datetime_struct.tm_min = time_in_second % 60;
    time_in_second /= 60;
    // hour 
    datetime_struct.tm_hour = time_in_second % 24;
    time_in_second /= 24;
    // day in year of 365 days 
    datetime_struct.tm_yday = time_in_second % 365;
    datetime_struct.tm_year = time_in_second / 365; // Actually, not every year consists of 365 days; for instance, leap years. 
    // set each attribute else to a value of non-sense 
    datetime_struct.tm_mday  = 1 << 31;
    datetime_struct.tm_wday  = 1 << 31;
    datetime_struct.tm_mon   = 1 << 31;
    datetime_struct.tm_isdst = 0;
    return datetime_struct;
}