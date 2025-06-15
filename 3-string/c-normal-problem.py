def visualizarPorDentro(s: str) -> str:
    # Inverte a string
    s = s[::-1]
    
    # Troca p por q e vice-versa
    # Em Python, strings são imutáveis, então vamos criar uma nova string
    resultado = ""
    for c in s:
        if c == 'p':
            resultado += 'q'
        elif c == 'q':
            resultado += 'p'
        else:  # w permanece w
            resultado += c
            
    return resultado

def main():
    # Lê o número de casos de teste
    t = int(input())
    
    # Processa cada caso de teste
    for _ in range(t):
        s = input()
        print(visualizarPorDentro(s))

if __name__ == "__main__":
    main()