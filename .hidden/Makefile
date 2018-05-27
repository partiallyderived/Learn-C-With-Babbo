C_FILES = $(shell find .. -not -path '../.*' -name '*.c')
PDF_FILES = $(shell find .. -not -path '../.*' -name '*.pdf')

.PHONY: gen_makefile
gen_makefile:
	./gen_make.sh

-include gen_makefile

.PHONY: add_c
add_c:
	git add $(C_FILES)
	
.PHONY: add_pdf
add_pdf:
	git add $(PDF_FILES)