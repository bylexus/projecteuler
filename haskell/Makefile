outputs = $(patsubst %.hs, bin/%, $(wildcard problem_*.hs))

.PHONY: build
build: $(outputs)

.PHONY:clean
clean:
	rm -f bin/*
	rm -f *.o *.hi

bin/%: %.hs EulerLib.hs
	mkdir -p bin
	echo $@ $<
	ghc -O -o $@ $<
