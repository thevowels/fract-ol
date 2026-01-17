# Fract-ol

A fractal visualization program using MLX42 graphics library (Work in Progress).

## Current Status

This project is in early development. Currently implements basic MLX42 library integration and pixel manipulation.

## Installation

```bash
# Build the project
make

# Run the program
./Game
```

## What's Implemented

- Basic MLX42 window creation (720x480)
- Pixel drawing functionality
- Simple red square rendering

## Testing & Development Log

### Current Commit: Basic MLX42 Setup
**Tests Performed**:
- ✅ MLX42 library compilation and linking
- ✅ Window creation with title "MLX42"
- ✅ Image creation and pixel manipulation
- ✅ Red square rendering (200x200 pixels at position 100,100)
- ✅ Proper MLX42 initialization and cleanup
- ✅ Memory management (no leaks detected)

**Technical Details**:
- Using `mlx_init()` for window setup
- Creating image buffer with `mlx_new_image()`
- Drawing pixels with `mlx_put_pixel()` in nested loops
- RGBA color format: `0xFF0000FF` (red with full alpha)
- Proper termination with `mlx_terminate()`

**Current Code Structure**:
- `get_rgba()`: Helper function for color composition
- Main loop: Basic MLX42 setup → image creation → pixel drawing → display

**Next Steps**:
- Implement fractal mathematical functions
- Add command line argument parsing
- Create fractal rendering algorithms

---

*Update this section with each commit to document your testing process*


