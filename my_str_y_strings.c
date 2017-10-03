#include <stdio.h>
#include <string.h>

// Returns the length of the string as an integer
int mystrlen(char *strngy) {
    char *i;
    for (i=strngy; *i; i++);
    return i - strngy;
}

// Copies the first 'n' characters from source onto dest and returns dest
char * mystrncpy(char *dest, char *source, int n) {
    int i;

    /*
        While a terminating 0 doesn't exist at that location, copy from source into dest.
        If a terminating 0 is reached before 'n' entries are copied, continue on by placing 
        terminating 0s.
    */
    for (i=0; i < n && source[i] != '\0'; i++)
        dest[i] = source[i];
    while (i < n)
        dest[i] = '\0';

    // Return the result
    return dest;
}

// Copies the entire source string over to dest using mystrncpy()
char * mystrcpy(char *dest, char *source) {
    return mystrncpy(dest, source, mystrlen(source));
}

// Appends the first 'n' characters from source onto the end of dest
// and returns dest.
char * mystrncat(char *dest, char *source, int n) {
    int i;
    int len = mystrlen(dest);

    /*
        While a terminating 0 doesn't exist at that location, append the next character
        from the source string after the destination string. Continue until either a 
        terminating zero is reached or 'n' characters have been appended.
    */
    for (i=0; i < n && source[i] != '\0'; i++)
        dest[i + len] = source[i];
    while (i < n)
        dest[i + len] = '\0';

    // Return the result
    return dest;
}

// Appends the entire source string after dest using mystrncat()
char * mystrcat(char *dest, char *source) {
    return mystrncat(dest, source, mystrlen(source));
}

// Compares each character of s1 with s2 and returns
// 1 if s1 > s2, -1 if s1 < s2, and 0 if s1 == s2
int mystrcmp(char *s1, char *s2) {
    /*
        While s1 is not zero,
        If s2 is not zero or s1 is greater than s2, return 1
        If s2 is greater than s1, return -1
        Otherwise increment both s1 and s2 and compare the next two pointers
    */
    while (*s1) {
        if (!*s2 || *s1 > *s2)
            return 1;
        if (*s2 > *s1)
            return -1;
        s1++;
        s2++;
    }
    
    // If there is anything left in s2, it is greater than s1 so return -1.
    if (*s2)
        return -1;

    // Return 0 in all other cases.
    return 0;
}

// Returns a pointer located at the first occurance of c in s1.
char * mystrchr(char *s1, char c) {
    char *p;
    int i;
    int len = mystrlen(s1);

    /*
        Iterates through s1 over its length and returns the location of the pointer if c occurs in s1.
        Otherwise, returns null.
    */
    for (i = 0; i < len; i++) {
        if (s1[i] == c) {
            *p = s1[i];
            return p;
        }
    }
    
    return NULL;
}

// Returns a pointer located at the first occurance of substring s2 in s1.
char * mystrstr(char *s1, char *s2) {
    // While s1 is not 0
    while (*s1) {

        char *start_loc = s1;
        char *looking_for = s2;
        /* 
            While start_loc/looking_for are both not 0 and start_loc == looking_for
            Increment both pointers
        */
        while (*start_loc && *looking_for && *start_loc == *looking_for) {
            start_loc++;
            looking_for++;
        }

        /*
            If looking_for is not zero at the end of the while loop, the substring
            is a match so return the start location, start_loc.
        */
        if (!*looking_for)
            return s1;

        // Otherwise, increment the s1 pointer and check again while s1 is not zero.
        s1 = start_loc + 1;
    }
    return NULL;
}

int main() {
    char s1[5]; // Empty char array
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

    printf("\nTesting strchr(%s, 'z'):\n", s1);
    printf("[standard]: %p\n", strchr(s1, 'z'));
    printf("[mine]: %p\n", mystrchr(s1, 'z'));

    char ab[] = "ab"; // String "ab" used to test mystrcmp()
    char abc[] = "abc"; // String "abc" used to test mystrcmp()

    printf("\nTesting strcmp:\n");
    printf("Comparing 'ab' to 'abc':\n");
    printf("[standard]: %d\n", strcmp(ab, abc));
    printf("[mine]: %d\n", mystrcmp(ab, abc));
    printf("Comparing 'abc' to 'ab':\n");
    printf("[standard]: %d\n", strcmp(abc, ab));
    printf("[mine]: %d\n", mystrcmp(abc, ab));
    printf("Comparing 'abc' to 'abc':\n");
    printf("[standard]: %d\n", strcmp(abc, abc));
    printf("[mine]: %d\n", mystrcmp(abc, abc));

    // Testing for mystrstr

    char testss[] = "Hello my name is Ninooo";

    char *strstrtest = strstr(testss, "Nino");
    char *mystrstrtest = mystrstr(testss, "Nino");

    printf("\nTesting strstr:\n");
    printf("[standard]: %p\n", strstrtest);
    printf("[mine]: %p\n", mystrstrtest);
    printf("Memory addresses identical: %s\n", strstrtest == mystrstrtest ? "True" : "False");
}