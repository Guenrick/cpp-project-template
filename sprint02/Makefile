all: compile run

compile:
	mkdir -p bin
	g++ -Wall src/system.cpp src/flow.cpp src/model.cpp test/funcional/main.cpp test/funcional/funcional_tests.cpp -o bin/funcional_tests

run:
	./bin/funcional_tests

clean:
	rm -rf bin/*