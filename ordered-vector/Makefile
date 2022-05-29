lib:
	g++ -std=c++11 -Wall -o test testing.cpp

app: 
	g++ -o app main.cpp

.PHONY: test
test: test
	./test --success

clean: 
	@echo "Removing executable files"
	rm app
	rm test
