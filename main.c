#include <stdio.h>
#include "ext.h"



int main(int argc, char *argv[])
{
    char path[100] = {0};
    char ext[100] = {0};
    char func[100] = {0};
    scanf("%s", path);
    printf("%d\n", load_ext(path));
    scanf("%s", ext);
    scanf("%s", func);

    call_ext_func(ext, func);
    return 0;
}
