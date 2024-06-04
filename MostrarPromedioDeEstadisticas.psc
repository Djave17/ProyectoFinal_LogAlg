Proceso MostrarPromedioDeEstadisticas
	definir acum,dato,n,prom, i  Como Entero;
	Escribir "Ingrese la cantidad de datos:";
	leer n;
	Para i <- 1 Hasta n  Hacer
		escribir "Ingrese el dato " , i;
		leer dato; acum <- n   + dato; 
	FinPara
	prom <- acum + dato;
	Escribir "el promedio es: " , prom;
FinProceso
