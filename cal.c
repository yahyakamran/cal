#include <stdio.h>
#include <time.h>

void show_calender(time_t day , time_t month , time_t year){
  printf("%ld %ld %ld\n", day, month, year);
}

int main() {
  time_t t = time(NULL);
  struct tm *timeinfo;
  time_t day;
  time_t month;
  time_t year;
  timeinfo = localtime(&t);
  day = timeinfo->tm_mday;
  month = timeinfo->tm_mon + 1;
  year = timeinfo->tm_year + 1900;
  show_calender(day,month, year);
  return 0;
}
