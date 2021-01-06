#include <stdio.h>
#include <stdlib.h>
#define null ((void *)0)
typedef struct sad
{
    int num;
    void (*set_num)(struct sad *, int);
    int (*get_num)(struct sad *);
    void (*del_sad)(struct sad *);
} sad;
void set_num(sad *thissad, int _num)
{
    thissad->num = _num;
}
int get_num(sad *thissad)
{
    return thissad->num;
}
void del_sad(sad *thissad)
{
    free(thissad);
    thissad = null;
}
sad *new_sad(int _num)
{
    sad *new_sad = (sad *)malloc(sizeof(sad));
    if (!new_sad)
    {
        return null;
    }
    new_sad->num = (int)malloc(sizeof(int));
    if (!new_sad->num)
    {
        return null;
    }

    new_sad->get_num = get_num;
    new_sad->set_num = set_num;
    new_sad->del_sad = del_sad;

    new_sad->set_num(new_sad, _num);

    return new_sad;
}

int main(int argc, char **argv)
{
    printf("sad_begin\n");
    sad *mysad = new_sad(3);

    printf("sad init: %d\n", mysad->get_num(mysad));
    mysad->set_num(mysad, 2);

    printf("sad now: %d\n", mysad->get_num(mysad));
    mysad->del_sad(mysad);

    printf("sad_over");
    return 0;
}