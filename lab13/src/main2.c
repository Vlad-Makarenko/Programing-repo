#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEXT "Today is cold"

int main(){

    int str_length = strlen(TEXT);
    char * text_copy = malloc((str_length + 1) * sizeof (char));
    strcpy(text_copy, TEXT);
    
    char space[] = " ";
    char *max_word ;
    char *min_word ;

    int max_length = 0;
    int min_length = 250;

    for (char *word = strtok(text_copy, space); word != NULL; word = strtok(NULL, space)) {
        int length = strlen(word);

        if (length > max_length) {
            max_length = length;
            max_word = word;
        }

        if (length < min_length) {
            min_length = length;
            min_word = word;
        }
    }

    free(text_copy);
    return 0;
}
