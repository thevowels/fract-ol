# Fract-ol

A graphics programming project from the 42 Common Core curriculum that demonstrates the fundamentals of computer graphics using the MLX42 library.

## Description

This project is an introduction to graphics programming, showcasing how to:
- Create and manage windows using MLX42
- Handle images and pixel manipulation
- Implement event hooks and loops
- Work with external graphics libraries

## Features

- **Window Management**: Creates a 720x480 pixel window with customizable title
- **Image Rendering**: Demonstrates basic image creation and display
- **Pixel Manipulation**: Shows how to modify individual pixels in real-time
- **Event Handling**: Implements hooks to monitor window state changes
- **Real-time Updates**: Uses MLX42's loop system for continuous rendering

## Dependencies

The project relies on several external libraries:
- **MLX42**: The main graphics library (included in `lib/MLX42/`)
- **GLFW**: For window and input management
- **OpenGL**: For graphics rendering
- **pthread**: For threading support
- **libdl**: For dynamic linking
- **libm**: Math library

## Building

### Prerequisites
Make sure you have the following installed:
- GCC compiler
- CMake
- GLFW development libraries
- OpenGL development libraries

### Compilation
```bash
# Build the project
make

# Clean object files
make clean

# Full clean (removes executable)
make fclean

# Rebuild everything
make re
```

The build process will:
1. Automatically compile the MLX42 library using CMake
2. Compile the source files with optimization flags
3. Link all dependencies to create the final executable

### Build Configuration
- **Compiler Flags**: `-Wextra -Wall -Werror -Wunreachable-code -Ofast`
- **Output**: Executable named `Game`
- **Optimization**: Built with `-Ofast` for maximum performance

## Usage

Run the program:
```bash
./Game
```

The application will:
- Open a window titled "Windows Title"
- Display a 256x256 image
- Show a red pixel at position (0,0)
- Print window dimensions to the console continuously

## Project Structure

```
fract-ol/
├── src/main.c          # Main program logic
├── lib/MLX42/          # MLX42 graphics library
├── Makefile            # Build configuration
└── README.md           # This file
```

## Learning Objectives

This project teaches:
- **Graphics Programming Basics**: Understanding how pixels and images work
- **Event-Driven Programming**: Using hooks and callbacks
- **Library Integration**: Working with external C libraries
- **Build Systems**: Using Makefiles and CMake
- **Memory Management**: Proper initialization and cleanup of graphics resources

## 42 School Project

This is part of the 42 Common Core curriculum, focusing on:
- Low-level graphics programming
- Understanding of computer graphics fundamentals
- Working with complex external libraries
- System programming concepts
