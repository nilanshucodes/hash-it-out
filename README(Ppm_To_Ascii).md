# PPM to ASCII Art Converter

## Overview

This program reads a **PPM (Portable Pixmap) image file** and converts it into an **ASCII art representation** using a predefined set of characters. It processes the image by reading pixel data, converting RGB values to grayscale, and mapping them to ASCII characters based on brightness levels.

## How It Works

### 1. Checking Command-Line Arguments

```cpp
if(argc < 2) {
    cout << "Please pass the PPM image as argument." << endl;
    return 1;
}
```

- Ensures the user provides a PPM file as an argument.
- If not provided, prints an error message and exits.

### 2. Declaring the Density String

```cpp
string density = "#N@%W$9876543210X&?ABC/()!;:^*+=~-_,.";
```

- Defines a **character scale** from darkest (`#`) to lightest (`.`) for ASCII mapping.

### 3. Opening the Image File

```cpp
ifstream image;
image.open(argv[1]);
```

- Opens the file specified in the command-line argument.

### 4. Reading PPM Header

```cpp
string type = "", width = "", height = "", RGB = "";
image >> type >> width >> height >> RGB;
```

- Extracts:
  - `type`: PPM file format (e.g., `P3`)
  - `width`: Image width
  - `height`: Image height
  - `RGB`: Maximum RGB value (usually `255`)

### 5. Converting Width & Height to Integers

```cpp
int w = 0, h = 0;
stringstream widthstream(width);
widthstream >> w;
stringstream heightstream(height);
heightstream >> h;
```

- Converts width and height from **strings to integers**.

### 6. Checking Image Size

```cpp
if(w > 200 || h > 200) {
    cout << "Image too big (max supported size 200x200)" << endl;
    return 2;
}
```

- Ensures the image is not **larger than 200x200**.

### 7. Reading Pixel Data

```cpp
string red = "", green = "", blue = "";
int r = 0, g = 0, b = 0;
int avg = 0, index = 0, newLine = 0;
```

- Declares variables for **RGB values** and **grayscale conversion**.

### 8. Processing Each Pixel

```cpp
while(!image.eof()) {
    image >> red >> green >> blue;
```

- Reads **three values** (R, G, B) from the file **until EOF**.

### 9. Converting RGB to Integers

```cpp
stringstream redstream(red);
stringstream greenstream(green);
stringstream bluestream(blue);
redstream >> r;
greenstream >> g;
bluestream >> b;
```

- Converts **RGB values from strings to integers**.

### 10. Calculating Grayscale Value

```cpp
avg = (r + g + b) / 3;
```

- Computes the **average brightness** of the pixel.

### 11. Mapping Grayscale to ASCII

```cpp
index = floor(avg / (255 / density.size()));
if(index >= density.size()) {
    index = density.size() - 1;
}
```

- Determines the **density character index**.
- Ensures **index does not exceed string length**.

### 12. Printing ASCII Character

```cpp
cout << density.at(index);
```

- Prints the **corresponding ASCII character**.

### 13. Handling Newlines

```cpp
++newLine;
if(newLine == w) {
    cout << endl;
    newLine = 0;
}
```

- Ensures proper **image formatting** by breaking lines after `w` characters.

### 14. Program Ends

```cpp
return 0;
```

- **Indicates successful execution**.

## Summary

This program:

1. **Opens a PPM file** (`P3` format expected).
2. **Reads image metadata** (width, height, RGB max value).
3. **Processes each pixel**:
   - Reads **RGB values**.
   - Converts **RGB → Grayscale**.
   - Maps **Grayscale → ASCII**.
   - Prints ASCII characters while maintaining structure.
4. **Ensures proper formatting** (newlines after every `w` pixels).

## Usage

Compile and run the program using:

```sh
g++ ppm_to_ascii.cpp -o ppm_to_ascii
./ppm_to_ascii image.ppm
```

Replace `image.ppm` with the actual PPM file path.

## Example Output

Given a PPM image, the program produces an ASCII representation like:

```
@@@@@@######*****....
@@@@@######******....
```

