# Valgrind memory test

echo Teste de memoria
valgrind -v --leak-check=full --show-leak-kinds=all ./main

