ASM = asm/asm
WM = wm/corewar

all: $(ASM) $(WM)

$(ASM):
	@make -C asm

$(WM):
	@make -C wm

clean:
	@make clean -C asm
	@make clean -C wm

fclean: clean
	@make fclean -C asm
	@make fclean -C wm

re: fclean all
