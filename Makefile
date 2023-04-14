name = get_next.a


flags = -Wall -Wextra -Werror
# === FILES 
files = get_next_line.c get_next_line_utils.c
files_objects = $(files:.c=.o)

all: $(name)

$(name): $(files_objects)
	make -C ./printf
	cp ./printf/libftprintf.a .
	mv libftprintf.a $(name)
	ar -rcs $(name) $(files_objects)

%.o: %.c
	@printf " [$(ok)OK$(RESET_COLOR)] $<\r"
	cc $(flags) -I ./printf/include -c $< -o $@

clean:
	rm -rf *.o

create: $(name)
	cc $(flags) -I ./printf/include main.c $(name) && ./a.out
	./a.out

fclean: clean
	make fclean -C ./printf/
	rm -f $(name)