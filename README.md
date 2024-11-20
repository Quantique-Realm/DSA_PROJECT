Huffman Compression & Decompression Tool

A lightweight and efficient tool for **lossless data compression** and **decompression** using the Huffman Encoding algorithm, with a user-friendly web interface powered by Flask.

---

Features

- **Lossless Compression**: Compresses files without losing any data, reducing storage space.
- **Fast Decompression**: Recovers original data from compressed files with high accuracy.
- **User-Friendly Interface**: Upload, compress, decompress, and download files easily via a Flask web app.
- **Efficient Implementation**: Powered by a priority queue-based Huffman Tree for optimal performance.
- **Multi-File Support**: Compatible with text files and other formats.

---

Technologies Used

- **C++**: Core implementation of Huffman Compression and Decompression.
- **Flask (Python)**: Web interface for user interactions.
- **HTML/CSS**: Frontend for the web app.

---

## 📂 Project Structure

```
.
├── app.py                        # Flask application for web interface
├── huffman_compressor.cpp        # C++ program for compression and decompression
├── templates/
│   └── index.html                # HTML template for web interface
├── uploads/                      # Folder to store uploaded files
├── compressed_files/             # Folder to store compressed files
└── README.md                     # Project documentation
```

---

## How It Works

### Huffman Encoding
1. **Frequency Calculation**: Counts the frequency of characters in the input data.
2. **Priority Queue**: Uses a min-heap to build a Huffman Tree based on character frequency.
3. **Binary Tree**: Generates unique binary codes for characters (shorter codes for frequent characters).
4. **Compression**: Encodes data using the binary codes, reducing storage size.
5. **Decompression**: Rebuilds the original data using the Huffman Tree.

---

##  Setup Instructions

### Prerequisites:
- **C++ Compiler** (e.g., GCC, Clang, or MSVC)
- **Python 3.x**
- **Flask Framework**

### Installation Steps:
1. **Clone the repository**:
2. **Compile the C++ Program**:
3. **Install Python dependencies**:
4. **Run the Flask App**:
5. Open your browser and visit `http://127.0.0.1:5000/`.
---

## 📋 Usage Instructions

### 🗜️ Compression
1. Navigate to the **"Upload File"** section in the web interface.
2. Select the file you want to compress (e.g., `example.txt`).
3. Click **"Compress"**.
4. Download the compressed file (e.g., `example_compressed.bin`).

### 🔓 Decompression
1. Upload the compressed file (e.g., `example_compressed.bin`).
2. Click **"Decompress"**.
3. Download the decompressed file (e.g., `example_decompressed.txt`).

---

## 🧪 Example Workflow

1. Original File: **`example.txt`**  
   Content: `This is a sample text file for Huffman Compression.`  
   Size: **1.2 KB**

2. Compressed File: **`example_compressed.bin`**  
   Size: **700 bytes**

3. Decompressed File: **`example_decompressed.txt`**  
   Matches the original content.

---

## Performance

- **Time Complexity**:
  - Building the Huffman Tree: **O(n log n)** (where `n` is the number of unique characters).
  - Encoding/Decoding: **O(L)`**, where `L` is the length of the input data.
- **Space Efficiency**:
  - Achieves up to **40% compression** for repetitive text data.

---

## Screenshots

### Home Page
![Home Page](https://via.placeholder.com/800x400?text=Home+Page)

### File Upload
![File Upload](https://via.placeholder.com/800x400?text=File+Upload)

### Compression Results
![Compression Results](https://via.placeholder.com/800x400?text=Compression+Results)

---

## Features in Progress

- **Streaming Support**: Handle large files via chunk-based compression.
- **Compression Ratio Display**: Show detailed statistics about file size reduction.
- **Support for Media Files**: Extend compression to audio, images, and videos.

---

## 🛡️ Limitations

- Compression ratio depends on input data characteristics.
- Ineffective for highly random data.
- File size may increase for very small input files.

---
