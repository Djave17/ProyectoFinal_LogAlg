Proceso Agregar_Estadisticas
	Definir PtsNoted Como Entero;
	Definir PtsContra Como Entero;
	Definir AceMatches Como Entero;
	Definir NumParties Como Entero;
	Definir SuccessBlock Como Entero;
	Definir AttackSuccessful Como Entero;
	Definir RecSuccessful Como Entero;
	Definir EffectiveDefense Como Entero;
	Definir opcion Como Entero;
	Escribir 'Ingrese Pts Anotados';
	Leer PtsNoted;
	Escribir 'Ingrese Pts en Contra';
	Leer PtsContra;
	Escribir 'Ingrese Efectividad de saques';
	Leer AceMatches;
	Escribir 'Ingrese Numero de partidos';
	Leer NumParties;
	Escribir 'Ingrese Bloqueos efectivos por partidos';
	Leer SuccessBlock;
	Escribir 'Ingrese Errores no forzados por partido';
	Leer AttackSuccessful;
	Escribir 'Ingrese Efectividad de ataque';
	Leer RecSuccessful;
	Escribir 'Ingrese Efectividad de defensa';
	Leer EffectiveDefense;
	Escribir 'Seleccione una opcion:';
	Escribir '1. Ver resultados';
	Escribir '2. Agregar otro partido';
	Escribir '3. Finalizar';
	Leer opcion;
	Segun opcion Hacer
		1:
			Escribir 'Pts Anotados: ', PtsNoted;
			Escribir 'Pts en Contra: ', PtsContra;
			Escribir 'Efectividad de saques: ', AceMatches;
			Escribir 'Numero de partidos: ', NumParties;
			Escribir 'Bloqueos efectivos por partidos: ', SuccessBlock;
			Escribir 'Errores no forzados por partido: ', AttackSuccessful;
			Escribir 'Efectividad de ataque: ', RecSuccessful;
			Escribir 'Efectividad de defensa: ', EffectiveDefense;
		2:
			Agregar_Estadisticas();
		3:
			Escribir 'Gracias por usar el programa. ¡Hasta luego!';
		De Otro Modo:
			Escribir 'Opción no válida. Por favor, intente de nuevo.';
	FinSegun
FinProceso
