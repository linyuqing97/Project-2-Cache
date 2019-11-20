M = Main
C = cache-sim
DC = DirectCache
SAC = SetAssociateCache
FAC = FullAssociateCache
PF = Prefetch
SAN = SetAssociateNot
HC = HotCold

CFLAGS= -std=c++14  -O2 

Main: $(M)


$(M):$(M).o $(DC).o $(SAC).o $(FAC).o $(PF).o $(SAN).o $(HC).o
	g++ $(M).o $(DC).o $(SAC).o $(FAC).o $(PF).o $(SAN).o $(HC).o -o $(C)



$(FAC).o:$(FAC).cpp 
	g++ $(CFLAGS) -c  $(FAC).cpp -o $(FAC).o

$(DC).o:$(DC).cpp 
	g++ $(CFLAGS) -c  $(DC).cpp -o $(DC).o

$(SAC).o:$(SAC).cpp 
	g++ $(CFLAGS) -c  $(SAC).cpp -o $(SAC).o

$(PF).o:$(PF).cpp 
	g++ $(CFLAGS) -c  $(PF).cpp -o $(PF).o


$(SAN).o:$(SAN).cpp 
	g++ $(CFLAGS) -c  $(SAN).cpp -o $(SAN).o

$(HC).o:$(HC).cpp 
	g++ $(CFLAGS) -c  $(HC).cpp -o $(HC).o
clean:
	rm -rf *.o  $(C)