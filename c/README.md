C solutions
==============

Build with:

* `for i in *.c; do clang -O3 -o ${i%.*} $i;done`
or:
* `for i in *.c; do gcc -O3 -o ${i%.*} $i;done`
