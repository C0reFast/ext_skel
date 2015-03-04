#ifndef _EXT_H_
#define _EXT_H_

typedef struct _function_entry {
    const char *fname;
    void (*handler)(void);
} function_entry;

typedef struct _ext_entry {
    const char *name;
    const int func_nums;
    const struct _function_entry *functions;
} ext_entry;

int load_ext(const char *extpath);
int call_ext_func(const char *extname, const char *func);

#endif
