#include <string.h>
#include <ctype.h>

#define TEXT "Hallo world, it's me!"
#define SHIFT 3

char Encrypt_text (char *buf, int shift);

int main()
{

    int str_length = strlen(TEXT);
    char * buf = malloc((str_length + 1) * sizeof (char));
    strcpy(buf, TEXT);
    
    Encrypt_text (buf, SHIFT);
    
    free(buf);
    
    return 0;
}

char Encrypt_text (char *buf, int shift){
    for (int i = 0; i < strlen(TEXT); i++){
        if(isdigit(*(buf + i)) >= 1 || ispunct(*(buf + i)) >= 1 || *(buf + i) == ' ') {
            continue;
        }
        else if (isalpha(*(buf + i) + SHIFT) == 0) {  //!!!!!!!!!!//!!!!!!!!!!
            *(buf + i) = (*(buf + i) - 26) + SHIFT;
        }else{
            *(buf + i) += SHIFT;
        } 
    }
    return buf;
    
}
