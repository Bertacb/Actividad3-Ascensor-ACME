# Diagrama lógico del código

Inicio  
↓  
Inicialización de LCD, DHT22, LEDs y buzzer  
↓  
Lectura de sensores: temperatura, humedad e iluminación  
↓  
Autodiagnóstico de sensores  
↓  
¿Existe fallo en DHT22 o LDR?  

Sí → Activar modo seguro  
- Apagar LED verde  
- Encender LED rojo  
- Activar buzzer  
- Mostrar "FALLO SENSOR" en LCD  

No → Continuar control normal  
↓  
¿Luz < 500?  
- Sí: encender LED verde  
- No: apagar LED verde  

↓  
¿Temperatura > 28 ºC?  
- Sí: encender LED rojo y buzzer  
- No: apagar LED rojo y buzzer  

↓  
Mostrar valores en LCD  
↓  
Repetir ciclo
