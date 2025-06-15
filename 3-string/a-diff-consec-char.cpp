    #include <iostream>
    #include <string>
    using namespace std;

    // Funcao para contar o numero minimo de operacoes necessarias
    int contarOperacoes(const string& s) {
        int operacoes = 0;
        int n = s.length();

        // Verifica cada par de caracteres consecutivos
        for (int i = 0; i < n - 1; i++) {
            // Se encontrar dois caracteres iguais consecutivos,
            // precisamos inserir um caractere entre eles
            if (s[i] == s[i + 1]) {
                operacoes++;
            }
        }

        return operacoes;
    }

    int main() {
        int T;
        cin >> T;

        while (T--) {
            int N;
            string S;

            cin >> N;
            cin >> S;

            cout << contarOperacoes(S) << endl;
        }

        return 0;
    }
