
# Fractol

![Fractol Screenshot](path/to/screenshot.png)

Fractol is a graphical application that renders various types of fractals such as the Mandelbrot set, Julia set, and the Burning Ship fractal. This project uses the MiniLibX library for graphical rendering.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features

- Render different types of fractals including Mandelbrot, Julia, and Burning Ship.
- Zoom in and out of the fractals.
- Adjust fractal parameters in real-time.
- Color customization.
- Control iteration levels.

## Installation

### Prerequisites

- Make sure you have `gcc` installed on your system.
- Install the MiniLibX library.

### Building the Project

1. Clone the repository:

    ```bash
    git clone https://github.com/yojablao/my_fractol.git
    cd my_fractol
    ```

2. Build the project using `make`:

    ```bash
    make
    ```

    This will compile the source code and generate the executable `fractol`.

## Usage

Run the application with one of the supported fractal types as an argument:

```bash
./fractol [fractal_type]
```

### Supported Fractal Types

- `mandelbrot`
![fractal_output (6)](https://github.com/yojablao/my_fractol/assets/111790283/2a988a1d-a095-4d36-a86e-634d0ac249c9)
![fractal_output (7)](https://github.com/yojablao/my_fractol/assets/111790283/bb8b3068-d8c7-4c3d-b588-10607821fd57)
![fractal_output (8)](https://github.com/yojablao/my_fractol/assets/111790283/b966c90e-06e1-42cd-9047-1cd83a828f80)
![fractal_output (9)](https://github.com/yojablao/my_fractol/assets/111790283/38499e4c-6a3f-4ab8-9663-786498f1dcd6)
![fractal_output (1)](https://github.com/yojablao/my_fractol/assets/111790283/6d033410-4673-4f56-929f-26db910b4c02)
![fractal_output](https://github.com/yojablao/my_fractol/assets/111790283/c4e6a538-664c-44cd-b608-bd5ab32a18a3)

- `julia`
![fractal_output (2)](https://github.com/yojablao/my_fractol/assets/111790283/f9de8b6d-b939-44dd-b18e-842e17d15c45)
![fractal_output (3)](https://github.com/yojablao/my_fractol/assets/111790283/2cd4cbe4-86d3-41a5-862e-ec5887a3e2fb)
![fractal_output (4)](https://github.com/yojablao/my_fractol/assets/111790283/bc985e7a-7440-4593-ad92-98fc2238d6a6)
![fractal_output (5)](https://github.com/yojablao/my_fractol/assets/111790283/08bdf245-fb38-41cf-bb30-b9740271b801)
- `burning_ship`

Example:

```bash
./fractol mandelbrot
```

## Controls

### General Controls

- **Mouse Scroll Up**: Zoom in.
- **Mouse Scroll Down**: Zoom out.
- **Arrow Keys**: Move the view left, right, up, and down.
- **C**: Change color scheme.
- **ESC**: Exit the application.

### Julia Fractal Specific Controls

- **Mouse Movement**: Change the parameters of the Julia set in real-time.

### Color Controls

- **1, 2, 3**: Switch between predefined color schemes.
- **R**: Reset to the default color scheme.

### Zoom Controls

- **+ (Plus)**: Zoom in.
- **- (Minus)**: Zoom out.

### Iteration Controls

- **I**: Increase the number of iterations for more detail.
- **P**: Decrease the number of iterations for less detail.

### Reset Controls

- **Spacebar**: Reset the view to the default position and zoom level.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [MiniLibX](https://github.com/qst0/ft_libgfx) - The lightweight graphics library used in this project.
- Inspiration from the 42 School curriculum.
```

<!-- #  Fractol

Fractol is a graphical application that renders various types of fractals such as the Mandelbrot set, Julia set, and the Burning Ship fractal. This project uses the MiniLibX library for graphical rendering.
![Fractol Screenshot](path/to/screenshot.png)

Fractol is a graphical application that renders various types of fractals such as the Mandelbrot set, Julia set, and the Burning Ship fractal. This project uses the MiniLibX library for graphical rendering.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features

- Render different types of fractals including Mandelbrot, Julia, and Burning Ship.
- Zoom in and out of the fractals.
- Adjust fractal parameters in real-time.
- Color customization.

## Installation

### Prerequisites

- Make sure you have \`gcc\` installed on your system.
- Install the MiniLibX library.

### Building the Project

1. Clone the repository:

\`\`\`bash
git clone https://github.com/yojablao/my_fractol.git
cd my_fractol
\`\`\`

2. Build the project using \`make\`:

\`\`\`bash
make
\`\`\`

This will compile the source code and generate the executable \`fractol\`.

## Usage

Run the application with one of the supported fractal types as an argument:

\`\`\`bash
./fractol [fractal_type]
\`\`\`

### Supported Fractal Types

- \`mandelbrot\`
![fractal_output (6)](https://github.com/yojablao/my_fractol/assets/111790283/2a988a1d-a095-4d36-a86e-634d0ac249c9)
![fractal_output (7)](https://github.com/yojablao/my_fractol/assets/111790283/bb8b3068-d8c7-4c3d-b588-10607821fd57)
![fractal_output (8)](https://github.com/yojablao/my_fractol/assets/111790283/b966c90e-06e1-42cd-9047-1cd83a828f80)
![fractal_output (9)](https://github.com/yojablao/my_fractol/assets/111790283/38499e4c-6a3f-4ab8-9663-786498f1dcd6)
![fractal_output (1)](https://github.com/yojablao/my_fractol/assets/111790283/6d033410-4673-4f56-929f-26db910b4c02)
![fractal_output](https://github.com/yojablao/my_fractol/assets/111790283/c4e6a538-664c-44cd-b608-bd5ab32a18a3)

- \`julia\`
![fractal_output (2)](https://github.com/yojablao/my_fractol/assets/111790283/f9de8b6d-b939-44dd-b18e-842e17d15c45)
![fractal_output (3)](https://github.com/yojablao/my_fractol/assets/111790283/2cd4cbe4-86d3-41a5-862e-ec5887a3e2fb)
![fractal_output (4)](https://github.com/yojablao/my_fractol/assets/111790283/bc985e7a-7440-4593-ad92-98fc2238d6a6)
![fractal_output (5)](https://github.com/yojablao/my_fractol/assets/111790283/08bdf245-fb38-41cf-bb30-b9740271b801)

- \`burning_ship\`

Example:

\`\`\`bash
./fractol mandelbrot
\`\`\`

## Controls

- **Mouse Scroll**: Zoom in and out.
- **Arrow Keys**: Move the view.
- **C**: Change color scheme.
- **ESC**: Exit the application.
- **space**: reset the zoom
- **R**: reset the fractol 
- **+**: Zoom in 
- **-**: Zoom out 
- **S**: take Screenshot
- **I**: more 
- **S**: take Screenshot

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [MiniLibX](https://github.com/qst0/ft_libgfx) - The lightweight graphics library used in this project.
- Inspiration from the 42 School curriculum.
" > README.md

# Add and commit the README.md
git add README.md
git commit -m "Add README.md"

# Add the remote repository if not already added
git remote add origin https://github.com/yojablao/my_fractol.git

# Push the changes
git push origin main

mandelbrot set -->
