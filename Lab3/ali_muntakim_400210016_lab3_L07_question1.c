#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(const char *const str1, const char *const str2);

int main() {
    char *str = my_strcat("MAGURO", "MAN");
    printf("%s\n", str);
    free(str);
    return 0;
}

char *my_strcat(const char *const str1, const char *const str2) {

    char *str3 = malloc(strlen(str1) + strlen(str2) + 1);

    int i = 0, j = 0;
    while(str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    while(str2[j] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }

    str3[i] = '\0';

    return str3;
}
