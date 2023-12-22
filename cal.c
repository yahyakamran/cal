#include <stdio.h>
#include <time.h>
#include <uchar.h>

void printDays(int month_number, time_t day) {
  printf("Today is %ld of %d th Month\n", day, month_number);
}

void show_calender(time_t day, time_t month, time_t year) {
  char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  int month_number = (int)month;
  printf("\t%ld %s %ld\n", day, *(months + (month_number - 1)), year);
  printf("Mon Tue Wed Thr Fri Sat Sun\n");
  printDays(month_number, day);
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
  show_calender(day, month, year);
  return 0;
}
