"""


"""

import random

def gerador():
    try:
        arq = open(r"C:\Users\nicol\Desktop\Antivirus\Ativação\chaves_geradas.txt", "a")
        for n in range(20):
            x = random.randint(1000, 9999)
            y = random.randint(1000, 9999)
            z = random.randint(1000, 9999)
            id = n + 1
            arq.write("{}: {}-{}-{}\n".format(id, x, y, z))

        print("Chaves geradas com sucesso.")
        arq.close()
    except:
        print("Não foi possível abrir o arquivo.")

gerador()



