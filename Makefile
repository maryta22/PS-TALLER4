hash: main.c
	gcc -static -o hash main.c ./.libs/libsha1.a
hash_dyn: main.c
	gcc -o hash_dyn main.c ./.libs/libsha1.so -Wl,-rpath,./.libs -L./.libs -lsha1
.PHONY: clean
clean:
	rm -rf hash hash_dyn
