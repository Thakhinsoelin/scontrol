# SControl

SControl is a lightweight file versioning system that provides both a graphical interface and a command-line utility for tracking file changes.

---

# Build Instructions

This document outlines the requirements and steps to build the SControl project from source using CMake.

## Prerequisites

Ensure the following tools are installed on your system:

- C++23 compliant compiler (e.g., MSVC, GCC, or Clang)
- CMake (version 3.10 or higher)
- OpenGL development libraries(don't require on windows)

---

## Build Steps

### 1. Clone the Repository

```bash
git clone https://github.com/Thakhinsoelin/scontrol.git
cd scontrol
```

### 2. Create a Build Directory

It is recommended to perform an out-of-source build to keep the source tree clean.

```bash
mkdir build
cd build
```

### 3. Configure the Project

Run CMake to generate the build files for your environment.

```bash
cmake ..
```

### 4. Build the Project

Compile the source code using your system's default build tool.

```bash
cmake --build .
```

---

# Build Artifacts

Upon a successful build, the following executables will be generated in the output directory:

| Executable         | Description                               |
|--------------------|-------------------------------------------|
| `SControl.exe`     | The primary GUI application               |
| `cmdprogram.exe`   | The command-line interface tool           |

---

# Troubleshooting

## Missing Dependencies

If CMake fails to locate OpenGL or GLFW:

- Ensure your development environment is correctly configured.
- Verify that the `Dependencies/` folder is correctly populated.

## Linker Errors

If you encounter `LNK2019` errors:

1. Delete the `build/` directory.
2. Re-run the configuration steps.
3. Build the project again.

---