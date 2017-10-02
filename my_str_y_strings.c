#include <stdio.h>
#include <string.h>

// Returns the length of the string as an integer
int mystrlen(char * strngy) {
    char *i;
    for (i=strngy; *i; i++);
    return i - strngy;
}

// Copies the first 'n' characters from source onto dest and returns dest
char * mystrncpy(char * dest, char * source, int n) {
    int i;

    /*
        While a terminating 0 doesn't exist at that location, copy from source into dest.
        If a termnating 0 is reached before 'n' entries are copied, continue on by placing 
        terminating 0s.
    */
    for (i=0; i < n && source[i] != '\0'; i++)
        dest[i] = source[i];
    while (i < n)
        dest[i] = '\0';

    /*
        Return the result
    */
    return dest;
}

// Appends the first 'n' characters from source onto the end of dest
// and returns dest.
char * mystrncat(char * dest, char * source, int n) {
    int i;
    int len = mystrlen(dest);

    /*
        While a terminating 0 doesn't exist at that location, append the next character
        from the source string after the destination string. Continue until a terminating
        zero is reached or 'n' characters have been appended.
    */
    for (i=0; i < n && source[i] != '\0'; i++)
        dest[i + len] = source[i];
    while (i < n)
        dest[i + len] = '\0';

    // Return the result
    return dest;
}

// Compares each character of s1 with s2 and returns
// 1 if s1 > s2, -1 if s1 < s2, and 0 if s1 == s2
int mystrcmp(char * s1, char * s2) {
    int i;
    int len = mystrlen(s1);

    /*
        Goes through the length of the first string, comparing values at each memory location.
        If the locations contain different values, compare the two.
        If they're both terminating 0s, you've already gone through the length of both strings
        and they're therefore the same so a 0 is returned.
    */
    for (i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            if (s1[i] > s2[i])
                return 1;
            else
                return -1;
        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
    }
    
    // Return 0 just in case a case is missed.
    return 0;
}

// Returns a pointer located at the first occurance of c in s1.
char * mystrchr(char * s1, char c) {
    char * p;
    int i;
    int len = mystrlen(s1);

    for (i = 0; i < len; i++) {
        if (s1[i] == c)
            break;
        else {
            *p = s1[i + 1];
        }
    }

    return p;
}

int main() {
    char s1[5];
    char s2[] = "hello";
    char s3[] = "goodbye";

    printf("s1: [%s]\n", s1);
    printf("s2: [%s]\n", s2);
    printf("s3: [%s]\n", s3);

    printf("\nTesting strlen(%s):\n", s2);
    printf("[standard]: %ld\n", strlen(s2));
    printf("[mine]: %d\n", mystrlen(s2));

    printf("\nTesting strncpy(%s, %s, 3):\n", s1, s3);
    printf("[standard]: [%s]\n", strncpy(s1, s3, 3));
    printf("[mine]: [%s]\n", mystrncpy(s1, s3, 3));

    printf("\nTesting strncat(%s, %s, 3):\n", s1, s2);
    printf("[standard]: [%s]\n", strncat(s1, s2, 3));
    printf("[mine]: [%s]\n", mystrncat(s1, s2, 3));

    printf("\nTesting strcmp(%s, %s):\n", s2, s3);
    printf("[standard]: %d\n", strcmp(s1, s2));
    printf("[mine]: %d\n", mystrcmp(s1, s2));

    printf("\nTesting strchr(%s, %c):\n", s2, 'o');
    printf("[standard]: %p\n", strchr(s2, 'o'));
    printf("[mine]: %p\n", strchr(s2, 'o'));

}