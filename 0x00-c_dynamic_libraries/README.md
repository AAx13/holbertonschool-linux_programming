# Dynamic Libraries Project

## Libraries
`libholberton.so` Is a Shared or Dynamic Library created from all the functions
in the `src` directory.
`header.h` Contains all the prototypes for the functions within the `src` directory.
```
/* _putchar - writes a character to stdout. */
int _putchar(char c);

/* _islower - checks for a lower-case character. */
int _islower(int c);

/* _isalpha - checks for an alphabetic character. */
int _isalpha(int c);

/* _abs - compute absolute value of an integer. */
int _abs(int n);

/* _isupper - checks for an uppercase letter. */
int _isupper(int c);

/* _isdigit - checks for a digit (0 through 9). */
int _isdigit(int c);

/* _strlen - calculate the length of a string. */
int _strlen(char *s);

/* _puts - writes the string and trailing newline to stdout. */
void _puts(char *s);

/* _strcpy - copy a string. */
char *_strcpy(char *dest, char *src);

/* _atoi - convert a string to integer. */
int _atoi(char *s);

/* _strcat - concatenate two strings. */
char *_strcat(char *dest, char *src);

/* _strncat - concatenate two strings up to n amount of chars. */
char *_strncat(char *dest, char *src, int n);

/* _strncpy - copy a string up to n amount of characters. */
char *_strncpy(char *dest, char *src, int n);

/* _strcmp - compare two strings. */
int _strcmp(char *s1, char *s2);

/* _strncmp - compare two strings up to n amount of characters. */
int _strncmp(char *s1, char *s2);

/* _memset - copy memory area. */
char *_memset(char *s, char b, unsigned int n);

/* _memcpy - copy memory area. */
char *_memcpy(char *dest, char *src, unsigned int n);

/* _strchr - locate character in string. */
char *_strchr(char *s, char c);

/* _strspn - search a string for a set of bytes. */
unsigned int _strspn(char *s, char *accept);

/* _strpbrk - search a string for any of a set of bytes. */
char *_strpbrk(char *s, char *accept);

/* _strstr - locate a substring. */
char *_strstr(char *haystack, char *needle);
```