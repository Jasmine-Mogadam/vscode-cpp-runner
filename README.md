# C++ Runner Workspace

This workspace is configured for C++ development in Visual Studio Code, using `make` as the build system.

## Project Structure

- **`include/`**: Contains header files (`.hpp`). This is where you define your classes and function prototypes.
- **`src/`**: Contains source files (`.cpp`). This is where you implement the logic defined in the headers.
- **`obj/`**: (Generated) Contains compiled object files (`.o`). This helps speed up compilation by only rebuilding changed files.
- **`app`**: (Generated) The final executable binary.

## VS Code Configuration (`.vscode/`)

- **`extensions.json`**: Recommends the "C++ Extension Pack" for IntelliSense, debugging, and code navigation.
- **`tasks.json`**: Defines the build task. It tells VS Code to run the `make` command when you trigger a build.
- **`launch.json`**: Configures the debugger (LLDB) to run and debug the `app` executable.

## How to Compile & Run

### In the UI (VS Code)

1.  **Build**: Press `Cmd + Shift + B` (macOS) or `Ctrl + Shift + B` (Windows/Linux) to compile the project.
2.  **Run/Debug**: Press `F5` to start debugging. This will automatically build the project first if there are changes.

### In the Console

1.  **Build**:
    ```bash
    make
    ```
2.  **Run**:
    ```bash
    ./app
    ```
3.  **Clean Build Files**:
    ```bash
    make clean
    ```

## Makefile Explanation

The `Makefile` automates the compilation process:

- It tracks dependencies between `.cpp` and `.hpp` files.
- It uses `g++` with the C++17 standard and extra warnings enabled (`-Wall -Wextra`).
- It automatically creates the `obj/` directory if it doesn't exist.
- It links all object files together to create the final `app` executable.
