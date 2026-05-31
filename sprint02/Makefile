all: compile run

compile:
	mkdir -p bin
	g++ -Wall src/system.cpp src/flow.cpp src/model.cpp test/funcional/main.cpp test/funcional/funcional_tests.cpp -o bin/funcional_tests
	@echo "Compilação funcional concluída."

compile_unit:
	mkdir -p bin
	g++ -Wall src/system.cpp src/flow.cpp src/model.cpp test/unit/main.cpp test/unit/unit_tests.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp test/unit/unit_Model.cpp -o bin/unit_tests
	@echo "Compilação de testes unitários concluída."

run:
	./bin/funcional_tests

run_unit:
	./bin/unit_tests

test: compile run compile_unit run_unit

clean:
	rm -rf bin/*