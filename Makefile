name = get_next.a


flags = -Wall -Wextra -Werror
# === FILES 
files = get_next_line.c get_next_line_utils.c
files_objects = $(files:.c=.o)

all: $(name)

$(name): $(files_objects)
	ar -rcs $(name) $(files_objects)

%.o: %.c
	@printf " [$(ok)OK$(RESET_COLOR)] $<\r"
	cc $(flags) -c $< -o $@

clean:
	rm -rf *.o

string ?= $(shell bash -c 'read -p "" username;')

create: $(name)
	cc $(flags) main.c $(name) -o mainProgram && ./mainProgram
	 @read -p "Enter Module Name:" module;
	./mainProgram $$module
	

fclean: clean
	rm -f $(name)

re: del

del: fclean
	rm -f mainProgram