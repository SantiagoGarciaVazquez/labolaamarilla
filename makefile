bin/bola : src/main.cpp src/bolaamarilla.cpp
	g++ src/main.cpp src/bolaamarilla.cpp -o bin/bola -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -pthread -Iinclude
run : bin/bola
	./bin/bola