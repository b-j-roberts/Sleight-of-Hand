COMPILER := clang++-9
CLANG_WARNS := -Weverything -Wextra -Wno-c++98-compat -Wno-padded -Wno-global-constructors -Wno-switch-enum -Wno-shorten-64-to-32 -Wno-weak-vtables -Wno-missing-prototypes

HARMONY_LOCATION := ~/workspace

VERSION := -std=c++2a
FLAGS := -O3 -ggdb
INC := -I lib/ -I ${HARMONY_LOCATION}

LINKS := -lsfml-graphics -lsfml-window -lsfml-system -L ${HARMONY_LOCATION}/Harmony -lharmony-basic

main: main.o obj/card.o obj/card_drawer.o obj/card_visual.o obj/card_inventory.o obj/card_pool.o obj/translate.o obj/board.o obj/mob.o
	${COMPILER} main.o obj/card.o obj/card_drawer.o obj/card_visual.o obj/card_inventory.o obj/card_pool.o obj/translate.o  obj/board.o obj/mob.o -o main ${FLAGS} ${LINKS}

main.o: main.cpp
	${COMPILER} -c main.cpp ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_pool.o: lib/card/card_pool.cpp
	${COMPILER} -c lib/card/card_pool.cpp -o obj/card_pool.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_inventory.o: lib/card/card_inventory.cpp
	${COMPILER} -c lib/card/card_inventory.cpp -o obj/card_inventory.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_drawer.o: lib/card/card_drawer.cpp
	${COMPILER} -c lib/card/card_drawer.cpp -o obj/card_drawer.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card_visual.o: lib/card/card_visual.cpp
	${COMPILER} -c lib/card/card_visual.cpp -o obj/card_visual.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/card.o: lib/card/card.cpp
	${COMPILER} -c lib/card/card.cpp -o obj/card.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/translate.o: lib/tools/translate.cpp
	${COMPILER} -c lib/tools/translate.cpp -o obj/translate.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/board.o: lib/map/board.cpp
	 ${COMPILER} -c lib/map/board.cpp -o obj/board.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

obj/mob.o: lib/mobs/mob.cpp
	 ${COMPILER} -c lib/mobs/mob.cpp -o obj/mob.o ${VERSION} ${FLAGS} ${INC} ${CLANG_WARNS}

clean:
	rm main main.o obj/* -r
