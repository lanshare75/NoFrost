# NoFrost (04/03/2020 JMT)
Controlador de Heladera NoFrost Philips Wirlpoll ARF-430
Caracteristicas:
Volumen: 410 Litros
Refrigerante: R12(300grs)
Potencia: 225w (Nominal)
Corriente: 1.4Amp (Nominal)
Version: XRG.40KXBDB
Motocompresor: Embraco FF10 BKW - 14LRA
Año Fabricación: 1997


Se controlará una heladera NoFrost con una placa Arduino Nano, para que funcione en 3 MODOS distintos:
MODOS:
1) Fermentar , Madurar y Clarificar Cerveza
2) Servicio de serveza
3) Funcionamiento de Heladera Comun.

Detalle General del funcionamiento No Frost Tradicional Mecanico.
Las Heladeras NoFrost poseen un timer (12x21) el cual mantiene a la heladera en funcionamiento durante 12hs.
Cada 12 horas corta el motor principal y el forzador y enciende la resistencia de defrost(22v x 200w) durante 21 minutos.
Este timer es independiente del Termostaro de la heladera quien esta conectado en serie con el timer y es el encargado de cortar por la temperatura sensada en el interior del refrigerador.
Por lo tanto: mientras el timer mantiene al sistema encendido por 12 horas, el termostato cortará el motocopresor si en el interior del refrigerador esta a la temperatura seteada en el termostaro.


