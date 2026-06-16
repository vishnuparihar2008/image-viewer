# 🖼️ Image Viewer in C

A lightweight, terminal-driven image viewer written in C using the **SDL2** graphics library. It reads a **PPM (P6 binary)** image from `stdin` and renders it pixel-by-pixel in a native desktop window.

---

## 📸 Demo

```
./main < image.ppm
```

A window opens displaying the image at its native resolution. Close the window to exit.

---

## ✨ Features

- Renders PPM (P6 binary format) images using SDL2
- Pixel-accurate rendering via `SDL_FillRect`
- Reads directly from `stdin` — no file path argument needed
- Auto-sizes the window to match the image dimensions
- Minimal and dependency-light — just C standard library + SDL2

---

## 🛠️ Prerequisites

Make sure you have the following installed:

- **GCC** (or any C compiler)
- **SDL2** development libraries

### Install SDL2 on Ubuntu/Debian

```bash
sudo apt-get install libsdl2-dev
```

### Install SDL2 on macOS (Homebrew)

```bash
brew install sdl2
```

---

## 🔧 Building

```bash
gcc main.c -o main $(sdl2-config --cflags --libs)
```

This compiles `main.c` and links the SDL2 library automatically.

---

## 🚀 Usage

Run the viewer by piping a PPM image to the binary:

```bash
./main < image.ppm
```

The window will open at the image's native dimensions. Close it by clicking the **X** button or pressing **Alt+F4**.

---

## 🎨 Working with PPM Images

This viewer supports the **P6 (binary PPM)** format. Most images can be converted to PPM using common tools.

### Convert using ImageMagick

```bash
# WebP / PNG / JPG → PPM
convert input.webp output.ppm
convert input.png output.ppm
convert input.jpg output.ppm
```

### Convert using FFmpeg

```bash
ffmpeg -i input.png output.ppm
```

### Expected PPM File Format (P6)

```
P6
# Optional comment
<width> <height>
255
<binary RGB pixel data...>
```

---

## 📁 Project Structure

```
image-viewer/
├── main.c        # Source code
├── main          # Compiled binary (Linux)
├── image.ppm     # Sample PPM image
└── image.webp    # Original WebP source image
```

---

## ⚙️ How It Works

1. **Header Parsing** — Reads the PPM header from `stdin` using `fgets` to extract image width and height.
2. **Window Creation** — Creates an SDL2 window sized to the image dimensions.
3. **Pixel Rendering** — Reads raw RGB bytes pixel-by-pixel using `getchar()` and fills each 1×1 rectangle on the SDL surface.
4. **Display & Event Loop** — Calls `SDL_UpdateWindowSurface()` to show the final image and polls for an `SDL_QUIT` event to exit.

---

## 📚 Dependencies

| Library | Purpose |
|---|---|
| `SDL2` | Window creation and pixel rendering |
| `stdio.h` | Standard I/O for reading PPM from stdin |
| `stdlib.h` | Memory allocation (`calloc`, `free`) |

---

## 👩‍💻 Author

**Aparna** — [vishnuparihar2008](https://github.com/vishnuparihar2008)

---

## 📄 License

This project is open source. Feel free to use, modify, and distribute.
