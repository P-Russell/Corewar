int		ft_add(t_champ *champ, t_reg *arena)
{
	/* inside champ the pc points to the register in 
	arena where the start of the next set of instruction is
	the value at this register will be the opcode for add*/
	int	acb;		//argument encoding byte
	int	param1;
	int	param2;
	int	param3;
	int	sum;

	acb = get_value_from_reg(pc + 1);		// add has an argument encoding byte
	param1 = get_value_from_reg(pc + 2);	// assuming that the byte code has been compiled correctly these values will be here
	param2 = get_value_from_reg(pc + 3);	// the plus one to the addess is base on the macro REG_SIZE being one byte
	param3 = get_value_from_reg(pc + 4);

	if (check_params_are_valid_registers() < 0)
		return (-1)

	champ->reg[param3] = param1 + param2;
	champ->pc += 5; 				// better to write function that moves the pc to the next opcode to avoid segfault
	champ->cycles_to_exec = g_op_tab[pc->raw - 1].nb_cycles;
	return (1);
}