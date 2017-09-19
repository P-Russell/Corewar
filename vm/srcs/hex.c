void	write_char_to_hex(unsigned char num, char *reg)
{
	char hex[16];

	ft_strcpy(hex, "0123456789ABCDEF");
	if (n < 16)
	{
		reg[0] = '0';
		reg[1] = hex[n];
	}
	else
	{
		reg[0] = hex[(num / 16) % 16];
		reg[1] = hex[num % 16];
	}
}