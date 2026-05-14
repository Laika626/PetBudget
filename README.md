# PetBudget

PetBudget es un sistema orientado a objetos, desarrollado en C++ para ayudar a los dueños de perros y gatos a planear sus gastos veterinarios basicos mensuales. El programa calcual cuánto dinero necesitan para cubrir gastos los gastos fijos y los gastos anuales de sus mascotass. 
---
## Objetivo del proyecto

Desarrollar un planificador financiero para la tenencia responsable de mascotas, que tome en cuenta el protocolo oficial de vacunacion y desparasitación, y permita al usuario registrar gastos adicionales personalizados por mascotas. 
---
## Descripcion general del sistema

Flujo dle el programa:
- El registro de perros y/o gatos con sus datos personales y padecimientos (si aplica).
- Carga automatica del protocolo oficial de vacunación y desparacitación segun la especie, etapa de vida y, en el caso de gatos el resutado de Leucemia Felina.
- Registro manual de medicamento y gastos adicionales especificos de cada mascota.
- Calculo del presupuesto mensual total, separando gastos fijos mensuales y ahorro mensual para gastos anuales.
---
## Clases

| Clase | Descripción |
|-------|-------------|
| `Mascota` | Clase base: nombre, edad, padecimientos |
| `Perro` | Hereda de Mascota; aplica esquema de vacunación canino según edad |
| `Gato` | Hereda de Mascota; considera resultado de test de leucemia felina |
| `Vacuna` | Nombre, precio, frecuencia (mensual/anual); precargadas por especie |
| `Gasto` | Medicamentos y gastos adicionales registrados manualmente por el usuario |
| `Presupuesto` | Suma todos los gastos y calcula el monto mensual a apartar |
---
## Referencias a revizar para cargar protocolos de desparasitación y vacunación
- BBVA México. (2024). *Guía práctica para saber cuánto cuesta tener un perro*. https://www.bbva.mx/educacion-financiera/banca-digital/cuenta-digital-cuanto-cuesta-tener-perro.html
- Cronista México. (2025). *Llega SimiPet Care: estos son los costos de los servicios para perros y gatos*. https://www.cronista.com/mexico/actualidad-mx/llega-simipet-care-estos-son-los-costos-de-las-consultas-vacunas-y-otros-servicios-para-perros-y-gatos/
- Hills Pet México. (s.f.). *Todo sobre las vacunas para gatos*. https://www.hillspet.com.mx/cat-care/routine-care/vaccinating-your-kitten
- Tala México. (2023). *¿Cuánto cuesta tener un michi?* https://talamobile.mx/2023/03/21/blog-cuanto-cuesta-tener-un-michi/
- WSAVA Vaccination Guidelines Group. (2022). *WSAVA Guidelines for the Vaccination of Dogs and Cats*. https://wsava.org/global-guidelines/vaccination-guidelines/
