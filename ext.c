#include <dlfcn.h>
#include <string.h>
#include "ext.h"


#define MAX_EXT_NUM 10


ext_entry* exts[MAX_EXT_NUM] = {0};

int ext_num = 0;



int load_ext(const char *path)
{
    if (ext_num == MAX_EXT_NUM) {
        return -1;
    }

    void *handle;
    ext_entry* entry;
    ext_entry* (*get_ext_entry)(void);
    
    handle = dlopen(path, RTLD_LAZY | RTLD_GLOBAL);
    if (!handle) {
        return -2;
    }
    
    get_ext_entry = (ext_entry *(*)(void)) dlsym(handle, "get_ext_entry");
    if (!get_ext_entry) {
        dlclose(handle);
        return -3;
    }

    entry = get_ext_entry();
    exts[ext_num++] = entry;

    return ext_num;
}


int call_ext_func(const char *extname, const char *func)
{
    for (int i=0; i<ext_num; i++)
    {
        if (strcmp(extname, exts[i]->name) == 0) {
            for (int j=0; j<exts[i]->func_nums; j++) {
                if (strcmp(func, exts[i]->functions[j].fname) == 0) {
                    exts[i]->functions[j].handler();
                    return 0;
                }
            }
        }
    }
    return -1;
}
