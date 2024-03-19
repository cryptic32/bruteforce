#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bruteHelper(char* password, char* current, const char* charset, int charset_length, int pos, int max_len);

void bruteforce(char* password) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int charset_length = strlen(charset);

    char current[50] = { 0 };

    for (int len = 1; len <= strlen(password); len++) {
        bruteHelper(password, current, charset, charset_length, 0, len);
    }

    printf("Password not found.\n");
}

void bruteHelper(char* password, char* current, const char* charset, int charset_length, int pos, int max_len) {
    if (pos == max_len) {
        if (strcmp(current, password) == 0) {
            printf("Password found: %s\n", current);
            exit(0);
        }
        return;
    }

    for (int i = 0; i < charset_length; i++) {
        current[pos] = charset[i];
        bruteHelper(password, current, charset, charset_length, pos + 1, max_len);
    }
}

int main() {
    char password[50];

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Удаление символа новой строки

    bruteforce(password);

    return 0;
}
