class Calulator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int mul(int a, int b) {
        return a * b;
    }
    
    int div(int a, int b) {
        return a / b;
    }
};

int **differential(int **polynomial, int highest_term) {
    int **diff_polynomial = new int*[highest_term - 1];

    for (int i = 0; i < highest_term - 1; i++) {
        diff_polynomial[i] = new int[2];
        diff_polynomial[i][0] = polynomial[i][0] * polynomial[i][1];
        diff_polynomial[i][1] = polynomial[i][1] - 1;
    }

    return diff_polynomial;
}

int main() {
    Calulator cal;
    int a = cal.add(3, 4);
    int s = cal.sub(3, 4);
    int m = cal.mul(3, 4);
    int d = cal.div(3, 4);
}