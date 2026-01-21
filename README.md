# Fract-ol

## Description

Fract-ol is a comprehensive fractal visualization program that renders mathematically beautiful and infinitely complex fractal sets in real-time. The project explores the fascinating world of fractals through interactive visualization, allowing users to explore the intricate patterns of the Mandelbrot set, Julia sets, and the organic beauty of the Barnsley Fern.

**Project Goal:** Create an interactive fractal explorer that demonstrates the mathematical beauty of complex dynamics while providing smooth navigation, zoom capabilities, and visual customization options.

**Key Features:**
- **Multiple Fractal Types:** Mandelbrot set, customizable Julia sets, and Barnsley Fern
- **Interactive Navigation:** Mouse-controlled zooming and keyboard panning
- **Dynamic Visualization:** Real-time color scheme switching and window resizing
- **Mathematical Precision:** Accurate complex plane calculations with smooth zoom accumulation
- **Advanced Rendering:** Both pixel-based and point-based algorithms for different fractal types

The program demonstrates advanced graphics programming concepts including event-driven architecture, coordinate space transformations, escape-time algorithms, and iterated function systems.

## Instructions

### Prerequisites
- Linux system with X11 support
- GCC compiler
- Make utility
- CMake (for MLX42 compilation)
- OpenGL development libraries

### Required System Libraries
Before compilation, ensure these libraries are installed on your system:

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential cmake
sudo apt-get install libglfw3-dev libgl1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```

**Fedora/CentOS/RHEL:**
```bash
sudo dnf install gcc make cmake
sudo dnf install glfw-devel mesa-libGL-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel
```

**Arch Linux:**
```bash
sudo pacman -S base-devel cmake
sudo pacman -S glfw-wayland mesa libxrandr libxinerama libxcursor libxi
```

**Note:** The makefile links against `-ldl -lglfw -pthread -lm` so these libraries must be available in your system's library path.

### Compilation
```bash
# Clone the repository
git clone https://github.com/thevowels/fract-ol.git
cd fract-ol

# Build the project (includes automatic MLX42 and libft compilation)
make

# Clean build artifacts
make clean

# Complete cleanup including libraries
make fclean

# Rebuild everything
make re
```

### Installation
No separate installation required. The program runs directly from the build directory.

### Execution
```bash
# Mandelbrot Set
./fractol M

# Julia Set with default parameters
./fractol J

# Julia Set with custom complex constants (real imaginary)
./fractol J -0.7 0.27015
./fractol J 0.285 0.01
./fractol J -0.8 0.156

# Barnsley Fern (point-based rendering)
./fractol K
```

### Controls
| Input | Action |
|-------|--------|
| **Mouse Scroll** | Zoom in/out at cursor position |
| **Arrow Keys** | Pan around the fractal (Up/Down/Left/Right) |
| **Spacebar** | Cycle through 5 different color schemes |
| **ESC** | Exit program |

### Usage Examples
```bash
# Explore the classic Mandelbrot set
./fractol M

# Create artistic Julia sets with different parameters
./fractol J -0.4 0.6     # Spiral patterns
./fractol J 0.285 0.01   # Dendrite fractal
./fractol J -0.8 0.156   # Lightning-like patterns

# Experience organic growth patterns
./fractol K              # Barnsley Fern simulation
```

## Technical Implementation

### Architecture
- **Modular Design:** Separate modules for fractals, rendering, events, and utilities
- **Function Pointers:** Dynamic algorithm selection for fractals and color schemes
- **Event-Driven:** MLX42 integration for real-time user interaction
- **Memory Safety:** Comprehensive error handling and resource cleanup

### Fractal Algorithms

#### Complex Number Representation
Since computers cannot directly compute with imaginary numbers (i), all complex number operations are broken down into their real and imaginary components:
- **Complex Number:** `Z = a + bi` where `i² = -1`
- **Real Component:** `z_re = a` (stored as double)
- **Imaginary Component:** `z_im = b` (stored as double)

#### Mandelbrot Set Implementation
**Mathematical Formula:** `Z_{n+1} = Z_n² + C`

**Algorithm Breakdown:**
```c
// Initial conditions for each pixel
z_re = 0.0;           // Z₀ = 0 + 0i
z_im = 0.0;
c_re = pixel_x_mapped_to_complex_plane;  // C = c_re + c_im*i
c_im = pixel_y_mapped_to_complex_plane;

// Iteration: Z² = (a + bi)² = a² - b² + 2abi
while (n < MAX_ITERATIONS) {
    if (z_re² + z_im² > 4.0)  // Escape condition: |Z| > 2
        break;
    
    tmp = 2 * z_re * z_im + c_im;           // New imaginary part
    z_re = z_re² - z_im² + c_re;            // New real part  
    z_im = tmp;                             // Update imaginary
    n++;
}
```

**Key Mathematical Concepts:**
- **Escape Radius:** Points where `|Z|² > 4` will diverge to infinity
- **Coordinate Mapping:** Screen pixels → Complex plane coordinates
- **Complex Squaring:** `(a + bi)² = (a² - b²) + (2ab)i`

#### Julia Set Implementation  
**Mathematical Formula:** `Z_{n+1} = Z_n² + C` (where C is constant)

**Algorithm Breakdown:**
```c
// C is fixed (user-provided constant)
c_re = user_constant_real;     // Fixed throughout
c_im = user_constant_imaginary;

// Z₀ varies with pixel position  
z_re = pixel_x_mapped_to_complex_plane;  // Initial Z varies per pixel
z_im = pixel_y_mapped_to_complex_plane;

// Same iteration as Mandelbrot
while (n < MAX_ITERATIONS) {
    if (z_re² + z_im² > 4.0)
        break;
    tmp = 2 * z_re * z_im + c_im;
    z_re = z_re² - z_im² + c_re; 
    z_im = tmp;
    n++;
}
```

**Difference from Mandelbrot:**
- **Mandelbrot:** C varies (pixel position), Z₀ = 0
- **Julia:** C is constant, Z₀ varies (pixel position)

#### Barnsley Fern (Iterated Function System)
**Mathematical Concept:** Probabilistic transformations using affine functions

**Transformation Functions:**
```c
// Function 1 (1% probability): Stem
f₁: x' = 0, y' = 0.16y

// Function 2 (85% probability): Main frond
f₂: x' = 0.85x + 0.04y, y' = -0.04x + 0.85y + 1.6

// Function 3 (7% probability): Left leaflet  
f₃: x' = 0.20x - 0.26y, y' = 0.23x + 0.22y + 1.6

// Function 4 (7% probability): Right leaflet
f₄: x' = -0.15x + 0.28y, y' = 0.26x + 0.24y + 0.44
```

**Algorithm Process:**
1. Start with random point
2. Apply one of four transformations based on probability
3. Plot resulting point
4. Repeat 1,000,000 times for statistical accuracy

#### Coordinate Space Transformations

**Screen to Complex Plane Mapping:**
```c
// Convert screen coordinates to mathematical coordinates
complex_real = min_r + (pixel_x / width) * (max_r - min_r);
complex_imag = max_i - (pixel_y / height) * (max_i - min_i);

// Default viewing window
min_r = -2.0, max_r = 2.0    // Real axis range
min_i = -2.0, max_i = 2.0    // Imaginary axis range
```

**Zoom Mathematics:**
```c
// Zoom factor calculation
new_range = current_range / zoom_factor;
// Center zoom on mouse position
new_min = mouse_complex_pos - (mouse_ratio * new_range);
new_max = new_min + new_range;
```

#### Escape-Time Coloring Algorithm
The number of iterations before escape determines pixel color:
- **Fast Escape (low n):** Often colored dark (outside set boundary)
- **Slow Escape (high n):** Colored bright (near set boundary) 
- **No Escape (n = MAX_ITERATIONS):** Usually black (inside set)

#### Mathematical Precision Considerations
- **Double Precision:** 64-bit floating point for coordinate accuracy
- **Iteration Limits:** MAX_ITERATIONS prevents infinite loops
- **Numerical Stability:** Escape condition `|Z|² > 4` ensures convergence detection
- **Coordinate Precision:** Higher zoom levels may hit floating-point limits

### Code Structure
```
src/
├── main.c          # Program entry and MLX42 initialization
├── fractals.c      # Mathematical fractal algorithms
├── actions.c       # Drawing and transformation functions
├── hooks.c         # Event handlers (mouse, keyboard, resize)
├── colors.c        # Color scheme implementations
├── parser.c        # Command-line argument validation
├── inits.c         # Structure initialization
└── utils.c         # Utility and helper functions
```

### Performance Features
- **Zoom Accumulation:** Smooth zooming with 0.3s event collection
- **Efficient Rendering:** Optimized pixel/point algorithms
- **Real-time Updates:** Immediate response to user interactions
- **Memory Optimization:** Smart image buffer management

## Resources

### Mathematical References
- **"The Fractal Geometry of Nature" by Benoit Mandelbrot** - Foundational text on fractal mathematics
- **"Chaos and Fractals: New Frontiers of Science" by Peitgen, Jürgens, and Saupe** - Comprehensive fractal theory
- **MIT OpenCourseWare: Complex Analysis** - Mathematical foundations for complex dynamics
- **Wolfram MathWorld: Fractal Encyclopedia** - Online reference for fractal properties and equations

### Technical Documentation
- **MLX42 Official Documentation** - Graphics library API reference
- **42 School MLX42 Guide** - School-specific implementation guidelines
- **OpenGL Programming Guide** - Graphics programming fundamentals
- **"Computer Graphics: Principles and Practice" by Foley et al.** - Comprehensive graphics theory

### Online Resources
- **Fractal Foundation** (fractalfoundation.org) - Educational fractal content
- **Paul Bourke's Fractal Pages** - Mathematical formulations and examples
- **Wikipedia: Mandelbrot Set & Julia Set** - Mathematical definitions and properties
- **Stack Overflow Fractal Programming** - Community solutions and optimizations

### Development Tools
- **GDB Debugger** - Code debugging and memory analysis
- **Valgrind** - Memory leak detection and profiling
- **Make Documentation** - Build system reference
- **Git Version Control** - Project management and collaboration

### AI Usage Declaration

**AI was utilized in the following aspects of this project:**

1. **Code Review and Optimization:**
   - AI assisted in reviewing fractal algorithm implementations for mathematical accuracy
   - Provided suggestions for performance optimizations in rendering loops
   - Helped identify potential memory leaks and edge cases

2. **Documentation Enhancement:**
   - AI helped structure and format this comprehensive README
   - Assisted in explaining complex mathematical concepts in accessible language
   - Provided suggestions for improving code comments and technical descriptions

3. **Mathematical Validation:**
   - AI verified the correctness of complex number arithmetic implementations
   - Helped validate coordinate transformation mathematics
   - Assisted in understanding fractal convergence properties

4. **Problem-Solving Support:**
   - AI provided guidance on MLX42 event handling best practices
   - Helped troubleshoot zoom accumulation algorithm implementation
   - Assisted in debugging color scheme switching mechanisms

**Note:** All core fractal algorithms, rendering implementations, and architectural decisions were designed and implemented independently. AI served as a supplementary tool for validation, optimization suggestions, and documentation enhancement rather than code generation.

### Learning Resources Used
- **42 School Curriculum** - Project specifications and learning objectives
- **Peer Code Reviews** - Collaborative learning and best practices
- **Mathematical Software Libraries** - Reference implementations for validation
- **Graphics Programming Communities** - Forums and discussion groups for advanced techniques


