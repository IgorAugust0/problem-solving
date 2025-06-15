# Lê o número de casos de teste
t = int(input())

# Processa cada caso de teste
for _ in range(t):
    # Lê os três números como inteiros
    a, b, c = map(int, input().split())
    
    # Verifica se algum número é a soma dos outros dois
    # Testa todas as possibilidades: a+b=c, b+c=a, a+c=b
    if a + b == c or b + c == a or a + c == b:
        print("YES")
    else:
        print("NO")