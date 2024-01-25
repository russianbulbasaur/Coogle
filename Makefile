flipit:
	gcc src/FlipIt/server.c -o bin/flipit
	chmod +x bin/flipit
	echo "Execute flipit"

clean_flipit:
	rm bin/flipit


clean_all:
	rm -rf bin/*
	rm -rf **/**/o
	rm -rf **/**/a.out
