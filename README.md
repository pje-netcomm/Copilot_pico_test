# Raspberry Pi Pico Blink

A simple LED blink example for the Raspberry Pi Pico microcontroller, demonstrating basic GPIO control and USB serial debugging.

## Features

- Configurable LED pin (supports both Pico and Pico W)
- Adjustable blink timing via compile-time defines
- USB serial output for debugging
- Clean, well-documented code

## Hardware Requirements

- Raspberry Pi Pico or Pico W board
- USB cable for programming and power
- (Optional) External LED and resistor if not using onboard LED

## Software Prerequisites

### Windows
- [CMake](https://cmake.org/download/) (version 3.13 or later)
- [ARM GCC Compiler](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/) or MinGW
- [Python 3](https://www.python.org/downloads/) (required by Pico SDK)

### Linux/macOS
```bash
# Ubuntu/Debian
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential

# macOS
brew install cmake
brew tap ArmMbed/homebrew-formulae
brew install arm-none-eabi-gcc
```

## Building

### 1. Set up Pico SDK

**Option A: Set environment variable (recommended)**
```bash
# Windows (PowerShell)
$env:PICO_SDK_PATH = "C:\path\to\pico-sdk"

# Linux/macOS
export PICO_SDK_PATH=/path/to/pico-sdk
```

**Option B: Let CMake download it automatically**
```bash
# Windows (PowerShell)
$env:PICO_SDK_FETCH_FROM_GIT = "ON"

# Linux/macOS
export PICO_SDK_FETCH_FROM_GIT=ON
```

### 2. Build the project

```bash
# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
cmake --build .
```

The output files will be in the `build` directory:
- `blink.uf2` - Main firmware file for drag-and-drop programming
- `blink.elf` - ELF binary
- `blink.hex` - Intel HEX format
- `blink.bin` - Raw binary

## Flashing

1. Hold down the BOOTSEL button on your Pico
2. Connect the Pico to your computer via USB
3. Release the BOOTSEL button - the Pico will appear as a USB mass storage device
4. Copy `build/blink.uf2` to the Pico drive
5. The Pico will automatically reboot and start running your program

## Configuration

You can customize the behavior by defining compile-time options in CMakeLists.txt:

```cmake
# Custom LED pin (default: 25 for Pico, use 0 for external LED)
target_compile_definitions(blink PRIVATE LED_PIN=0)

# Custom blink timing (in milliseconds)
target_compile_definitions(blink PRIVATE 
    BLINK_ON_TIME=250
    BLINK_OFF_TIME=250
)
```

## Debugging

The project is configured to output debug information via USB serial. To view the output:

### Windows
- Use a serial terminal like [PuTTY](https://www.putty.org/) or [Tera Term](https://ttssh2.osdn.jp/index.html.en)
- Connect to the COM port assigned to your Pico (check Device Manager)
- Baud rate: 115200

### Linux
```bash
# Find the device (usually /dev/ttyACM0)
ls /dev/ttyACM*

# Connect with screen or minicom
screen /dev/ttyACM0 115200
# or
minicom -D /dev/ttyACM0 -b 115200
```

### macOS
```bash
# Find the device
ls /dev/tty.usbmodem*

# Connect with screen
screen /dev/tty.usbmodem* 115200
```

## Board Support

### Raspberry Pi Pico
- Uses GPIO 25 (onboard LED)
- Works out of the box

### Raspberry Pi Pico W
- Onboard LED is connected to the wireless chip, not a GPIO pin
- For basic GPIO testing, connect an external LED to GPIO 0 with appropriate resistor
- To use the onboard LED on Pico W, additional cyw43 driver support is needed

## Troubleshooting

**Build fails with "PICO_SDK_PATH not found"**
- Ensure PICO_SDK_PATH environment variable is set correctly
- Or enable PICO_SDK_FETCH_FROM_GIT to download automatically

**LED doesn't blink**
- Verify you're using the correct LED_PIN for your board
- Check USB power connection
- Try viewing serial output to confirm the program is running

**No serial output**
- Wait 2-3 seconds after connecting for USB to enumerate
- Verify correct COM port / device
- Check terminal baud rate is set to 115200

## License

MIT License - see LICENSE file for details

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Resources

- [Raspberry Pi Pico Documentation](https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html)
- [Pico SDK Documentation](https://raspberrypi.github.io/pico-sdk-doxygen/)
- [Getting Started Guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
