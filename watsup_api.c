#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WEATHER_FILE "weather_data2.dat"

int main() {

    int result;
    int file_size;
    char temperature[11];
    char *city_name;
    char command[100];
    //scanf("%ms", &city_name);
    //printf("%s", city_name);
    sprintf(command, "curl -i -X POST \"https://graph.facebook.com/v20.0/388365704358053/messages\"");// -H 'Authorization: Bearer EAAG6yEtcnQABO9ghkiBzn4c2ycPPqDUZCsyXGTjBHRhGqVGmfTHoV2RomISwDZC2ohZAK1G9cQ9wWOAFfNhIAZB3Kel45dgcxxOi3VxCHLrf8XveQIZAT9xnUZA9F1dgvli0Hp6kf4Li0TmTQ7y5Pu5mZAgs3X5BmWMTxnXZAGoT106aZAD1sM0vtQvH4VLSuq4girF85cXfAIm0OSKEd4wqyZAf01vucZD' `-H 'Content-Type: application/json' -d '{ \"messaging_product\": \"whatsapp\", \"to\": \"917075937346\", \"type\": \"template\", \"template\": { \"name\": \"hello_world\", \"language\": { \"code\": \"en_US\" } } }'\" ");
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
    /*FILE* fp = fopen(WEATHER_FILE, "r");
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
    printf("%s\n", temperature);*/

    return 0;
}
