#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str) {
    int i = 0, j = strlen(str) - 1;
    
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    
    return 0;
}
