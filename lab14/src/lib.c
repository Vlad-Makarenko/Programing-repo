#include "lib.h"

void tree_function(char *directory_name, int count_of_space)
{
    DIR *folder;
    struct dirent *directory;

    folder = opendir(directory_name);
    if (folder != NULL)
    {
        while ((directory = readdir(folder)))
        {
            if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0)
            {
                printf(" |");
                printf("%*c", count_of_space, ' ');
                printf("+---");
                printf("%s\n", directory->d_name);
                char *full_name_of_subdirectory = malloc((strlen(directory_name) + 1 + strlen(directory->d_name)) * sizeof(char));
                strcpy(full_name_of_subdirectory, directory_name);
                strcat(full_name_of_subdirectory, SLESH);
                strcat(full_name_of_subdirectory, directory->d_name);
                tree_function(full_name_of_subdirectory, count_of_space + 4);
                free(full_name_of_subdirectory);
            }
        }
    }

    closedir(folder);
}

void print_size_of_directory()
{
    char *directory_name =  malloc(256 * sizeof(char));
    printf("%s\n", "Введіть ім'я каталогу:");
    scanf("%s", directory_name);

    double directory_size = calculate_size_of_directory(directory_name);
    directory_size /= 1024.0;

    printf("%s %s: %3.2f%s\n", "Розмір директорії", directory_name, directory_size, " КБ");
    free(directory_name);
}

double calculate_size_of_directory(char *directory_name)
{
    double directory_size = 0.0;

    DIR *folder;
    struct dirent *directory;

    folder = opendir(directory_name);
    if (folder == NULL)
    {
        FILE *file;
        file = fopen(directory_name, "r");

        if (file != NULL)
        {
            directory_size += (double)calculate_file_size(file);
            fclose(file);
        }
    }
    else
    {
        while ((directory = readdir(folder)))
        {

            if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0)
            {
                char *full_name_of_subdirectory = malloc((strlen(directory_name) + 1 + strlen(directory->d_name)) * sizeof(char));

                strcpy(full_name_of_subdirectory, directory_name);
                strcat(full_name_of_subdirectory, SLESH);
                strcat(full_name_of_subdirectory, directory->d_name);

                directory_size += calculate_size_of_directory(full_name_of_subdirectory);
                free(full_name_of_subdirectory);
            }
        }
    }
    closedir(folder);
    return directory_size;
}

long int calculate_file_size(FILE *file)
{
    long int save_pos = ftell(file);
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, save_pos, SEEK_SET);
    return file_size;
}

int do_arithmetic_operation () {

    char *input = malloc(256 * sizeof(char));
    puts("Введіть ім'я файлу, з вхідними данними:");
    scanf("%s", input);

    char *content = malloc(256 * sizeof(char));

    read_from_file(input, content, 255);
    


    char * buffer = malloc(strlen(content) * sizeof(char ));

    int op_left = strtol(content, &buffer, 10);
    char op = *(buffer + 0);
    int op_right = strtol(buffer + 1, NULL, 10);

    float result = do_operation(op_left, op_right, op);
    
    char *output = malloc(256 * sizeof(char));
    puts("Введіть ім'я файлу в який записати результат:");
    scanf("%s", output);
    write_to_file(output, result);
    
    free(input);
    free(output);
    free(content);
    //free(buffer);

    return 0;
}


void read_from_file(char *file_name, char *content, int size){
    FILE * input = fopen(file_name, "r");
    if (input == NULL){
    	puts("Error");
    }
    fgets(content, size, input);
    fclose(input);
}

void write_to_file(char *file_name, float result){
    FILE *output = fopen(file_name, "w");
    if (output == NULL){
    	puts("Error");
    }
    fprintf(output, "%f", result);
    fclose(output);
}

float do_operation(int operand_left, int operand_right, char oper) {
    float result = 0;
    switch (oper) {
        case '+' : result = operand_left + operand_right; break;
        case '-' : result = operand_left - operand_right; break;
        case '*' : result = operand_left * operand_right; break;
        case '/' :
            if (operand_right != 0) {
                result = (float) operand_left / (float) operand_right;
            }
            break;
        default: result = 0;
    }
    return result;
}

