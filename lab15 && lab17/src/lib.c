//
// Created by Vlad on 22.03.2021.
//

#include "lib.h"

void ReadFromFile(struct Backpack **backpacks){
    FILE *file = fopen("backpacks.txt", "r");
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
int comparator(char a[15], char b[15]){
    if(strcmp(a,b) == 0){
        return 0;
    } else if (strcmp(a,b) < 0){
        return -1;
    } else if (strcmp(a,b) > 0){
        return 1;
    }
    return 0;
}

void SortByCriterion(struct Backpack **backpacks, char criterion[18], int size){
    int flag;
    char laptop_department[18] = "laptop_department"; // 1 - yes; 0 - no.
    char color[18] = "color";
    char volume[18] = "volume";
    char country[18] = "country";
    char enumPurpose[18] = "purpose";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            flag = 0;
            if(strcmp(color,criterion) == 0) {
                flag = comparator((*(backpacks + j))->color, (*(backpacks + j + 1))->color);
            }else if(strcmp(country, criterion) == 0){
                flag = comparator((*(backpacks + j))->country, (*(backpacks + j + 1))->country);
            }else if(strcmp(laptop_department, criterion) == 0){
                if ((*(backpacks + j))->laptop_department > (*(backpacks + j + 1))->laptop_department){
                    flag = 1;
                }
            }else if(strcmp(volume, criterion) == 0) {
                if ((*(backpacks + j))->volume > (*(backpacks + j + 1))->volume) {
                    flag = 1;
                }
            }else if(strcmp(enumPurpose, criterion) == 0) {
                if ((*(backpacks + j))->enumPurpose > (*(backpacks + j + 1))->enumPurpose) {
                    flag = 1;
                }
            }
            if (flag == 1){
                struct Backpack *temp = *(backpacks + j);
                *(backpacks + j) = *(backpacks + j + 1);
                *(backpacks + j + 1) = temp;
            }
        }

    }
}

void PrintInConsole(struct Backpack **backpacks){
    for(int i = 0; i < COUNT; i++){
        struct Backpack* temp = *(backpacks + i);
        if(temp->laptop_department == 1){
            printf("Availability of a laptop department: Yes\n");
        }else{
            printf("Availability of a laptop department: NO\n");
        }
        printf("Color: %s\n", temp->color);
        printf("Volume: %d liter(s)\n", temp->volume);
        printf("Producing country: %s\n", temp->country);
        if(temp->enumPurpose == URBAN){
            printf("The purpose: city backpack\n");
        } else if(temp->enumPurpose == TACTICAL){
            printf("The purpose: tactical backpack\n");
        } else if(temp->enumPurpose == TOURIST) {
            printf("The purpose: travel backpack\n");
        }
        printf("\n");
    }
}

void PrintInFile(struct Backpack **backpacks){
    FILE *file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < COUNT; i++){
        struct Backpack* temp = *(backpacks + i);
        if(temp->laptop_department == 1){
            fprintf(file, "Availability of a laptop department: Yes\n");
        }else{
            fprintf(file, "Availability of a laptop department: NO\n");
        }
        fprintf(file, "Color: %s\n", temp->color);
        fprintf(file, "Volume: %d liter(s)\n", temp->volume);
        fprintf(file, "Producing country: %s\n", temp->country);
        if(temp->enumPurpose == URBAN){
            fprintf(file, "The purpose: city backpack\n");
        } else if(temp->enumPurpose == TACTICAL){
            fprintf(file, "The purpose: tactical backpack\n");
        } else if(temp->enumPurpose == TOURIST) {
            fprintf(file, "The purpose: travel backpack\n");
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

struct Backpack* FindGermanBackpack(struct Backpack **backpacks, int size){
    int right = 0;
    char country[15] = "Germany";
    int flag = 0;
    printf("German city backpack(s):\n");
    for(int i = 0; i < size; i++){
        struct Backpack *temp = *(backpacks + i);
        if (strcmp(temp->country, country) == 0 && temp->enumPurpose == URBAN) {
            flag = 1;
            if (temp->laptop_department == 1) {
                printf("Availability of a laptop department: Yes\n");
            } else {
                printf("Availability of a laptop department: NO\n");
            }
            printf("Color: %s\n", temp->color);
            printf("Volume: %d liter(s)\n", temp->volume);
            printf("Producing country: %s\n", temp->country);
            printf("The purpose: city backpack\n");
            printf("\n");
            right = i;
        }
    }
    if(flag == 0){
        printf("German city backpacks not found\n");
    }
    return *(backpacks + right);
}


void WriteToBinaryFile(struct Backpack **backpacks) {
    FILE *file = fopen("result.bin", "wb");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < COUNT; i++) {
        struct Backpack *temp = *(backpacks + i);
        char buf[50];
        sprintf(buf, "%d", temp->laptop_department);
        fwrite(buf, sizeof(struct Backpack), sizeof(temp->laptop_department), file);
        fwrite(temp->color, sizeof(struct Backpack), sizeof(temp->color), file);
        sprintf(buf, "%d", temp->volume);
        fwrite(buf, sizeof(struct Backpack), sizeof(temp->volume), file);
        fwrite(temp->country, sizeof(struct Backpack), sizeof(temp->country), file);
        sprintf(buf, "%d", temp->enumPurpose);
        fwrite(buf, sizeof(struct Backpack), sizeof(temp->enumPurpose), file);
    }
    fclose(file);
}


void ReadFromBinaryFile(struct Backpack **backpacks){
    FILE *file = fopen("result.bin", "rb");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    //long count = ftell(file);

    for (int j = 0; j < COUNT; j++) {
        struct Backpack *temp = *(backpacks + j);
        char buf[50];
        sprintf(buf, "%d", temp->laptop_department);
        fread(buf, sizeof(struct Backpack), sizeof(temp->laptop_department), file);
        fread(temp->color, sizeof(struct Backpack), sizeof(temp->color), file);
        sprintf(buf, "%d", temp->volume);
        fread(buf, sizeof(struct Backpack), sizeof(temp->volume), file);
        fread(temp->country, sizeof(struct Backpack), sizeof(temp->country), file);
        sprintf(buf, "%d", temp->enumPurpose);
        fread(buf, sizeof(struct Backpack), sizeof(temp->enumPurpose), file);

        /*if(temp->laptop_department == 1){
            printf("Availability of a laptop department: Yes\n");
        }else{
            printf("Availability of a laptop department: NO\n");
        }
        printf("Color: %s\n", temp->color);
        printf("Volume: %d liter(s)\n", temp->volume);
        printf("Producing country: %s\n", temp->country);
        if(temp->enumPurpose == URBAN){
            printf("The purpose: city backpack\n");
        } else if(temp->enumPurpose == TACTICAL){
            printf("The purpose: tactical backpack\n");
        } else if(temp->enumPurpose == TOURIST) {
            printf("The purpose: travel backpack\n");
        }
        printf("\n");*/

    }
    fclose(file);
}

