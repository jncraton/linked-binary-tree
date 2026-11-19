all: test

%: %.cc
	g++ -std=c++23 $< -o $@

format:
	clang-format -i *.cc

test: tree.cc
	g++ -std=c++23 $< -o $@
	./$@
	
clean:
	rm -rf tree test
