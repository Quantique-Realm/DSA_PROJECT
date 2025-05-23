import os
import subprocess
from flask import Flask, request, redirect, url_for, send_from_directory, render_template

app = Flask(__name__)
UPLOAD_FOLDER = 'uploads'
COMPRESSED_FOLDER = 'compressed_files'

os.makedirs(UPLOAD_FOLDER, exist_ok=True)
os.makedirs(COMPRESSED_FOLDER, exist_ok=True)

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.config['COMPRESSED_FOLDER'] = COMPRESSED_FOLDER

@app.route('/')
def index():
    return render_template('index.html', filename=None)

# Route for file upload and compression
@app.route('/upload_compress', methods=['POST'])
def upload_compress_file():
    if 'file' not in request.files:
        return 'No file part', 400
    file = request.files['file']
    if file.filename == '':
        return 'No selected file', 400
    if file:
        input_path = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
        file.save(input_path)

        output_filename = file.filename.split('.')[0] + '_compressed.bin'
        output_path = os.path.join(app.config['COMPRESSED_FOLDER'], output_filename)

        # Run the C++ Huffman compression program
        try:
            subprocess.run(['huffman_compressor.exe', 'compress', input_path, output_path], check=True)
        except Exception as e:
            return str(e), 500

        return render_template('index.html', compressed_filename=output_filename)

# Route for decompression
@app.route('/decompress', methods=['POST'])
def decompress_file():
    if 'file' not in request.files:
        return 'No file part', 400
    file = request.files['file']
    if file.filename == '':
        return 'No selected file', 400
    if file:
        compressed_path = os.path.join(app.config['COMPRESSED_FOLDER'], file.filename)
        decompressed_filename = file.filename.split('.')[0] + '_decompressed.txt'
        decompressed_path = os.path.join(app.config['UPLOAD_FOLDER'], decompressed_filename)

        # Run the C++ Huffman decompression program
        try:
            subprocess.run(['huffman_compressor.exe', 'decompress', compressed_path, decompressed_path], check=True)
        except Exception as e:
            return str(e), 500

        return render_template('index.html', decompressed_filename=decompressed_filename)

# Route to download the compressed file
@app.route('/download_compressed/<filename>')
def download_compressed_file(filename):
    return send_from_directory(app.config['COMPRESSED_FOLDER'], filename, as_attachment=True)

# Route to download the decompressed file
@app.route('/download_decompressed/<filename>')
def download_decompressed_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'], filename, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
