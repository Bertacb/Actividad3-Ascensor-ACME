# Actividad3-Ascensor-ACME
## Descripción

Este repositorio contiene el desarrollo de la Actividad 3 de la asignatura Equipos e Instrumentación Electrónica.

El objetivo del proyecto es perfeccionar el sistema de control del ascensor industrial ACME mediante una estrategia de instrumentación avanzada basada en autodiagnóstico.

## Funcionalidades implementadas

- Medición de temperatura y humedad mediante DHT22.
- Medición de iluminación mediante LDR.
- Visualización de datos en pantalla LCD I2C.
- Control automático de iluminación mediante LED verde.
- Alarma de temperatura mediante LED rojo y buzzer.
- Autodiagnóstico de sensores.
- Activación de modo seguro ante valores anómalos.

## Autodiagnóstico

El sistema comprueba automáticamente:

- Lecturas inválidas del sensor DHT22.
- Temperaturas fuera del rango permitido.
- Humedad fuera del rango permitido.
- Valores anómalos del sensor LDR.

Cuando se detecta un fallo, el sistema entra en modo seguro, activa la alarma visual y acústica y muestra el mensaje "FALLO SENSOR" en la pantalla LCD.

## Estructura del repositorio

- `codigo/`: código fuente Arduino.
- `BOM/`: lista de materiales.
- `diagramas/`: diagrama lógico del programa.
- `esquematico_wokwi.png`: captura del circuito en Wokwi.
- `memoria.pdf`: memoria final de la actividad.

## Componentes utilizados

- Arduino UNO
- DHT22
- LDR
- LCD I2C 16x2
- LED verde
- LED rojo
- Buzzer
- Resistencias de 220 Ω

## Enlace a la simulación Wokwi

https://wokwi.com/projects/465561795760159745
