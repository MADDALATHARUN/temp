#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WEATHER_FILE "word_data.dat"

int main() {

    int result;
    int file_size;
    char temperature[11];
    char *city_name;
    char command[100];
    scanf("%ms", &city_name);
    printf("%s", city_name);
    sprintf(command, "curl -s \"https://api.dictionaryapi.dev/api/v2/entries/en/%s\" > %s", word[1], FILENAME);
    //= "curl -o weather_data2.dat \"http://api.openweathermap.org/data/2.5/weather?q=%s&appid=b5196b302ac0ecc1a11b3f021ab64280&units=metric\", city_name";
    result = system(command);
    if (result == 0)
    {
        printf("Weather data saved to weather_data2.dat\n");
    }
    else
    {
        printf("Error fetching weather data\n");
        exit;
    }
    FILE* fp = fopen(WEATHER_FILE, "r");
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    char temp [file_size];
    fseek(fp, 0L, SEEK_SET);
    fread(temp, file_size, 1, fp);
    //char* token = strtok(temp, "temp");
    //while( token != NULL)
    //{
      //  printf("\n%s\n",token);
        //token = strtok(NULL,":");
    //}
    int pos = strstr(temp,"\"temp") - &temp[0];
    strncpy(temperature, temp+pos, 12);
    printf("%s\n", temperature);

    return 0;
}
