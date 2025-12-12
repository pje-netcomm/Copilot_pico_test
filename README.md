# Raspberry Pi Pico Blink

A simple LED blink example for the Raspberry Pi Pico microcontroller.

This isn't a serious project, just a test of Github co-pilot.

## Features

- Configurable LED pin (default: GPIO 25)
- Adjustable blink timing via compile-time defines
- Clean, minimal code

## Requirements

- Raspberry Pi Pico or Pico W board
- USB cable for programming and power
- [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

## Building

### Set up the Pico SDK

**Option 1:** Set environment variable
```bash
export PICO_SDK_PATH=/path/to/pico-sdk
```

**Option 2:** Let CMake download it automatically
```bash
export PICO_SDK_FETCH_FROM_GIT=ON
```

### Build the project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Output: `build/blink.uf2`

## Flashing

1. Hold down the BOOTSEL button on your Pico
2. Connect the Pico to your computer via USB
3. Release the BOOTSEL button
4. Copy `build/blink.uf2` to the Pico drive
5. The LED will start blinking

## Configuration

Customize behavior in CMakeLists.txt:

```cmake
# Custom LED pin (default: 25)
target_compile_definitions(blink PRIVATE LED_PIN=0)

# Custom blink timing (in milliseconds, default: 500)
target_compile_definitions(blink PRIVATE 
    BLINK_ON_TIME=250
    BLINK_OFF_TIME=250
)
```

## License

MIT License - see LICENSE file for details
