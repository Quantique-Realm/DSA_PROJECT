# Huffman File Compression and Decompression Web Application

A lightweight and efficient tool for **lossless data compression** and **decompression** using the Huffman Encoding algorithm, with a user-friendly web interface powered by Flask.

---

### Features

- **Lossless Compression**: Compresses files without losing any data, reducing storage space.
- **Fast Decompression**: Recovers original data from compressed files with high accuracy.
- **User-Friendly Interface**: Upload, compress, decompress, and download files easily via a Flask web app.
- **Efficient Implementation**: Powered by a priority queue-based Huffman Tree for optimal performance.
- **Multi-File Support**: Compatible with text files and other formats.

---

### Technologies Used

- **C++**: Core implementation of Huffman Compression and Decompression.
- **Flask (Python)**: Web interface for user interactions.
- **HTML/CSS**: Frontend for the web app.

---

## 📂 Project Structure

```
.
├── app.py                       
├── huffman_compressor.cpp       
├── templates/
│   └── index.html             
├── uploads/                     
├── compressed_files/            
└── README.md                     
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
![WhatsApp Image 2024-11-20 at 23 33 57_db52ff9d](https://github.com/user-attachments/assets/87d99515-725c-4f75-8c2f-a76546579675)

### File Upload
![WhatsApp Image 2024-11-20 at 23 47 39_144ce02f](https://github.com/user-attachments/assets/d6464c95-db48-469b-a6b2-bee70c96700c)

### Compression Results
![WhatsApp Image 2024-11-20 at 23 36 31_f2ef9331](https://github.com/user-attachments/assets/7f1aa1f9-ae9f-474c-8b5a-bd4d09272b1a)

### Decompression Results
https://github.com/Quantique-Realm/DSA_PROJECT/issues/3#issue-2676762655

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
