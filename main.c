// main() file

#include <stdio.h>
#include <string.h>
#include "my_str_y_strings.h"

int main() {
    char s1[50]; // Empty char array
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