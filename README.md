# `findr`

`findr` is a blazing-fast command-line tool to recursively search for files and directories whose names contain a given string, starting from the current working directory.

---

## 🚀 Features

- 🔍 Recursively scans all subdirectories.
- 🔠 Case-insensitive name matching.
- 🧱 Cross-platform: works on Linux, Windows, and macOS.
- ⚡ Optimized for speed (C++17, `std::filesystem`, `-O3`, `-march=native`).
- 🛑 Skips inaccessible folders (no crash on permission denied).

---

## 📦 Build Instructions

### Prerequisites

- CMake ≥ 3.10
- A C++17-compatible compiler (GCC, Clang, MSVC)

### Build (Release)

```bash
git clone https://github.com/yourname/findr.git
cd findr
cmake -DCMAKE_BUILD_TYPE=Release -B build
cmake --build build
```

The binary will be available at `build/findr`.

---

## 🧪 Usage

```bash
./findr <search_term>
```

### Example

```bash
./findr main.cpp
```

Output:

```sh
Searching for: main.cpp

Found 1 match(es):

/home/user/projects/findr/src/main.cpp
```

---

## 📝 Notes

- The search term is **case-insensitive**.
- The tool prints only paths that **contain** the search term in their name or full path.
- If you pass multiple words, they are treated as a single space-separated string (e.g., `"My File"`).

---

## 📁 Project Structure

```sh
.
├── CMakeLists.txt
├── src/
│   └── main.cpp
└── README.md
```

---

## 🛠 Future Improvements

- Option for case-sensitive search
- Regex support
- Output formatting (JSON, plain, etc.)
- File content search (like `grep`)

---

## 🧑‍💻 License

MIT License — free for personal and commercial use.