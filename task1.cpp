#include <iostream>
#include <vector>

using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

// Function to initialize the canvas
void initializeCanvas(vector<vector<char>>& canvas) {
    canvas.clear();
    canvas.resize(HEIGHT, vector<char>(WIDTH, ' '));
}

// Function to display the canvas
void displayCanvas(const vector<vector<char>>& canvas) {
    for (const auto& row : canvas) {
        for (char pixel : row) {
            cout << pixel;
        }
        cout << endl;
    }
}

// Function to draw a rectangle on the canvas
void drawRectangle(vector<vector<char>>& canvas, int x, int y, int width, int height, char symbol) {
    for (int i = y; i < y + height; ++i) {
        for (int j = x; j < x + width; ++j) {
            canvas[i][j] = symbol;
        }
    }
}

// Function to draw a line on the canvas using Bresenham's line algorithm
void drawLine(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2, char symbol) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        canvas[y1][x1] = symbol;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    vector<vector<char>> canvas;
    initializeCanvas(canvas);

    char choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Draw Rectangle" << endl;
        cout << "2. Draw Line" << endl;
        cout << "3. Display Canvas" << endl;
        cout << "4. Clear Canvas" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int x, y, width, height;
                char symbol;
                cout << "Enter position (x y): ";
                cin >> x >> y;
                cout << "Enter width and height: ";
                cin >> width >> height;
                cout << "Enter symbol to draw: ";
                cin >> symbol;
                drawRectangle(canvas, x, y, width, height, symbol);
                break;
            }
            case '2': {
                int x1, y1, x2, y2;
                char symbol;
                cout << "Enter start point (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter end point (x2 y2): ";
                cin >> x2 >> y2;
                cout << "Enter symbol to draw: ";
                cin >> symbol;
                drawLine(canvas, x1, y1, x2, y2, symbol);
                break;
            }
            case '3':
                displayCanvas(canvas);
                break;
            case '4':
                initializeCanvas(canvas);
                break;
            case '5':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '5');

    return 0;
}
