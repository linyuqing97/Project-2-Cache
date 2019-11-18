M = Main
DC = DirectCache
SAC = SetAssociateCache
FAC = FullAssociateCache
PF = Prefetch
SAN = SetAssociateNot

CFLAGS= -std=c++14  -O2 

Main: $(M)


$(M):$(M).o $(DC).o $(SAC).o $(FAC).o $(PF).o $(SAN).o
	g++ $(M).o $(DC).o $(SAC).o $(FAC).o $(PF).o $(SAN).o -o $(M)



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
clean:
	rm -rf *.o  $(M)