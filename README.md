# ⏱️ Timer Programable con Arduino + Teclado Matricial + LCD I2C

Proyecto de **timer digital programable** usando Arduino, un teclado matricial 4x4, un LCD 16x2 con interfaz I2C y un buzzer.

El tiempo se ingresa directamente en formato **MMSS**, se muestra en pantalla como **MM:SS** y al finalizar se emite una alerta sonora.

---

## 🧩 Características

- ⌨️ Ingreso de tiempo en formato **MMSS**
- 📟 Visualización en **LCD 16x2 I2C**
- ⌫ Tecla `*` para borrar el último dígito
- ▶️ Tecla `A` para iniciar el conteo
- 🔄 Tecla `C` para resetear
- 🔔 Buzzer al finalizar el tiempo
- 🧠 Código simple y comentado (Arduino nativo)

---

## 🛠️ Componentes necesarios

- Arduino Uno o Nano
- Teclado matricial 4x4
- LCD 16x2 con módulo I2C (PCF8574)
- Buzzer activo o pasivo
- Cables Dupont

---

## 🔌 Conexiones

### 📟 LCD I2C → Arduino

| LCD I2C | Arduino |
|-------|--------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

> ⚠️ Dirección I2C común: `0x27` o `0x3F`

---

### ⌨️ Teclado Matricial 4x4 → Arduino

| Teclado | Arduino |
|-------|--------|
| Fila 1 | 9 |
| Fila 2 | 8 |
| Fila 3 | 7 |
| Fila 4 | 6 |
| Col 1 | 5 |
| Col 2 | 4 |
| Col 3 | 3 |
| Col 4 | 2 |

---

### 🔔 Buzzer

| Buzzer | Arduino |
|------|--------|
| + | Pin 10 |
| - | GND |

---

## ⌨️ Mapa de teclas

1 2 3 A
4 5 6 B
7 8 9 C
* 0 # D


| Tecla | Función |
|----|--------|
| 0–9 | Ingresar tiempo (MMSS) |
| A | Iniciar timer |
| C | Resetear |
| * | Borrar último dígito |

---

## 🧠 Funcionamiento

1. Ingresar **4 dígitos** en formato `MMSS`
   - Ejemplo: `0130` → 01:30
2. El LCD muestra el tiempo formateado
3. Presionar `A` para iniciar
4. El tiempo corre en cuenta regresiva
5. Al llegar a `00:00` suena el buzzer

---

## 📦 Librerías necesarias

Instalar desde el **Administrador de Librerías de Arduino**:

- `Keypad`
- `LiquidCrystal I2C` (Frank de Brabander)

---

## 🚀 Posibles mejoras

- ⏸️ Pausa / Reanudar con tecla `B`
- ⏱️ Reemplazar `delay()` con `millis()`
- 💾 Guardar último tiempo en EEPROM
- ⚠️ Parpadeo en últimos segundos
- 🔊 Diferentes patrones de sonido

---

## 📜 Licencia

Este proyecto es de uso educativo y libre.  
Puedes modificarlo, mejorarlo y compartirlo sin problema.

---

## 🤝 Autor

Proyecto creado como ejercicio práctico con Arduino para aprendizaje de:
- Entradas digitales
- Manejo de LCD I2C
- Lógica de temporización
- Interacción con usuario

¡Disfrútalo! 😄🔧
