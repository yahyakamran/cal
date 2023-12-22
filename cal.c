#include <stdio.h>
#include <time.h>

int findFirstDay(time_t day, time_t weekday) {
  int days_of_week[] = {1, 2, 3, 4, 5, 6, 7};
  int day_to_reverse = (day - 1) % 7;
  int arrLen = sizeof days_of_week / sizeof days_of_week[0];
  int index = -1;
  for (int i = 0; i < arrLen; i++) {
    if (days_of_week[i] == (int)weekday) {
      index = i;
      break;
    }
  }
  int selected_day_index;
  if (index - day_to_reverse < 0) {
    int temp = index - day_to_reverse;
    selected_day_index = 6 + temp;
  } else {
    selected_day_index = index - day_to_reverse;
  }
  return days_of_week[selected_day_index];
}

void printDays(time_t month_number, time_t day, time_t weekday, time_t year) {
  int days_in_month[] = {
      0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
  };
  if ((0 == (int)year % 4 && 0 != (int)year % 100) || 0 == (int)year % 400) {
    days_in_month[2] = 29; 
  }
  int first_day = findFirstDay(day, weekday);
  int numbers_of_rows =
      ((first_day + days_in_month[(int)month_number]) / 7) + 1;
  // printf("Today is %ld of %ld th Month the weekday is %ld. The total days in
  // " "this month are %d The first day of this month is %d\n", day,
  // month_number, weekday, days_in_month[(int)month_number], first_day);
  int days = 1;
  for (int i = 1; i <= numbers_of_rows; ++i) {
    for (int j = 1; j <= 7; ++j) {
      if (1 == i && 1 == j) {
        for (int empty = 1; empty < first_day; empty++) {
          printf("   ");
          j++;
        }
      }
      if (days > days_in_month[(int)month_number]) {
        printf("   ");
      } else {
        if (days == day) {
          printf("\033[33m");
        }
        if (days < 10) {
          printf("%d  ", days);
        } else {
          printf("%d ", days);
        }
        if (days == day) {
          printf("\033[0m");
        }
      }
      days++;
    }
    printf("\n");
  }
}

void showCurrentDate(time_t month, time_t year) {
  char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  int month_number = (int)month;
  printf("     %s %ld\n", *(months + (month_number - 1)), year);
  printf("M  T  W  T  F  S  S\n");
}

int main() {
  time_t t = time(NULL);
  struct tm *timeinfo;
  timeinfo = localtime(&t);
  time_t day = timeinfo->tm_mday;
  time_t month = timeinfo->tm_mon + 1;
  time_t year = timeinfo->tm_year + 1900;
  time_t weekday = timeinfo->tm_wday;
  showCurrentDate(month, year);
  printDays(month, day, weekday, year);
  return 0;
}
