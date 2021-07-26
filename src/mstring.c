#define _CRT_SECURE_NO_WARNINGS

#include "mstring.h"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

static void _mstring_grow(mstring_t *str, int new_len) {
    if (str->cap < new_len) {
        char *old_cstr = str->cstr;  
        str->cap = 2 * (new_len + 1);
        str->cstr =  malloc(sizeof(char)*(str->cap + 1));
        strcpy(str->cstr, old_cstr);
        free(old_cstr);
    }
}

void mstring_init(mstring_t *str, const char *cstr) {
    int len = (int)strlen(cstr);
    str->cap = len;
    str->len = len;
    str->cstr = malloc(sizeof(char)*(str->cap + 1));
    strcpy(str->cstr, cstr);
}

void mstring_initf(mstring_t *str, const char *format, ...) {
    va_list args; 
    va_start(args, format); 
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    str->cap = len;
    str->len = len;
    str->cstr = malloc(sizeof(char)*(str->cap + 1));

    va_start(args, format); 
    vsprintf(str->cstr, format, args);
    va_end(args);
}

void mstring_deinit(mstring_t *str) {
    free(str->cstr);
}

void mstring_append_str(mstring_t *str, mstring_t *str2) {
    mstring_append_cstr(str, str2->cstr);
}

void mstring_append_cstr(mstring_t *str, const char *cstr) {
    int cstr_len = (int)strlen(cstr);
    mstring_append_cstr_len(str, cstr, cstr_len);
}

void mstring_append_cstr_len(mstring_t *str, const char *cstr, int cstr_len) {
    if (str->cap >= cstr_len + str->len) {
        strcat(str->cstr, cstr);
    }
    else {
        char *old_cstr = str->cstr;
        str->len = str->len + cstr_len;
        str->cap = str->len;
        str->cstr = malloc(sizeof(char)*(str->cap + 1));
        strcpy(str->cstr, old_cstr);
        strcat(str->cstr, cstr);
        free(old_cstr);
    }
}

void mstring_appendf(mstring_t *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    _mstring_grow(str, str->len + len);
    va_start(args, format);
    vsprintf(str->cstr + str->len, format, args);
    va_end(args);
    str->len += len;
}
