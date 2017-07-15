FINAL_FILE=out.exe
SRC=test/test.cpp

${FINAL_FILE}: ${SRC}
	g++ -g ${SRC} -o ${FINAL_FILE}

all: ${FINAL_FILE}
