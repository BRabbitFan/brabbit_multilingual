
SRC = ./src
OBJ = ./obj
BIN = ./bin

clean : 
	rm -rf ${OBJ}/*
	rm -rf ${BIN}/*

test : 	${OBJ}/main.o \
				${OBJ}/LanguageGlobal.o \
				${OBJ}/LanguageManager.o \
				${OBJ}/LanguageObject.o \
				${OBJ}/LanguageTranslator.o \
				${OBJ}/LanguageTag.o
	g++ -o 	${BIN}/test \
					${OBJ}/main.o \
					${OBJ}/LanguageGlobal.o \
					${OBJ}/LanguageManager.o \
					${OBJ}/LanguageObject.o \
					${OBJ}/LanguageTranslator.o \
					${OBJ}/LanguageTag.o \
					${SRC}/main.cpp

${OBJ}/main.o : ${SRC}/main.cpp
	g++ ${SRC}/main.cpp -o ${OBJ}/main.o

${OBJ}/LanguageGlobal.o :	${SRC}/LanguageGlobal.hpp \
													${SRC}/LanguageGlobal.cpp \
													${SRC}/main.cpp
	g++ -o 	${OBJ}/LanguageGlobal.o \
					${SRC}/LanguageGlobal.hpp \
					${SRC}/LanguageGlobal.cpp \
					${SRC}/main.cpp

${OBJ}/LanguageManager.o : 	${SRC}/LanguageManager.hpp \
														${SRC}/LanguageManager.cpp \
														${SRC}/main.cpp
	g++ -o 	${OBJ}/LanguageManager.o \
					${SRC}/LanguageManager.hpp \
					${SRC}/LanguageManager.cpp \
					${SRC}/main.cpp

${OBJ}/LanguageObject.o : ${SRC}/LanguageObject.hpp \
													${SRC}/LanguageObject.cpp \
													${SRC}/main.cpp
	g++ -o 	${OBJ}/LanguageObject.o \
					${SRC}/LanguageObject.hpp \
					${SRC}/LanguageObject.cpp \
					${SRC}/main.cpp

${OBJ}/LanguageTranslator.o : ${SRC}/LanguageTranslator.hpp \
															${SRC}/LanguageTranslator.cpp \
															${SRC}/main.cpp
	g++ -o 	${OBJ}/LanguageTranslator.o \
					${SRC}/LanguageTranslator.hpp \
					${SRC}/LanguageTranslator.cpp \
					${SRC}/main.cpp

${OBJ}/LanguageTag.o : 	${SRC}/LanguageTag.hpp \
												${SRC}/main.cpp
	g++ -o 	${OBJ}/LanguageTag.o \
					${SRC}/LanguageTag.hpp \
					${SRC}/main.cpp
