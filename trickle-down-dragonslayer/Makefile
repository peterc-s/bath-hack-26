.PHONY: run
run: build/out.wav
	# sudo uv run trickle-down-dragonslayer

build/out.wav: build build/main.bas
	./basic2tape.sh build/main.bas build/main.wav

build/main.bas: build src/basic/main.bas
	cd apple-tools && \
	uv run preprocess ../src/basic/main.bas > ../build/main.bas

build:
	mkdir -p build/

.PHONY: clean
clean:
	rm -r build/
