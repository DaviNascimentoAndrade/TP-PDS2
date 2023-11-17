CC = c++
CFLAGS =

obj1 = casa
obj2 = comodo
obj3 = ar_condicionado
obj4 = cortina
obj5 = janela
obj6 = lampada
obj7 = tranca

main: main.o $(obj1).o $(obj2).o $(obj3).o $(obj4).o $(obj5).o $(obj6).o $(obj7).o
	$(CC) $(CFLAGS) -o main *.o

main.o: include/$(obj1).h include/$(obj2).h include/$(obj3).h include/$(obj4).h include/$(obj5).h include/$(obj6).h include/$(obj7).h src/main.cc
	$(CC) $(CFLAGS) -c src/main.cc

$(obj1).o: include/$(obj1).h include/$(obj2).h src/$(obj1).cc
	$(CC) $(CFLAGS) -c src/$(obj1).cc

$(obj2).o: include/$(obj2).h include/$(obj3).h include/$(obj4).h include/$(obj5).h include/$(obj6).h include/$(obj7).h src/$(obj2).cc
	$(CC) $(CFLAGS) -c src/$(obj2).cc

$(obj3).o: include/$(obj3).h src/$(obj3).cc
	$(CC) $(CFLAGS) -c src/$(obj3).cc

$(obj4).o: include/$(obj4).h src/$(obj4).cc
	$(CC) $(CFLAGS) -c src/$(obj4).cc

$(obj5).o: include/$(obj5).h src/$(obj5).cc
	$(CC) $(CFLAGS) -c src/$(obj5).cc

$(obj6).o: include/$(obj6).h src/$(obj6).cc
	$(CC) $(CFLAGS) -c src/$(obj6).cc


$(obj7).o: include/$(obj7).h src/$(obj7).cc
	$(CC) $(CFLAGS) -c src/$(obj7).cc

clean:
	rm -f main.o $(obj1).o $(obj2).o $(obj3).o $(obj4).o $(obj5).o $(obj6).o $(obj7).o
