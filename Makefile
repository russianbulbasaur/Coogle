flipit:
	mkdir bin/FlipIt
	gcc src/FlipIt/glb/glb.c -o bin/FlipIt/glb
	gcc src/FlipIt/game/game.c -o bin/FlipIt/game
	chmod +x bin/flipit
	echo "Execute flipit"

clean_flipit:
	rm bin/flipit


clean_all:
	rm -rf bin/*
	rm -rf **/**/o
	rm -rf **/**/a.out
	rm -rf **/**/*.gch
