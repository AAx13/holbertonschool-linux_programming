# x86 Assembly - libASM Project

### Tools
* Ubuntu 14.04LTS
* nasm 2.10.09 flags -f elf64
* gcc 4.8.4

### Syntax/Architecture
* x86 Intel Assembly
* 64bit Architecture


[0-strlen.asm](../0x09-libasm/0-strlen.asm)
```nasm
;; Copycat of the function strlen(3), in x86-64 Assembly
size_t asm_strlen(const char *str);
```

[1-strcmp.asm](../0x09-libasm/1-strcmp.asm)
```nasm
;; Copycat of the function strcmp(3), in x86-64 Assembly
int asm_strcmp(const char *s1, const char *s2);
```

[2-strncmp.asm](../0x09-libasm/2-strncmp.asm)
```nasm
;; Copycat of the function strncmp(3), in x86-64 Assembly
int asm_strncmp(const char *s1, const char *s2, size_t n);
```

[3-strchr.asm](../0x09-libasm/3-strchr.asm)
```nasm
;; Copycat of the function strchr(3), in x86-64 Assembly
char *asm_strchr(const char *s, int c);
```

[4-strstr.asm](../0x09-libasm/4-strstr.asm)
```nasm
;; Copycat of the function strstr(3), in x86-64 Assembly
char *asm_strstr(const char *s1, const char *s2);
```

[5-memcpy.asm](../0x09-libasm/5-memcpy.asm)
```nasm
;; Copycat of the function memcpy(3), in x86-64 Assembly
void *asm_memcpy(void *dest, const void *src, size_t n);
```

[100-putc.asm](../0x09-libasm/100-putc.asm)
```nasm
;; Prints a single character on the standard output, in x86-64 Assembly
size_t asm_putc(int c);
```

[101-puts.asm](../0x09-libasm/101-puts.asm)
```nasm
;; Prints a string of characters on the standard output, in x86-64 Assembly
size_t asm_puts(const char *str);
```

[102-strcasecmp.asm](../0x09-libasm/102-strcasecmp.asm)
```nasm
;; Copycat of the function strcasecmp(3), in x86-64 Assembly
int asm_strcasecmp(const char *s1, const char *s2);
```

[103-strncasecmp.asm](../0x09-libasm/103-strncasecmp.asm)
```nasm
;; Copycat of the function strncasecmp(3), in x86-64 Assembly
int asm_strncasecmp(const char *s1, const char *s2, size_t n);
```

[104-strspn.asm](../0x09-libasm/104-strspn.asm)
```nasm
;; Copycat of the function strspn(3), in x86-64 Assembly
size_t asm_strspn(const char *s, const char *accept);
```

[105-strcspn.asm](../0x09-libasm/105-strcspn.asm)
```nasm
;; Copycat of the function strcspn(3), in x86-64 Assembly
size_t asm_strcspn(const char *s, const char *reject);
```

[106-strpbrk.asm](../0x09-libasm/106-strpbrk.asm)
```nasm
;; Copycat of the function strpbrk(3), in x86-64 Assembly
char *asm_strpbrk(const char *s, const char *accept);
```