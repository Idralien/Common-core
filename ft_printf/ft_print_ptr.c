#include "ft_printf.h"

char     *make_string(unsigned int value, int *len)
{
        int                             i;
        unsigned int    tmp;
        char                    *str;

        i = 0;
        tmp = value;
        while (tmp != 0)
        {
                tmp = tmp / 16;
                i++;
        }
        str = ft_calloc(i + 1, sizeof(char));
        *len = i - 1;
        return (str);
}

int     ft_print_ptr(unsigned int value, int ascii)
{
        unsigned int    tmp_value;
        char                    *print;
        int                             i;
        int                             *iptr;

        iptr = &i;
        tmp_value = value;
        print = make_string(value, iptr);
        if (!print)
                return (0);
        while (tmp_value != 0 && i >= 0)
        {
                if ((tmp_value % 16) < 10)
                        print[i] = (tmp_value % 16) + 48;
                else
                        print[i] = (tmp_value % 16) + ascii;
                tmp_value = tmp_value / 16;
                i--;
        }
	i = ft_strlen(print);
	i = i + ft_print_str("0x");
        ft_putstr_fd(print, 1);
        free(print);
        if (value == 0)
                ft_print_char('0');
        return (i);
}

