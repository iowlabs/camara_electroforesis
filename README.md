# Cámara electroforésis

Este proyecto tiene como objetivo el diseño de una cámara de electroforesis de bajo costo y fácil acceso, ideal para entornos educativos, laboratorios escolares,  iniciativas de ciencia ciudadana, equipamientos de bajo costo o laboratorios portátiles. El sistema completo incluye tanto la cámara donde se realiza la separación de moléculas como una fuente de poder casera que permite aplicar el voltaje necesario para el experimento.
El diseño y la implementación de este proyecto están fuertemente inspirados en la documentación proporcionada por IORodeo, quienes han compartido detalladamente cómo construir sistemas de electroforesis caseros. En particular, se han seguido y adaptado los siguientes recursos:

- Cámara de electroforesis - Instructables
- Fuente de poder - Instructables


Este repositorio prone un nuevo diseño orientado a consolidar y empaquetar el proceso de fabricación de los componentes por medio de nuevos diseños basados principalmente en impresión 3D. De este modo se consolida la información, archivos de diseño, materiales necesarios y las mejoras propuestas por iow Labs con la intención de facilitar la replicabilidad y su uso por parte de otras personas o instituciones interesadas en el uso de tecnologías abiertas en la ciencia.

## Cámara

En este diseño se propone un modelo de cámara impreso totalmente en PLA como una pieza continua. De este modo se facilita el proceso de fabricación evitando trabajar con acrílico y las complicaciones que esto implica.
### Materiales

Para la fabricación de esta cámara se necesitan los siguientes componentes

1
Cámara
Impreso en pla
disponible en este cámara .step
1
Peine
Impreso en pla
disponible en peine.step
2
Conectores banana tipo Macho de panel
1
Cable de platino de 0,1’’
Como alternativa puede cambiarse por acer inoxidable

1
Plancha de acrílico
Tapa superior- corte laser
disponible en tapasuperior.step










## Fuente de poder
Para implementar la fuente se diseñó una PCB que integre los componentes considerando en su mayoría componentes SMD. Esta PCB consiste en la implementación de un conversor DC/DC del tipo chopper bust. Este diseño se basa en el integrado MAX117 y la topología utilizada se encuentra detallada en los siguientes documentos 3,4,5
Esta topología es utilizada ampliamente por diferentes proyectos como el Open Drop o la misma fuente de electroforesis de IORodeo. Adicionalmente se consideró agregar un microcontrolador de la familia ESP32S3 para agregar nuevas funcionalidades al diseño y poder considerar en una implementación futura las capacidades de conectividad para montar  una red Lab on a Web que permita controlar todo el laboratorio de forma centralizada y remota.

El esquemático completo se entrega en la siguiente imagen.





A continuación se entregan imágenes de las visualizaciones 3D del render de la PCB



La PCB considera la integración de una interfaz de usuario implementada por medio de un rotary switch y una pantalla OLED con el objetivo de visualizar el valor actual de voltaje de salida.

### Archivos de fabricación
Los archivos de fabricación se encuentran disponibles en formato ZIP y en el siguiente directorio
### BOM de PCB
La lista de los componentes se encuentra disponible en el siguiente BOM, como referencia se consideran de LCSC.
### Lista de materiales
PCB electroforesis powesupply iowlabs
2x Conectores banana hembra de panel
2x Cables banana
Switch onoff
Rotary encoder para interfaz
Pantalla OLED
1x Case superior
1x Case inferior.
Fuente 12V y al menos 1A (12W)
### Firmware


## Instrucciones de ensamblado





## Licencias

Licencia de hardware :
Licencia de software y firmware:
Licencia de modelos 3D:
Licencia de documentación:
