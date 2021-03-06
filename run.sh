#gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c && ./a.out
#gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=10000000 main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c && ./a.out
clang -Wall -Wextra -Werror -g -D BUFFER_SIZE=10000000 main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c && ./a.out
#valgrind --leak-check=full --tool=memcheck --show-leak-kinds=all --track-origins=yes get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
