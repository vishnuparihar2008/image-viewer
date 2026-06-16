# 🚀 Image Viewer in C
A lightweight, terminal-driven image viewer written in C using the **SDL2** graphics library. It reads a **PPM (P6 binary)** image from `stdin` and renders it pixel-by-pixel in a native desktop window.

---

## ✨ Features

- Renders PPM (P6 binary format) images using SDL2.
- Pixel-accurate rendering via `SDL_FillRect`.
- Reads directly from `stdin`, i.e., no file path argument needed.
- Auto-sizes the window to match the image dimensions.
- Minimal and dependency-light, just C standard library + SDL2.

---

## 🛠 Tech Stack
* **Language:** C and its Libraries
* **Tools:** GCC, Neovim, Git, GIMP (To convert files into .ppm format)

## 📚 Dependencies
| Library | Purpose |
|---|---|
| `SDL2` | Window creation and pixel rendering |
| `stdio.h` | Standard I/O for reading PPM from stdin |
| `stdlib.h` | Memory allocation (`calloc`, `free`) |

---

## 📁 Project Structure

```
image-viewer/
├── main.c        # Source code
├── images/
    ├── image.ppm     # Sample PPM image (Converted using GIMP)
    └── image.webp    # Original WebP source image
```

---

## 🚀 Getting Started
To get a copy of this project up and running on their local machine:

### Prerequisites
Make sure you have the following installed:

- **GCC** (or any C compiler)
- **SDL2** development libraries

### Installation

- Clone the repository:
```bash
  git clone https://github.com/vishnuparihar2008/image-viewer.git
```

- Navigate into the project directory:
```bash
  cd ./image-viewer
```

- Compile the project:
```bash
gcc -Wall -Wextra -g -o main main.c `sdl2-config --cflags --libs`
```
This compiles `main.c` and links the SDL2 library automatically.

> [!NOTE]  
> sdl2-config is standard for only Unix-like systems and might not compile on Windows etc.

- Run the project:
```bash
cat images/image.ppm | ./main 
```

> [!NOTE]  
> cat is standard for only Unix-like systems and might not run on Windows etc.

This runs the viewer by piping a PPM image to the binary<br>
A window will open at the image's native dimensions. Close it by clicking the **X** button or pressing **Alt+F4**.

---

### 📄 Expected PPM File Format (P6)
**Binary (Raw)**
```text
P6
# Optional comment
<width> <height>
255
<binary RGB pixel data...>
```

---

## ⚙️ How It Works

1. **Header Parsing** — Reads the PPM header from `stdin` using `fgets` to extract image width and height.
2. **Window Creation** — Creates an SDL2 window sized to the image dimensions.
3. **Pixel Rendering** — Reads raw RGB bytes pixel-by-pixel using `getchar()` and fills each 1×1 rectangle on the SDL surface.
4. **Display & Event Loop** — Calls `SDL_UpdateWindowSurface()` to show the final image and polls for an `SDL_QUIT` event to exit.

---

## 💡 Usage Examples
![ The first photo ever taken of a giant squid in its habitat, 2004 ](https://github.com/vishnuparihar2008/image-viewer/util/ss.png)

---

## 🗺 Roadmap / Future Enhancements
- [ ] Scale it up to preview more than just .ppm files.
- [ ] Add a full-scrreen option.
- [ ] Implement basic pixel manipulation like:
  - [ ] grayscale conversion
  - [ ] brightness adjustment

---

## 👩‍💻 Author

**Vishnu Parihar** — [vishnuparihar2008](https://github.com/vishnuparihar2008)

---

## 📄 License

This project is open source. Feel free to use, modify, and distribute.
