CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -o pathfinder
CPSRC = \
inc/pathfinder.h \
libmx/inc/libmx.h \
src/main.c \
src/errors.c \
src/parsing.c \
src/core.c \
src/output.c \
src/utils/mx_byindex.c \
src/utils/mx_vertex_lists.c \
src/utils/mx_misc_parsing.c \
src/utils/mx_misc_core.c \
src/utils/mx_misc_memory.c \
src/utils/mx_misc_output.c \

SRC = \
main.c \
errors.c \
parsing.c \
core.c \
output.c \
mx_byindex.c \
mx_vertex_lists.c \
mx_misc_parsing.c  \
mx_misc_core.c \
mx_misc_memory.c \
mx_misc_output.c \

all: install clean
reinstall: uninstall all
install:
	@make -C libmx
	@mv libmx/libmx.a libmx.a
	@cp $(CPSRC) .
	@clang $(CFLAGS) $(SRC) libmx.a
clean:
	@rm -rf $(SRC) libmx.h pathfinder.h libmx.a
uninstall:
	@rm pathfinder
