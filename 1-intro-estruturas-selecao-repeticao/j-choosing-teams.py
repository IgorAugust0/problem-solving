def main():
    # Lê os valores de entrada
    n, k = map(int, input().split())

    # Lista para armazenar quantas vezes cada pessoa já participou
    participacoes = list(map(int, input().split()))

    # Conta quantas pessoas podem participar k vezes ainda
    pessoas_validas = sum(1 for participacao in participacoes if 5 - participacao >= k)

    # Calcula o número máximo de times possíveis (cada time precisa de 3 pessoas)
    max_times = pessoas_validas // 3

    print(max_times)


if __name__ == "__main__":
    main()
