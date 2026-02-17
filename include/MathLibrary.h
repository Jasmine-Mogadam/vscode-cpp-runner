
// supports 7 mathematical operations
void Add(int a, int b, void (*callback)(int));
void Multiply(int a, int b, void (*callback)(int));
void Subtract(int a, int b, void (*callback)(int));
void Divide(int a, int b, void (*callback)(int));
void Modulus(int a, int b, void (*callback)(int));
void Greater(int a, int b, void (*callback)(int));
void Less(int a, int b, void (*callback)(int));