SRC = ./src
OBJ = ./obj
BIN = ./bin

test : ${OBJ}/main.o \
		 	 ${OBJ}/LanguageGlobal.o \
		 	 ${OBJ}/LanguageManager.o \
		 	 ${OBJ}/LanguageObject.o \
		 	 ${OBJ}/LanguageTranslator.o \
		 	 ${SRC}/LanguageTag.hpp
	g++ -o ${BIN}/test \
				 ${OBJ}/main.o \
				 ${OBJ}/LanguageGlobal.o \
				 ${OBJ}/LanguageManager.o \
				 ${OBJ}/LanguageObject.o \
				 ${OBJ}/LanguageTranslator.o \
				 ${SRC}/*.hpp

${OBJ}/main.o :	${SRC}/main.cpp
	g++ -c -o ${OBJ}/main.o ${SRC}/main.cpp
					
${OBJ}/LanguageGlobal.o :	${SRC}/LanguageGlobal.cpp
	g++ -c -o ${OBJ}/LanguageGlobal.o ${SRC}/LanguageGlobal.cpp

${OBJ}/LanguageManager.o : ${SRC}/LanguageManager.cpp
	g++ -c -o ${OBJ}/LanguageManager.o ${SRC}/LanguageManager.cpp

${OBJ}/LanguageObject.o : ${SRC}/LanguageObject.cpp
	g++ -c -o ${OBJ}/LanguageObject.o ${SRC}/LanguageObject.cpp

${OBJ}/LanguageTranslator.o : ${SRC}/LanguageTranslator.cpp
	g++ -c -o ${OBJ}/LanguageTranslator.o ${SRC}/LanguageTranslator.cpp

${OBJ}/LanguageTag.o : ${SRC}/LanguageTag.hpp
	g++ -c -o ${OBJ}/LanguageTag.o ${SRC}/LanguageTag.hpp

clean : 
	rm -rf ${OBJ}/*
	rm -rf ${BIN}/*
