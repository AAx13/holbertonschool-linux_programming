#ifndef _ASM_H_
#define _ASM_H_

size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);
char *asm_strchr(const char *s, int c);
char *asm_strstr(const char *s1, const char *s2);
void *asm_memcpy(void *dest, const void *src, size_t n);
size_t asm_putc(int c);
size_t asm_puts(const char *str);
int asm_strcasecmp(const char *s1, const char *s2);

#endif /* _ASM_H_ */
