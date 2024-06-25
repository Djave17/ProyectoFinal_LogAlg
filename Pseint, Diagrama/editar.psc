Algoritmo editar
	
	
	definir ptsNoted, ptsContra, gamesPlayed, successBlocks, attackSuccessful, recSuccessful, effectiveDefense, game como entero; 	definir op como entero; 
	Escribir "Ingrese el numero de partido que desea editar "; 
	definir op como entero;  
	leer game; 
	si game = 0 Entonces
		Escribir "No existe"; 
	FinSi
	si game < 0 Entonces
		Escribir "Ingrese una opcion para editar"; 
		Escribir "1. Puntos  " ;
		Escribir "2. Puntos ";
		Escribir "3. Aces";
		Escribir "4. Bloqueos exitosos";
		Escribir "5. Ataques exitosos";
		Segun op Hacer
			1: 
				Escribir "Ingrese la cantidad de puntos anotados en el partido ",  i + 1, ": ";
				Leer ptsNoted;
			2: 
				Escribir "Ingrese la cantidad de puntos recibidos en el partido " , i + 1 , ": ";
				leer ptsContra; 
				
				
			3: 
				Escribir "Ingrese la cantidad de aces en el partido " , i + 1 ,": ";
				leer acePartidos; 
				
		FinSegun
		
		
	FinSi
	
	
	
	
	
FinAlgoritmo
