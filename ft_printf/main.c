#include "ft_printf.h"

int	main(void)
{
//	TESTS CHARACTER %c
	char	*character1 = "B";
	ft_printf("Test 1 char: %c\n", character1);

	char	character2 = 0;
	ft_printf("Test 2 char: %c\n", character2);

	char	*character3 = "Brent";
	ft_printf("Test 3 char: %c\n", character3);

//	TEST STRINGS %s
	char	*string1 = "Hello World!";
	ft_printf("Test 1 string: %s\n", string1);

	char	string2 = 0;
	ft_printf("Test 2 string: %s\n", string2);

	char	*string3 = "L";
	ft_printf("Test 3 string: %s\n", string3);

//	TEST POINTER %p
	int	nbr1 = 19;
	int	*ptr1 = &nbr1;
	ft_printf("Test 1 pointer: %p\n", (void *)ptr1);

	int	nbr2 = 0;
	int	*ptr2 = &nbr2;
	ft_printf("Test 2 pointer: %p\n", (void *)ptr2);

	int	nbr3 = 0;
	int	*ptr3 = &nbr3;
	ft_printf("Test 3 pointer: %p\n", (void *)ptr3);

//	TEST DECIMAL %d
	int	dec1 = -42;
	ft_printf("Test 1 decimal: %d\n", dec1);

	int	dec2 = 0;
	ft_printf("Test 2 decimal: %d\n", dec2);

	int	dec3 = 0;
	ft_printf("Test 3 decimal: %d\n", dec3);

	int	dec4 = 0;
	ft_printf("Test 4 decimal: %d\n", dec4);

	int	dec5 = -19;
	ft_printf("Test 5 decimal: %d\n", dec5);

	int	dec6 = -2147483648;
	ft_printf("Test 6 decimal: %d\n", dec6);

//	TEST INTEGER %i
	int	int1 = 101;
	ft_printf("Test 1 integer: %i\n", int1);

	int	int2 = 0;
	ft_printf("Test 2 integer: %i\n", int2);

	int	int3 = 0;
	ft_printf("Test 3 integer: %i\n", int3);

	int	int4 = 2147483647;
	ft_printf("Test 4 integer: %i\n", int4);

//	TEST UNSIGNED %u
	int	un1 = -42;
	ft_printf("Test 1 unsigned: %u\n", un1);

	int	un2 = -42;
	ft_printf("Test 2 unsigned: %u\n", un2);

	int	un3 = 606;
	ft_printf("Test 3 unsigned: %u\n", un3);

	int	un4 = -2147483648;
	ft_printf("Test 4 unsigned: %u\n", un4);

//	TEST HEXADECIMAL LOWERCASE AND UPPERCASE %x %X
	int	hex1_low = 90083;
	ft_printf("Test 1 hex lowercase: %x\n", hex1_low);

	int	hex2_low = 0;
	ft_printf("Test 2 hex lowercase: %x\n", hex2_low);

	int	hex3_low = 0;
	ft_printf("Test 3 hex lowercase: %x\n", hex3_low);

	char	*hex4_low = "AbcD22990";
	ft_printf("Test 4 hex lowercase: %x\n", hex4_low);

	int	hex1_upper = 90083;
	ft_printf("Test 1 hex uppercase: %X\n", hex1_upper);

	int	hex2_upper = 0;
	ft_printf("Test 2 hex uppercase: %X\n", hex2_upper);

	int	hex3_upper = 0;
	ft_printf("Test 3 hex uppercase: %X\n", hex3_upper);

	char	*hex4_upper = "AbcD22990";
	ft_printf("Test 4 hex uppercase: %X\n", hex4_upper);

//	TEST PRECENT SIGN %%
	char	*per1 = "%";
	ft_printf("Test 1 percent sign: %%\n", per1);

	char	per2 = 0;
	ft_printf("Test 2 percent sign: %%\n", per2);

	return (0);
}
