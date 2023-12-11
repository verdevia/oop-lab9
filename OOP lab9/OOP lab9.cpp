#include <iostream>

class GeometricFigure {
public:
    GeometricFigure(double x, double y, double rotationAngle, double scaleFactor)
        : centerX(x), centerY(y), rotationAngle(rotationAngle), scaleFactor(scaleFactor) {}

    virtual void draw() const = 0;
    void hide() {
        std::cout << "Figure is now hidden.\n";
    }

    void rotate(double angle) {
        rotationAngle += angle;
        std::cout << "Figure is rotated by " << angle << " degrees.\n";
    }

    void translate(double deltaX, double deltaY) {
        centerX += deltaX;
        centerY += deltaY;
        std::cout << "Figure is translated by vector (" << deltaX << ", " << deltaY << ").\n";
    }

    // Метод введення даних фігури
    virtual void input() {
        std::cout << "Enter center coordinates (x y): ";
        std::cin >> centerX >> centerY;
        std::cout << "Enter rotation angle (degrees): ";
        std::cin >> rotationAngle;
        std::cout << "Enter scale factor: ";
        std::cin >> scaleFactor;
    }

protected:
    double centerX;
    double centerY;
    double rotationAngle;
    double scaleFactor;
};

class Rectangle : public GeometricFigure {
public:
    Rectangle(double x, double y, double width, double height, double rotationAngle, double scaleFactor)
        : GeometricFigure(x, y, rotationAngle, scaleFactor), width(width), height(height) {}

    void draw() const override {
        std::cout << "Drawing a rectangle at (" << centerX << ", " << centerY << ") "
            << "with width " << width << " and height " << height << ".\n";
    }

    // Метод введення даних прямокутника
    void input() override {
        GeometricFigure::input(); // Викликати метод базового класу для введення загальних даних
        std::cout << "Enter rectangle width: ";
        std::cin >> width;
        std::cout << "Enter rectangle height: ";
        std::cin >> height;
    }

private:
    double width;
    double height;
};

// Функція для виведення меню та обробки вибору користувача
void showMenu(GeometricFigure& figure) {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Draw the figure\n";
        std::cout << "2. Rotate the figure\n";
        std::cout << "3. Translate the figure\n";
        std::cout << "4. Hide the figure\n";
        std::cout << "5. Input figure data\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            figure.draw();
            break;
        case 2:
            double angle;
            std::cout << "Enter rotation angle (degrees): ";
            std::cin >> angle;
            figure.rotate(angle);
            break;
        case 3:
            double deltaX, deltaY;
            std::cout << "Enter translation vector (deltaX deltaY): ";
            std::cin >> deltaX >> deltaY;
            figure.translate(deltaX, deltaY);
            break;
        case 4:
            figure.hide();
            break;
        case 5:
            figure.input();
            break;
        case 0:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
}

int main() {
    // Створення об'єкта класу Rectangle
    Rectangle myRectangle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    // Виклик меню для управління об'єктом
    showMenu(myRectangle);

    return 0;
}
