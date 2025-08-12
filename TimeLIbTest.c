#include <stdio.h>
#include <time.h>

int main()
{
    time_t t;
    struct tm *data;

    t = time(NULL);
    data = localtime(&t);

    printf("Dia do mês: ..: %d\n", data->tm_mday);
    printf("Mês ..........: %d\n", data->tm_mon + 1);
    printf("Ano ...........: %d\n\n", data->tm_year + 1900);

    printf("Data .......: %d/%d/%d \n\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    printf("Data .......: %d\n", data->tm_hour);
    printf("Data .......: %d\n", data->tm_min);
    printf("Data .......: %d\n", data->tm_sec);
}