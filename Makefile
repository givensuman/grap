all: build
	@echo "Done!"

build: grep.c search.c linked_list.c
	@echo "Building..."
	@gcc -o grep grep.c search.c linked_list.c

clean :
	@rm *.o ./grep
