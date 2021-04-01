#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з описом функцій оголошених в lib.h
 *
 * @author Makarenko V.
 * @date 28-march-2021
 * @version 1.0
 */

char *ElementInsertion(char * text, char * pasted_text, int position){
    if(position < 0){
        position = 0;
    }
    if(position > strlen(text)){
        position = strlen(text);
    }
    char* new_text = malloc((strlen(text) + strlen(pasted_text))* sizeof (char));
    memcpy(new_text, text, position);
    memcpy(new_text + position, pasted_text, strlen(pasted_text));
    memcpy(new_text + position + strlen(pasted_text), text + position, strlen(text) - position);
    *(new_text + strlen(pasted_text) + strlen(text)) = '\0';
    return new_text;
}

char * ElementDeleting(char * text, int start_pos, int end_pos){
    if(start_pos < 0 && end_pos > 0){
        start_pos = 0;
    }
    if(start_pos < 0 && end_pos > strlen(text)){
        start_pos = 0;
        end_pos = strlen(text) - 1;
    }
    if(end_pos > strlen(text)){
        end_pos = strlen(text) - 1;
    }
    if(start_pos > end_pos){
        return "Error";
    } else if(start_pos > strlen(text) || end_pos < 0){
        return "Nothing to delete";
    }
    char* new_text = malloc((strlen(text) - (end_pos - start_pos))* sizeof (char));
    memcpy(new_text, text, start_pos);
    memcpy(new_text + start_pos, text + end_pos + 1, strlen(text) - end_pos);
    return  new_text;
}

void ReadFromFile(struct Backpack **backpacks){
    FILE *file = fopen("D:\\Programing-repo\\lab15 && lab17\\backpacks.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < COUNT; i++){
        struct Backpack* temp = *(backpacks + i);
        fscanf(file, "%d %s %s %u", &(temp->laptop_department), (temp ->color), (temp->country), &(temp->enumPurpose));
    }
    fclose(file);
}

void random_number_generation(struct Backpack **backpacks){
    for(int i = 0; i < COUNT; i++){
        struct Backpack* temp = *(backpacks + i);
        temp->volume = rand() % 163 + 18;
    }
}

struct Backpack** InsertStruct (struct Backpack **backpacks, struct Backpack *insert, int position){
    struct Backpack ** result = malloc((COUNT + 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT + 1; i++){
        *(result + i) = malloc(sizeof (struct Backpack));
    }
    if(position < 0){
        position = 0;
    }
    if(position >= COUNT){
        position = COUNT;
        memcpy(*result, *backpacks, sizeof (struct Backpack) * (position + 1));
        memcpy(*(result + position), insert, sizeof (struct Backpack));
        memcpy(*(result + position + 1), *(backpacks + position), sizeof (struct Backpack) * (COUNT - position));
    }else{
        memcpy(*result, *backpacks, sizeof (struct Backpack) * (position));
        memcpy(*(result + position), insert, sizeof (struct Backpack));
        memcpy(*(result + position + 1), *(backpacks + position), sizeof (struct Backpack) * (COUNT - position + 1));
    }
    printf("\nРезульат вставки:\n\n");
    PrintInConsole(result, COUNT + 1);

    return result;
}

struct Backpack** DeleteStruct (struct Backpack **backpacks, int position){
    struct Backpack ** result = malloc((COUNT - 1) * sizeof (struct Backpack));
    for(int i = 0; i < COUNT - 1; i++){
        *(result + i) = malloc(sizeof (struct Backpack));
    }
    if(position < 0){
        position = 0;
    }
    if(position >= COUNT - 1) {
        position = COUNT;
    }
    memcpy(*result, *backpacks, sizeof (struct Backpack) * (position + 1));
    memcpy(*(result + position), *(backpacks + position + 1), sizeof (struct Backpack) * (COUNT - position));

    printf("\nРезульат удаления:\n\n");
    PrintInConsole(result, COUNT - 1);

    return result;
}

void PrintInConsole(struct Backpack **backpacks, int size){
    for(int i = 0; i < size; i++) {
        struct Backpack *temp = *(backpacks + i);
        if (temp->laptop_department == 1) {
            printf("Availability of a laptop department: Yes\n");
        } else {
            printf("Availability of a laptop department: NO\n");
        }
        printf("Color: %s\n", temp->color);
        printf("Volume: %d liter(s)\n", temp->volume);
        printf("Producing country: %s\n", temp->country);
        if (temp->enumPurpose == URBAN) {
            printf("The purpose: city backpack\n");
        } else if (temp->enumPurpose == TACTICAL) {
            printf("The purpose: tactical backpack\n");
        } else if (temp->enumPurpose == TOURIST) {
            printf("The purpose: travel backpack\n");
        }
        printf("\n");
    }
}