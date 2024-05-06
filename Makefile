mdderlebaglacalistir: derle bagla calistir

derle:
	g++ -c ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -c ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
	g++ -c ./src/main.cpp -o ./lib/main.o
	g++ -c ./src/print_Information.cpp -o ./lib/print_Information.o
	g++ -c ./src/Rules.cpp -o ./lib/Rules.o

bagla:
	g++  ./lib/Basamak.o ./lib/Dugum.o ./lib/Sayi.o ./lib/Rules.o ./lib/SayilarListesi.o ./lib/main.o ./lib/print_Information.o -o ./bin/run.exe

calistir:
	./bin/run.exe