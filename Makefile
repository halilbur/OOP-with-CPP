compile:program run clean
program:
		@g++ main.cpp -o main
run:
		@./main
clean:
		@rm -f *.o main
