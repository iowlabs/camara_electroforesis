# Cámara electroforésis

Este proyecto tiene como objetivo el diseño de una cámara de electroforesis de bajo costo y fácil acceso, ideal para entornos educativos, laboratorios escolares,  iniciativas de ciencia ciudadana, equipamientos de bajo costo o laboratorios portátiles. El sistema completo incluye tanto la cámara donde se realiza la separación de moléculas como una fuente de poder casera que permite aplicar el voltaje necesario para el experimento.
El diseño y la implementación de este proyecto están fuertemente inspirados en la documentación proporcionada por IORodeo, quienes han compartido detalladamente cómo construir sistemas de electroforesis caseros. En particular, se han seguido y adaptado los siguientes recursos:

- [Cámara de electroforesis - Instructables](https://www.instructables.com/Gel-electrophoresis-system-mini/)
- [Fuente de poder - Instructables](https://www.instructables.com/Gel-electrophoresis-power-supply/)


Este repositorio prone un nuevo diseño orientado a consolidar y empaquetar el proceso de fabricación de los componentes por medio de nuevos diseños basados principalmente en impresión 3D. De este modo se consolida la información, archivos de diseño, materiales necesarios y las mejoras propuestas por iow Labs con la intención de facilitar la replicabilidad y su uso por parte de otras personas o instituciones interesadas en el uso de tecnologías abiertas en la ciencia.

---
# Licencias
Todos los archivos involucrados en este proyecto se encuentran bajo licencias abiertas, para su replicabilidad y comercialización.

| Tipo de archivo | Licencia |
| ---             |  -----   |
| Electronica 	  |  CERN-OHL-S-2.0 |
| Software y firmware |  GPL-3.0-or-later|
| Diseños 3D |  CERN-OHL-S-2.0 |
| Archivos de documentación | CC-BY-SA-4.0 |


---

# Cámara

En este diseño se propone un modelo de cámara impreso totalmente, como una pieza continua. De este modo, se facilita el proceso de fabricación evitando trabajar con acrílico y las complicaciones que esto implica.


## Materiales

Los tanques para la electróforesis habitualmente se fabrican con acrílico, sin embargo el proceso de cortado y pegado suele ser dificil de gestionar ya que requiere habilidades manuales princilamnte debido a que involucra la manipulación de cloroformo.

Para evitar esto, se implementó una alternativa basada en impresión 3D. Para replicar las características del acrílico se evaluaron diferentes materialidades y metodologías. Finalmente, se optó por imprimir el cuerpo del tanque en PETG para garantizar el buen desempeño en altas temperaturas y para garantizar la impermeabilidad, se optó por aplicarle una capa de resina epoxyca al interior. La tapa se realiza en un solo corte acrílico, para garantizar la transparencia.   



| Pieza 	| Material | Archivo |
| --------- | -------- | ------- |
| Tanque   	|  PETG    | [tanque_V2.stl](https://github.com/iowlabs/camara_electroforesis/blob/main/3d%20models/tank_v2.stl) |
| Tapa		| Acrílico | [tapa_V2.stl](https://github.com/iowlabs/camara_electroforesis/blob/main/3d%20models/tapa_v2.stl) |

### Instrucciones de fabricación



## Lista de materiales

| N    | Componente 	| Cantidad | Comentario |
|------|----------------|----------|------------|
| 1    | Tanque         |  1       |            |
| 2    | Tapa           |  1       |            |
| 3    | Conectores banana     |  2   | Tipo macho |
| 4    | Electrodos de pt |  2   | arpox 20cm de cable de 0.01'' de platino           |


## Instrucciones de armado


---

# Fuente de poder

Para implementar la fuente se diseñó una PCB que integre los componentes considerando en su mayoría componentes SMD. Esta PCB consiste en la implementación de un conversor DC/DC del tipo chopper bust. Este diseño se basa en el integrado MAX117 y la topología utilizada se encuentra detallada en los siguientes documentos 3,4,5
Esta topología es utilizada ampliamente por diferentes proyectos como el Open Drop o la misma fuente de electroforesis de IORodeo. Adicionalmente se consideró agregar un microcontrolador de la familia ESP32S3 para agregar nuevas funcionalidades al diseño y poder considerar en una implementación futura las capacidades de conectividad para montar  una red Lab on a Web que permita controlar todo el laboratorio de forma centralizada y remota.

El esquemático completo se entrega en la siguiente imagen.

![Esquemático de la PCB](https://github.com/iowlabs/camara_electroforesis/blob/main/electronics/fuente_regulable/output_files/fuente_regulable.svg)


A continuación se entregan imágenes de las visualizaciones 3D del render de la PCB

![PCB 3D](https://github.com/iowlabs/camara_electroforesis/blob/main/electronics/fuente_regulable/output_files/render_3d_camara_electroforesis.png)


La PCB considera la integración de una interfaz de usuario implementada por medio de un rotary switch y una pantalla OLED con el objetivo de visualizar el valor actual de voltaje de salida.

Para integrar todos los componentes de forma segura se ha diseñado un casing 3D impreso en PLA.

### Archivos de fabricación
Los archivos de fabricación de la PCB se encuentran disponibles en formato ZIP en el directorio de [archivos de salida](https://github.com/iowlabs/camara_electroforesis/tree/main/electronics/fuente_regulable/output_files) listos para ser enviados a fabricación.

Para el casing, los archivos se encuentran en la carpeta de modelos 3D.


| Pieza 	| Material | Archivo |
| --------- | -------- | ------- |
| Tapa superior   	|  PLA   | [fure_tapa.step](https://github.com/iowlabs/camara_electroforesis/blob/main/3d%20models/tank_v2.stl) |
| Cara frontal		| PLA | [fure_cara.step](https://github.com/iowlabs/camara_electroforesis/blob/main/3d%20models/tapa_v2.stl) |
|  Base		| PLA | [fure_base.step](https://github.com/iowlabs/camara_electroforesis/blob/main/3d%20models/tapa_v2.stl) |

### BOM de PCB
La lista de los componentes se encuentra disponible en el archivo BOM  [fuente_regulable_bom.csv](https://github.com/iowlabs/camara_electroforesis/blob/main/electronics/fuente_regulable/output_files/fuente_regulable_bom.csv), como referencia se consideran de LCSC.


### Lista de materiales para la fuente regulable.

| N    | Componente 	| Cantidad | Comentario |
|------|----------------|----------|------------|
| 1    | FuRe PCB         |  1       | PCB by iow Labs |
| 2    | Conectores banana|  2       |  Tipo hembra  |
| 3    | Cables banana     |  2   | Tipo macho - hembra |
| 4    | Switch on/off |  1   |  |
| 5    | Rotary encoder switch |  1   |  |
| 6    | Jack DC |  1   |  |
| 7    | Pantalla OLED |  1   |  |
| 8    | case - superior |  1   | Pieza impresa |
| 9    | case - frontal |  1   | Pieza impresa |
| 10   | case - base |  1   | Pieza impresa |
| 11   | Fuente de 12V |  1   | Al menos 1A (12W) |
| 12   | Tornillos M3 |  6   | Al menos 12mm |
| 13   | Tuercas M3 |  4   |   |
| 14   | Cable AWG 20 |  -   | Para conexiones internas   |
| 15   | Cable AWG 26 - 4 wires |  1   | Cable de la pantalla OLED   |
| 16   | Cable AWG 26 - 5 wires |  1   | Cable del rotary encoder   |


### Firmware

El firmware se puede encontrar en el directorio [firmware](https://github.com/iowlabs/camara_electroforesis/tree/main/firmware). Esta escrito en el framwork de arduino. Para cargarlo correctamente es necesario configurar en el IDE de arduino la placa ESP32-S3. Para esto se puede usar el modelo ESP32-S3-DEV-Kit.

El código subido implementa una interfaz sencilla entre el rotary encoder y el voltaje de salida que se configura en el módulo MAX117 por medio de un potenciomentro digital configurado por SPI.

Todas las bibliotecas utilizadas se encuentran dentro del repositorio oficial de arduino.

## Instrucciones de ensamblado
