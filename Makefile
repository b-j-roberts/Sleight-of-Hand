COMPILER := clang++
CLANG_WARNS := -Weverything -Wextra -Wno-c++98-compat -Wno-padded -Wno-global-constructors -Wno-switch-enum -Wno-shorten-64-to-32 -Wno-weak-vtables -Wno-missing-prototypes

VERSION := -std=c++1z
FLAGS := -O3 -ggdb
INC := -I lib/

LINKS := -lsfml-graphics -lsfml-window -lsfml-system

main: main.o obj/card.o obj/card_drawer.o obj/card_visual.o
	${COMPILER} main.o obj/card.o obj/card_drawer.o obj/card_visual.o -o main ${FLAGS} ${LINKS}

main.o: main.cpp
	${COMPILER} -c main.cpp ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_drawer.o: lib/card/card_drawer.cpp
	${COMPILER} -c lib/card/card_drawer.cpp -o obj/card_drawer.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_visual.o: lib/card/card_visual.cpp
	${COMPILER} -c lib/card/card_visual.cpp -o obj/card_visual.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card.o: lib/card/card.cpp
	${COMPILER} -c lib/card/card.cpp -o obj/card.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

clean:
	rm main main.o obj/* -r
