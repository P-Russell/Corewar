#include "../includes/vm.h"

int     is_direct(int acb, int param_num)
{
    int     i;

    i = 0;
    while (i < param_num)
    {
        acb = acb << 2;
        i++;
    }
    if ((acb & 0b11000000) == 0b100000000)
        return (1);
    return (0);
}

int     is_indirect(int acb, int param_num)
{
    int     i;

    i = 0;
    while (i < param_num)
    {
        acb = acb << 2;
        i++;
    }
    if ((acb & 0b11000000) == 0b11000000)
        return (1);
    return (0);
}

int     is_register(int acb, int param_num)
{
    int     i;

    i = 0;
    while (i < param_num)
    {
        acb = acb << 2;
        i++;
    }
    if ((acb & 0b11000000) == 0b01000000)
        return (1);
    return (0);
}
