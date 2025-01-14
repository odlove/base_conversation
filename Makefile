all: ./convert_base.c
	gcc convert_base.c -o xtb
	ln -sf xtb dtb

install: all
	cp xtb dtb ~/.local/bin

clean:
	rm -f xtb dtb
