#include "../includes/vm.h"

inline int     valid_reg(int num)
{
    return ((num < REG_NUMBER && num > 0) ? 0 : 1);
}
