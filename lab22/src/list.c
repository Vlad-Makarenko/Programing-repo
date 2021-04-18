//
// Created by Vlad on 15.04.2021.
//

/**
 * @file list.c
 * @brief Файл з описом розроблених функцій
 *
 * @author Makarenko V.
 * @date 18-apr-2021
 * @version 1.0
 */

#include "list.h"

struct List *NewList()
{
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

struct ListBackpack *NewListBackpack(int a, char b[10], int c, char d[25], int f)
{
    struct ListBackpack *backpack = malloc(sizeof(struct ListBackpack));
    backpack->laptop_department = a;
    for (int i = 0; i < 10; ++i) {
        backpack->color[i] = b[i];
    }
    backpack->volume = c;
    for (int i = 0; i < 25; ++i) {
        backpack->country[i] = d[i];
    }
    backpack->enumPurpose = f;
    backpack->next = NULL;
    backpack->prev = NULL;
    return backpack;
}

void AddElementEnd(struct List *list, int a, char b[10], int c, char d[25], int f){
    struct ListBackpack *backpack = NewListBackpack(a, b, c, d, f);

    backpack->prev = list->tail;
    if (list->tail) {
        list->tail->next = backpack;
    }else {
        list->head = backpack;
    }
    list->tail = backpack;
}

void AddElementBegin(struct List *list, int a, char b[10], int c, char d[25], int f){
    struct ListBackpack *backpack = NewListBackpack(a, b, c, d, f);
    backpack->next = list->head;
    if(list->head){
        list->head->prev = backpack;
    }else{
        list->tail = backpack;
    }
    list->head = backpack;
}

void InsertElement(struct List *list, int pos, int a, char b[10], int c, char d[25], int f){
    if(pos <= 0){
        AddElementBegin(list, a, b, c, d, f);
        return;
    }
    struct ListBackpack *p = list->head;
    for(int i = pos; i > 0; i--){
        if(!p) {
            AddElementEnd(list, a, b, c, d, f);
            return;
        }
        p = p->next;
    }
    struct ListBackpack * backpack = NewListBackpack(a, b, c, d, f);
    backpack->prev = p->prev;
    backpack->next = p;
    backpack->next->prev = backpack;
    backpack->prev->next = backpack;
}

void DeleteElement(struct List *list, int pos){
    if(pos < 0){
        return;
    }
    struct ListBackpack *p = list->head;
    if(pos == 0){
        if(!list->head){
            return;
        }
        list->head = list->head->next;
        if(p->next){
            p->next->prev = NULL;
        }else{
            list->tail = NULL;
        }
        free(p);
        return;
    }
    for(int i = pos; i > 0; i--){
        if(!p) {
            return;
        }
        p = p->next;
    }
    p->prev->next = p->next;
    if(p->next){
        p->next->prev = p->prev;
    }else{
        list->tail = p->prev;
    }
    free(p);
}

bool RegexChek(char a[1], char b[10], char c[3], char d[25], char f[1]) {
    bool result = true;
    regex_t regex;
    int return_valueA = regcomp(&regex, "^[0-1]$", 0);
    return_valueA = regexec(&regex, a, 0, NULL, 0);
    if (return_valueA != 0) {
        result &= false;
    }
    int return_valueB = regcomp(&regex, "^[A-ZА-Я][a-zа-я]*$", REG_EXTENDED);
    return_valueB = regexec(&regex, b, 0, NULL, 0);
    if (return_valueB != 0) {
        result &= false;
    }
    int return_valueC = regcomp(&regex, "^[0-9]{1,3}$", REG_EXTENDED);
    return_valueC = regexec(&regex, c, 0, NULL, 0);
    if (return_valueC != 0) {
        result &= false;
    }
    int return_valueD = regcomp(&regex, "^[A-ZА-Я][a-zа-яA-ZА-Я]*((( |-|$)?[a-zA-Zа-яА-Я])*|$)?$", REG_EXTENDED);
    return_valueD = regexec(&regex, d, 0, NULL, 0);
    if (return_valueD != 0) {
        result &= false;
    }
    int return_valueF = regcomp(&regex, "^[0-2]$", 0);
    return_valueF = regexec(&regex, f, 0, NULL, 0);
    if (return_valueF != 0) {
        result &= false;
    }

//        print_result(return_valueA);
//        print_result(return_valueB);
//        print_result(return_valueC);
//        print_result(return_valueD);
//        print_result(return_valueF);

    return result;
}

void print_result(int return_value){
    if (return_value == 0) printf("Pattern found.\n");
    else if (return_value == REG_NOMATCH) printf("Pattern not found.\n");
    else printf("An error occurred.\n");
}


void FillList(struct List* list){
    printf("\n |-------------Создание списка-------------|\n |");
    printf("\n |\tВведите элемент, который нужно вставить в список:\n");
    for(int i = 0; i < 3; i++){
        char tempA[2];
        int a;
        char b[10];
        char tempC[4];
        int c;
        char d[25];
        char tempF[2];
        int f;
        printf(" |\tНаличие отдела для ноутбука(1-Да, 0-Нет): ");
        gets(tempA);
        printf(" |\tВведите цвет: ");
        gets(b);
        printf(" |\tВведите объём: ");
        gets(tempC);
        printf(" |\tВведите страну: ");
        gets(d);
        printf(" |\tВведите цель(0-Городской, 1-Тактический, 2-Туристический): ");
        gets(tempF);
        //scanf(file, "%s %s %s %s %s\n", tempA, b, tempC, tempF, d);
        printf(" |---------------------------------------|");
        if(RegexChek(tempA, b, tempC, d, tempF)) {
            a = atoi(tempA);
            c = atoi(tempC);
            f = atoi(tempF);
            AddElementEnd(list, a , b , c ,d ,f);
            printf("\n |\tВсе поля введены корректно");
        } else{
            printf("\n |\tERROR: Одно или несколько полей введено не корректно, элемент в список НЕ добавлен");
        }
        printf("\n |---------------------------------------|\n\n");

    }
}

void PrintFieldWithTwoWords(struct List *list){
    int flag = 0;
    printf("\tPlace for laptop - (1 - Yes, 0 - No)   Purpose(0 - URBAN, 1 - TACTICAL, 2 - TOURIST)\n\n");
    printf("    Place for laptop:              COLOR:              VOLUME:             PURPOSE:                       COUNTRY:\n");
    for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
        regex_t regex;
        int return_value = regcomp(&regex, "^[A-ZА-Я][a-zа-яA-ZА-Я-]* ((( |-|$)?[a-zA-Zа-яА-Я-])*|$)?$", REG_EXTENDED);
        return_value = regexec(&regex, backpack->country, 0, NULL, 0);
        if (return_value == 0) {
            flag = 1;
            printf("%20d %20s %20d %20d %30s\n", backpack->laptop_department, backpack->color, backpack->volume,
                   backpack->enumPurpose, backpack->country);
        }
    }
    if(flag == 0){
        printf("ERROR: Таких элементов нету\n");
    }
}

void ShowList(struct List *list, int side) {
    printf("\tPlace for laptop - (1 - Yes, 0 - No)   Purpose(0 - URBAN, 1 - TACTICAL, 2 - TOURIST)\n\n");
    printf("    Place for laptop:              COLOR:              VOLUME:             PURPOSE:                       COUNTRY:\n");
    if (side == 0) {
        for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
            printf("%20d %20s %20d %20d %30s\n", backpack->laptop_department, backpack->color, backpack->volume,  backpack ->enumPurpose, backpack->country);
//            if (backpack->laptop_department == 1) {
//                printf("\tAvailability of a laptop department: \tYes\n");
//            } else {
//                printf("\tAvailability of a laptop department: \tNO\n");
//            }
//            printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
//            printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
//            printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
//            if (backpack->enumPurpose == URBAN) {
//                printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
//            } else if (backpack->enumPurpose == TACTICAL) {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
//            } else if (backpack->enumPurpose == TOURIST) {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
//            }
//            printf("\n");
        }
    }else {
        for (struct ListBackpack *backpack = list->tail; backpack != NULL; backpack = backpack->prev) {
            printf("%20d %20s %20d %20d %30s\n", backpack->laptop_department, backpack->color, backpack->volume,  backpack ->enumPurpose, backpack->country);
//            if (backpack->laptop_department == 1) {
//                printf("\tAvailability of a laptop department: \tYes\n");
//            } else {
//                printf("\tAvailability of a laptop department: \tNO\n");
//            }
//            printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
//            printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
//            printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
//            if (backpack->enumPurpose == URBAN) {
//                printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
//            } else if (backpack->enumPurpose == TACTICAL) {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
//            } else if (backpack->enumPurpose == TOURIST) {
//                printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
//            }
//            printf("\n");
        }
    }
}

void PrintListInFile(struct List *list, int side){
    FILE *file = fopen("D:\\Programing-repo\\lab18&&lab19\\result.txt", "w");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(file, "\tPlace for laptop - (1 - Yes, 0 - No)   Purpose(0 - URBAN, 1 - TACTICAL, 2 - TOURIST)\n\n");
    fprintf(file, "    Place for laptop:              COLOR:              VOLUME:             PURPOSE:                     COUNTRY:\n");
    if (side == 0) {
        for (struct ListBackpack *backpack = list->tail; backpack != NULL; backpack = backpack->prev) {
            fprintf(file, "%20d %20s %20d %20d %30s", backpack->laptop_department, backpack->color, backpack->volume,  backpack ->enumPurpose, backpack->country);
//            if (backpack->laptop_department == 1) {
//                fprintf(file, "\tAvailability of a laptop department: \tYes\n");
//            } else {
//                fprintf(file, "\tAvailability of a laptop department: \tNO\n");
//            }
//            fprintf(file, "\tColor: \t\t\t\t\t%s\n", backpack->color);
//            fprintf(file, "\tVolume: \t\t\t\t%d liter(s)\n", backpack->volume);
//            fprintf(file, "\tProducing country: \t\t\t%s\n", backpack->country);
//            if (backpack->enumPurpose == URBAN) {
//                fprintf(file, "\tThe purpose: \t\t\t\tcity backpack\n");
//            } else if (backpack->enumPurpose == TACTICAL) {
//                fprintf(file, "\tThe purpose: \t\t\t\ttactical backpack\n");
//            } else if (backpack->enumPurpose == TOURIST) {
//                fprintf(file,"\tThe purpose: \t\t\t\ttravel backpack\n");
//            }
//            fprintf(file, "\n");
        }
    }else {
        for (struct ListBackpack *backpack = list->tail; backpack != NULL; backpack = backpack->prev) {
            fprintf(file, "%20d %20s %20d %20d %30s", backpack->laptop_department, backpack->color, backpack->volume,  backpack ->enumPurpose, backpack->country);

//            for (struct ListBackpack *backpack = list->tail; backpack != NULL; backpack = backpack->prev) {
//            if (backpack->laptop_department == 1) {
//                fprintf(file, "\tAvailability of a laptop department: \tYes\n");
//            } else {
//                fprintf(file, "\tAvailability of a laptop department: \tNO\n");
//            }
//            fprintf(file, "\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
//            fprintf(file, "\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
//            fprintf(file, "\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
//            if (backpack->enumPurpose == URBAN) {
//                fprintf(file, "\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
//            } else if (backpack->enumPurpose == TACTICAL) {
//                fprintf(file, "\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
//            } else if (backpack->enumPurpose == TOURIST) {
//                fprintf(file,"\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
//            }
//            printf("\n");
        }
    }
    fclose(file);
}

void FindBackpack(struct List * list, int index) {
    int flag = 0;
    char color[15];
    char country[25];
    int volume;
    int aim;
    switch (index) {
        case 1:
            printf("\nРезультат поиска:\n\n");
            for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
                if (backpack->laptop_department == 1) {
                    flag = 1;
                    if (backpack->laptop_department == 1) {
                        printf("\tAvailability of a laptop department: \tYes\n");
                    } else {
                        printf("\tAvailability of a laptop department: \tNO\n");
                    }
                    printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
                    printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
                    printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
                    if (backpack->enumPurpose == URBAN) {
                        printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
                    } else if (backpack->enumPurpose == TACTICAL) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
                    } else if (backpack->enumPurpose == TOURIST) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
                    }
                    printf("\n");
                }
            }
            break;
        case 2:
            printf(" |\tВведите цвет, который нужно найти: ");
            scanf("%s", color);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
                if (strcmp(backpack->color, color) == 0) {
                    flag = 1;
                    printf("\tAvailability of a laptop department: \tYes\n");
                    printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
                    printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
                    printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
                    if (backpack->enumPurpose == URBAN) {
                        printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
                    } else if (backpack->enumPurpose == TACTICAL) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
                    } else if (backpack->enumPurpose == TOURIST) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
                    }
                    printf("\n");
                }
            }
            break;

        case 3:
            printf(" |\tВведите объём, рюкзака который нужно найти: ");
            scanf("%d", &volume);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
                if (backpack->volume == volume) {
                    flag = 1;
                    if (backpack->laptop_department == 1) {
                        printf("\tAvailability of a laptop department: \tYes\n");
                    } else {
                        printf("\tAvailability of a laptop department: \tNO\n");
                    }
                    printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
                    printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
                    printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
                    if (backpack->enumPurpose == URBAN) {
                        printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
                    } else if (backpack->enumPurpose == TACTICAL) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
                    } else if (backpack->enumPurpose == TOURIST) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
                    }
                    printf("\n");
                }
            }
            break;
        case 4:
            printf(" |\tВведите цель, рюкзака который нужно найти: ");
            scanf("%d", &aim);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListBackpack *backpack = list->head; backpack != NULL; backpack = backpack->next) {
                if (backpack->enumPurpose == aim) {
                    flag = 1;
                    if (backpack->laptop_department == 1) {
                        printf("\tAvailability of a laptop department: \tYes\n");
                    } else {
                        printf("\tAvailability of a laptop department: \tNO\n");
                    }
                    printf("\tColor: \t\t\t\t\t\t\t\t\t%s\n", backpack->color);
                    printf("\tVolume: \t\t\t\t\t\t\t\t%d liter(s)\n", backpack->volume);
                    printf("\tProducing country: \t\t\t\t\t\t%s\n", backpack->country);
                    if (backpack->enumPurpose == URBAN) {
                        printf("\tThe purpose: \t\t\t\t\t\t\tcity backpack\n");
                    } else if (backpack->enumPurpose == TACTICAL) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttactical backpack\n");
                    } else if (backpack->enumPurpose == TOURIST) {
                        printf("\tThe purpose: \t\t\t\t\t\t\ttravel backpack\n");
                    }
                    printf("\n");
                }
            }
            break;
        default:
            printf("\tERROR:Некорректный вариант\n\n");
            flag = 1;
            break;
    }

    if(flag == 0){
        printf("\tERROR: Такого рюкзака нету.\n\n");
    }
}


int compareLd(struct ListBackpack* a, struct ListBackpack* b) {
    if (a->laptop_department == b->laptop_department)
        return 0;
    else if (a->laptop_department > b->laptop_department)
        return 1;
    else
        return -1;
}

int compareColor(struct ListBackpack* a, struct ListBackpack* b){
    if(strcmp(a->color, b->color) == 0)
        return 0;
    else if (strcmp(a->color, b->color) > 0)
        return 1;
    else
        return -1;
}


int compareVolume(struct ListBackpack* a, struct ListBackpack* b){
    if (a->volume == b->volume)
        return 0;
    else if (a->volume > b->volume)
        return 1;
    else
        return -1;
}

int compareCountry(struct ListBackpack* a, struct ListBackpack* b){
    if(strcmp(a->country, b->country) == 0)
        return 0;
    else if (strcmp(a->country, b->country) > 0)
        return 1;
    else
        return -1;
}

int comparePurpose(struct ListBackpack* a, struct ListBackpack* b){
    if (a->enumPurpose == b->enumPurpose)
        return 0;
    else if (a->enumPurpose > b->enumPurpose)
        return 1;
    else
        return -1;
}

void SortListByCriterion(struct List *list, int(*compare)(struct ListBackpack*, struct ListBackpack*)){
    struct ListBackpack *set = list->tail;
    while (set != list->head){
        struct ListBackpack *p = list->head->next;
        struct ListBackpack *max = list->head;
        while (p != set->next) {
            if (compare(p, max) >= 0)
                max = p;
            p = p->next;
        }
        if (set == max) {
            set = max->prev;
            continue;
        }
        else if (max == list->head && set == list->tail) {
            list->head = set;
            list->tail = max;
            list->head->next = list->tail->next;
            list->tail->prev = list->head->prev;
            list->head->next->prev = list->head;
            list->tail->prev->next = list->tail;
            list->head->prev = NULL;
            list->tail->next = NULL;
        }
        else if (max == list->head) {
            list->head = set;
            max->prev = list->head->prev;
            list->head->prev = NULL;
            max->prev->next = max;
            struct ListBackpack *t = max->next;
            max->next = list->head->next;
            list->head->next = t;
            max->next->prev = max;
            list->head->next->prev = list->head;
        }
        else if (set == list->tail) {
            list->tail = max;
            set->next = list->tail->next;
            list->tail->next = NULL;
            set->next->prev = set;
            struct ListBackpack *t = set->prev;
            set->prev = list->tail->prev;
            list->tail->prev = t;
            set->prev->next = set;
            list->tail->prev->next = list->tail;
        }
        else {
            struct ListBackpack *t = max->next;
            max->next = set->next;
            set->next = t;
            max->next->prev = max;
            set->next->prev = set;
            t = max->prev;
            max->prev = set->prev;
            set->prev = t;
            max->prev->next = max;
            set->prev->next = set;
        }
        set = max->prev;
    }
}

void FreeList(struct List *list){
    while (list->head) {
        struct ListBackpack *p = list->head;
        list->head = p->next;
        free(p);
    }
    free(list);
}

