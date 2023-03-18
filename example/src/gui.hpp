struct Shape {
    int xa = 0;
    int ya = 0;
    int xb = 0;
    int yb = 0;
    int xc = 0;
    int yc = 0;
    float radius;
    int width = 0;
    int height = 0;
    Color color = {
        .r = 0,
        .g = 0,
        .b = 0,
        .a = 255
    };
    Color grad_color = {
        .r = 0,
        .g = 0,
        .b = 0,
        .a = 0
    };
    void rect(Color col) {
        DrawRectangle(xa + (xa * -0.5), ya + (ya * -0.5), width, height, col);
    };
    void lRect(Color col) {
        DrawRectangleLines(xa + (xa * -0.5), ya + (ya * -0.5), width, height, col);
    };
    void gRect(Color col, Color colb) {
        DrawRectangleGradientH(xa + (xa * -0.5), ya + (ya * -0.5), width, height, col, colb);
    };
    void line(Color col) {
        DrawLine(xa, ya, xb, yb, col);
    };
    void ellipse(Color col) {
        DrawCircle(xa, ya, radius, col);
    };
    void lEllipse(Color col) {
        DrawCircleLines(xa, ya, radius, col);
    };
    void gEllipse(Color col, Color colb) {
        DrawCircleGradient(xa, ya, radius, col, colb);
    };
    using execute_fp = void (*)(); //this is a feature to be added later
    execute_fp onclick; //this is a feature to be added later
};
