# LeetCode Solutions

A learning repository for mastering algorithms through multiple programming languages, with a focus on converting C++ solutions to Go and Rust.

## 🎯 Purpose

This repository is designed as a systematic approach to learning Go and Rust by implementing the same LeetCode problems across three languages:
- **C++** - Base implementations (reference solutions)
- **Go** - Learning functional programming patterns and Go idioms
- **Rust** - Learning memory safety, ownership, and systems programming concepts

## 📁 Repository Structure

```
leetcode-algo/
├── problem-name/
│   ├── cpp/
│   │   └── main.cpp          # C++ reference solution
│   ├── golang/
│   │   └── main.go           # Go implementation
│   └── rust/
│       ├── Cargo.toml        # Rust project configuration
│       └── src/
│           └── main.rs       # Rust implementation
├── .gitignore
├── LICENSE
└── README.md
```

## 🔄 Learning Methodology

1. **Start with C++** - Implement the algorithm in C++ as a reference
2. **Convert to Go** - Focus on Go idioms, slices, maps, and concurrency patterns
3. **Convert to Rust** - Learn ownership, borrowing, memory safety, and zero-cost abstractions

## 🛠 Development Setup

### Prerequisites
- **C++**: GCC or Clang compiler
- **Go**: Go 1.19+ 
- **Rust**: Rust 1.70+ (install via [rustup](https://rustup.rs/))

### Running Solutions

#### C++
```bash
cd problem-name/cpp
g++ -o main main.cpp
./main
```

#### Go
```bash
cd problem-name/golang
go run main.go
```

#### Rust
```bash
cd problem-name/rust
cargo run
```

## 📄 License

MIT License - see [LICENSE](./LICENSE) file for details.

## 🎓 Learning Resources

- [LeetCode](https://leetcode.com/) - Problem source
- [Go Tour](https://tour.golang.org/) - Interactive Go tutorial
- [Rust Book](https://doc.rust-lang.org/book/) - The official Rust programming language book
- [Go by Example](https://gobyexample.com/) - Hands-on Go examples
- [Rust by Example](https://doc.rust-lang.org/rust-by-example/) - Learn Rust with examples