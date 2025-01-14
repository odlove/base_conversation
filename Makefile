LINKS = x d b

all: xtb
	@for l1 in $(LINKS); do \
		for l2 in $(LINKS); do \
			ln -sf xtb "$${l1}t$${l2}"; \
		done; \
	done

xtb: convert_base.c
	gcc convert_base.c -o xtb

install: all
	@for l1 in $(LINKS); do \
		for l2 in $(LINKS); do \
			mv "$${l1}t$${l2}" ~/.local/bin; \
		done; \
	done

uninstall:
	@for l1 in $(LINKS); do \
		for l2 in $(LINKS); do \
			trash  ~/.local/bin/"$${l1}t$${l2}"; \
		done; \
	done



clean:
	@for l1 in $(LINKS); do \
		for l2 in $(LINKS); do \
			trash "$${l1}t$${l2}"; \
		done; \
	done
