C_FILES = $(shell find .. -not -path '../.*' -name '*.c')

.PHONY: gen_makefile
gen_makefile:
	./gen_make.sh

-include gen_makefile

.PHONY: add_c
add_c:
	git add $(C_FILES)
	