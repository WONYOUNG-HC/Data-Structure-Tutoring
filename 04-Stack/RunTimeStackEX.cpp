void foo(int f);
void bar(int b);

int main() {
    int x = 0;
    foo(x);
}

void foo(int f) {
    int y = f;
    bar(f);
}

void bar(int b) {
    int z = b;
}